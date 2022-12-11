#include "EnemyBlue.h"
#include "ActorManager.h"

CEnemyBlue::CEnemyBlue()
{
	Init();
}

CEnemyBlue::CEnemyBlue(int x , int y)
{
	Init(x,y);
}

CEnemyBlue::~CEnemyBlue()
{
}

bool CEnemyBlue::Init()
{
	m_sActor = ")(";
	m_nActorColor = 9;

	// 초기 위치
	m_tPos.x = 10;
	m_tPos.y = 4;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	m_aPattern.push_back(POSITION(0, 1));
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(-1, -1));
	m_aPattern.push_back(POSITION(1, -1));
	m_aPattern.push_back(POSITION(0, -1));


	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;

	return true;
}

bool CEnemyBlue::Init(int x, int y)
{
	m_sActor = ")(";
	m_nActorColor = 9;

	// 초기 위치
	m_tPos.x = x;
	m_tPos.y = y;

	// 움직일 패턴 입력. ( 현재 위치에 더해서 사용한다.)
	m_aPattern.push_back(POSITION(0, 1));
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(-1, -1));
	m_aPattern.push_back(POSITION(1, -1));
	m_aPattern.push_back(POSITION(0, -1));

	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;
	return true;
}

void CEnemyBlue::Update()
{
	if (m_nCurrentIdx < m_nPatternSize - 1)
		m_nCurrentIdx++;
	else
		m_nCurrentIdx = 0;

	m_tPos.x += m_aPattern[m_nCurrentIdx].x;
	m_tPos.y += m_aPattern[m_nCurrentIdx].y;

	if (m_nCurrentIdx == m_nPatternSize / 2)
		Shoot();
}

void CEnemyBlue::Shoot()
{
	CActorManager::GetInstance()->CreateEBullet( m_tPos.x, m_tPos.y);
}
