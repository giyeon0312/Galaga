#include "ActorManager.h"

CActorManager* CActorManager::_instance = nullptr;

CActorManager::CActorManager()
{
}

CActorManager::~CActorManager()
{
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

void CActorManager::CreateActor(ACTOR_TYPE eType,int x = 0, int y = 0)
{
	CActor* pActor = NULL;
	
	switch(eType)
	{
		case ACTOR_PLAYER:
			pActor = new CPlayer();
			break;
		case ACTOR_PBULLET:
			break;
		case ACTOR_ENEMY_RED:
			pActor = new CEnemyRed();
			break;
		case ACTOR_ENEMY_BLUE:
			break;
		case ACTOR_ENEMY_YELLOW: 
			break;
		case ACTOR_EBULLET: 
			break;
	
	}

	if (!pActor->Init())
	{
		SAFE_DELETE(pActor);
	}

	m_pActors.push_back(pActor);
}
