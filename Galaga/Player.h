#pragma once
#include "Actor.h"

class CPlayer :
    public CActor
{
public:
    CPlayer();
    virtual ~CPlayer();

public:
    virtual bool Init();
    virtual void Update();

public:
    void MoveDown();
    void MoveUp();
    void MoveRight();
    void MoveLeft();
};

