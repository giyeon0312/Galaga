#include "ActorManager.h"

CActorManager* CActorManager::_instance = nullptr;

CActorManager::CActorManager()
{
	m_pActors.push_back(new CPlayer());
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
