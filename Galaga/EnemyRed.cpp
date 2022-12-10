#include "EnemyRed.h"

CEnemyRed::CEnemyRed()
{
}

CEnemyRed::CEnemyRed(int x , int y)
{
	Init(x, y);
}

CEnemyRed::~CEnemyRed()
{
}

bool CEnemyRed::Init()
{
	m_sActor = "][";
	m_nActorColor = 0xC;

	// 초기 위치
	m_tPos.x = 20;
	m_tPos.y = 5;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	m_aPattern.push_back(POSITION(2, 0));
	m_aPattern.push_back(POSITION(2, 0));
	m_aPattern.push_back(POSITION(-2, 0));
	m_aPattern.push_back(POSITION(-2, 0));


	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;

	return true;
}

bool CEnemyRed::Init(int x, int y)
{
	m_sActor = "][";
	m_nActorColor = 0xC;

	// 초기 위치
	m_tPos.x = x;
	m_tPos.y = y;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	/*m_aPattern.push_back(POSITION(x + 2, y));
	m_aPattern.push_back(POSITION(x + 2, y));
	m_aPattern.push_back(POSITION(x - 2, y));
	m_aPattern.push_back(POSITION(x - 2, y));*/
	m_aPattern.push_back(POSITION(2, 0));
	m_aPattern.push_back(POSITION(2, 0));
	m_aPattern.push_back(POSITION(-2, 0));
	m_aPattern.push_back(POSITION(-2, 0));

	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;
	return true;
}

void CEnemyRed::Update()
{
	if (m_nCurrentIdx < m_nPatternSize - 1)
		m_nCurrentIdx++;
	else
		m_nCurrentIdx = 0;

	m_tPos.x += m_aPattern[m_nCurrentIdx].x;
	m_tPos.y += m_aPattern[m_nCurrentIdx].y;
}
