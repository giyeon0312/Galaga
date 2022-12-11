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
    bool Init();
    bool Init(int x, int y);
    virtual void Update();

private:
    void Shoot();
};

