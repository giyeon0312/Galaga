#pragma once
#include "Actor.h"

class CEnemy:
	public CActor
{

public:
    CEnemy();
    virtual ~CEnemy();

public:
    virtual bool Init();
    virtual bool Init(int x, int y);
    virtual void Update();

protected:
    vector<POSITION> m_aPattern;
    int m_nPatternSize;
    int m_nCurrentIdx;
};

