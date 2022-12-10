#pragma once
#include "Enemy.h"


class CEnemyYellow :
   public CEnemy
{
public:
    CEnemyYellow();
    CEnemyYellow(int x, int y, bool direction = false);
    virtual ~CEnemyYellow();

public:
    bool Init();
    bool Init(int x, int y,int direction = 0);
    virtual void Update();

private:
    bool m_bDirection; // 0: 우측하단, 1: 좌측하단
};

