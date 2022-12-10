#pragma once

#include "StdAfx.h"

class CActor
{
public:
	CActor();
	virtual ~CActor();

protected:
	//char m_sActor[ACTOR_SIZE];		// ���� ���
	string		m_sActor;
	int			m_nActorColor;		// 255�÷�.
	int			m_nActorSize;
	POSITION	m_tPos;				// ���� ��ġ

public:
	void SetPosition(int x, int y)
	{
		//m_tPos = POSITION(x, y);
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	POSITION GetPosition()	const
	{
		return m_tPos;
	}

public:
	bool Init();
	virtual void Update() = 0;
	//virtual void DrawActor();
	void DrawActor();
};

