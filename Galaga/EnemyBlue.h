#pragma once
#include "Enemy.h"


class CEnemyBlue:
    public CEnemy
{
public:
    CEnemyBlue();
    CEnemyBlue(int x, int y);
    virtual ~CEnemyBlue();

public:
    virtual bool Init();
    virtual bool Init(int x, int y);
    virtual void Update();
};

