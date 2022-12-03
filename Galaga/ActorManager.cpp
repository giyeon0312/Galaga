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
		// CActor::Update를 virtual로 하기
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

void CActorManager::CreateActor(ACTOR_TYPE eType)
{
	CActor* pActor = NULL;
	
	switch(eType)
	{
		case ACTOR_PLAYER:
			pActor = new CPlayer();
			break;
		case ACTOR_PBULLET:
			break;
		case ACTOR_ENEMY1:
			break;
		case ACTOR_ENEMY2:
			break;
		case ACTOR_ENEMY3: 
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
