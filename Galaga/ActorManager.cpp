#include "ActorManager.h"

CActorManager* CActorManager::_instance = nullptr;

CActorManager::CActorManager()
{
}

CActorManager::~CActorManager()
{
}

void CActorManager::Init()
{
	CreateActor(ACTOR_TYPE::ACTOR_PLAYER);
	CreateActor(ACTOR_TYPE::ACTOR_ENEMY_RED, 20, 5);
	CreateActor(ACTOR_TYPE::ACTOR_ENEMY_BLUE, 10, 4);
	CreateActor(ACTOR_ENEMY_YELLOW, 15, 2, false);
	CreateActor(ACTOR_ENEMY_YELLOW, 30, 2, true);
}

void CActorManager::Update()
{
	int cnt = m_pActors.size();

	for (vector<CActor*>::iterator iter = m_pActors.begin(); iter != m_pActors.end();)
	{
		CActor* actor = *iter;
		actor->Update();

		// 테두리 밖으로 나가면 삭제하기.
		POSITION pos = actor->GetPosition();
		if (pos.y <= 0 || pos.y >= STAGE_HEIGHT || pos.x <= 0 || pos.x >= STAGE_WIDTH)
		{
			// 벡터에서 지우고
			SAFE_DELETE(actor);
			iter = m_pActors.erase(iter); // 다음 iterator 반환한다.
			// 삭제 됐을 경우 다음 iter를 여기서 받아가기 때문에 iter++를 하면 다음을 건너뛰게 된다.
		}
		else
			iter++;
	}

	// 충돌 처리.
	/*
	* 이중 for문 돌면서 positon이 겹치면 
	*/
	
}

void CActorManager::Render()
{
	int cnt = m_pActors.size();
	for (int i = 0; i < cnt; i++)
	{
		CActor* actor = m_pActors[i];
		actor->DrawActor();
	}
}

void CActorManager::CreateActor(ACTOR_TYPE eType, int x, int y, bool direction)
{
	CActor* pActor = NULL;

	switch (eType)
	{
	case ACTOR_PLAYER:
		pActor = new CPlayer();
		break;
	case ACTOR_ENEMY_RED:
		pActor = new CEnemyRed(x, y);
		break;
	case ACTOR_ENEMY_BLUE:
		pActor = new CEnemyBlue(x, y);
		break;
	case ACTOR_ENEMY_YELLOW:
		pActor = new CEnemyYellow(x, y, direction);
		break;
	case ACTOR_EBULLET:
		break;
	case ACTOR_PBULLET:
		pActor = new CPBullet(x, y);
		break;
	}

	//if (!pActor->Init())
	//{
	//	SAFE_DELETE(pActor);
	//}

	m_pActors.push_back(pActor);
}


