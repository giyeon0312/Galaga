#pragma once
#include "Actor.h"

class CEBullet :
    public CActor
{
public:
    CEBullet();
    CEBullet(int x, int y);
    virtual ~CEBullet();

public:
    bool Init();
    bool Init(int x, int y);
    virtual void Update();
};