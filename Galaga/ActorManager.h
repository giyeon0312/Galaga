#pragma once

#include "StdAfx.h"
#include "Actor.h"
#include "Player.h"
#include <vector>

class CActorManager
	:public Singleton<CActorManager>
{
public:
	CActorManager();
	~CActorManager();

private:
	vector<CActor*> m_pActors;

public:
	void Update();
	void Render();
	void CreateActor(ACTOR_TYPE eType);
};

