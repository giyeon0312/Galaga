#include "EnemyYellow.h"

CEnemyYellow::CEnemyYellow()
{
	Init();
}

CEnemyYellow::CEnemyYellow(int x, int y, bool direction)
{
	Init(x,y, direction);
}

CEnemyYellow::~CEnemyYellow()
{
}

bool CEnemyYellow::Init()
{
	m_sActor = "}{";
	m_nActorColor = 9;

	// 초기 위치
	m_tPos.x = 10;
	m_tPos.y = 4;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));

	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;

	return true;
}

bool CEnemyYellow::Init(int x, int y, int direction) 
{
	m_sActor = "}{";
	m_nActorColor = 14;
	m_bDirection = direction;

	// 초기 위치
	m_tPos.x = x;
	m_tPos.y = y;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));

	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;
	return true;
}

void CEnemyYellow::Update()
{
	if (m_nCurrentIdx < m_nPatternSize - 1)
		m_nCurrentIdx++;
	else
		m_nCurrentIdx = 0;

	if (!m_bDirection)
	{
		m_tPos.x += m_aPattern[m_nCurrentIdx].x;
		m_tPos.y += m_aPattern[m_nCurrentIdx].y;
	}
	else
	{
		m_tPos.x -= m_aPattern[m_nCurrentIdx].x;
		m_tPos.y += m_aPattern[m_nCurrentIdx].y;
	}
}
