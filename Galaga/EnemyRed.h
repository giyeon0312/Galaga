#pragma once
#include "Enemy.h"

class CEnemyRed :
	public CEnemy
{
public:
    CEnemyRed();
    virtual ~CEnemyRed();

public:
    virtual bool Init();
    virtual bool Init(int x, int y);
    virtual void Update();
};

