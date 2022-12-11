#pragma once
#include "Actor.h"

class CPBullet:
    public CActor
{
public:
    CPBullet();
    CPBullet(int x, int y);
    virtual ~CPBullet();

public:
    bool Init();
    bool Init(int x, int y);
    virtual void Update();
};
