#pragma once

#include "StdAfx.h"
#include "Actor.h"
#include "Player.h"
#include "EnemyRed.h"
#include "EnemyBlue.h"
#include "EnemyYellow.h"
#include "PBullet.h"
#include "EBullet.h"

class CActorManager
	:public Singleton<CActorManager>
{
public:
	CActorManager();
	~CActorManager();

private:
	vector<CActor*> m_pActors;
	vector<CEBullet*> m_pEBullets;

public:
	void Init();
	void Update();
	void Render();
	void CreateActor(ACTOR_TYPE eType, int x = 0, int y = 0, bool direction = false);
	void CreateEBullet(int x, int y);
};

