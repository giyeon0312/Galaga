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

private:
    void MoveDown();
    void MoveUp();
    void MoveRight();
    void MoveLeft();
    void Shoot();

private:
    int m_nHeart;

public:
    int GetHeartCnt();
    void SetHeartCnt(int heart);
    void Die();
};

