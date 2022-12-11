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

		// �׵θ� ������ ������ �����ϱ�.
		POSITION pos = actor->GetPosition();
		if (pos.y <= 0 || pos.y >= STAGE_HEIGHT || pos.x <= 0 || pos.x >= STAGE_WIDTH)
		{
			// ���Ϳ��� �����
			SAFE_DELETE(actor);
			iter = m_pActors.erase(iter); // ���� iterator ��ȯ�Ѵ�.
			// ���� ���� ��� ���� iter�� ���⼭ �޾ư��� ������ iter++�� �ϸ� ������ �ǳʶٰ� �ȴ�.
		}
		else
			iter++;
	}

	// �浹 ó��.
	/*
	* ���� for�� ���鼭 positon�� ��ġ�� 
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


