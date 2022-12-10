#pragma once
#include "Enemy.h"


class CEnemyYellow :
   public CEnemy
{
public:
    CEnemyYellow();
    CEnemyYellow(int x, int y);
    virtual ~CEnemyYellow();

public:
    virtual bool Init();
    virtual bool Init(int x, int y);
    virtual void Update();
};

