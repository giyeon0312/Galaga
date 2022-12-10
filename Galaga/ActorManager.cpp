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
	for (int i = 0; i < cnt; i++)
	{
		CActor* actor = m_pActors[i];
		actor->Update();
	}
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
		break;
	}

	//if (!pActor->Init())
	//{
	//	SAFE_DELETE(pActor);
	//}

	m_pActors.push_back(pActor);
}


