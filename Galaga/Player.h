#pragma once
#include "Actor.h"

class CPlayer :
    public CActor
{
public:
    virtual bool Init();
    virtual void DrawActor();
};

