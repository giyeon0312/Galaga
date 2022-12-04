#include "Enemy.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Init()
{
	return false;
}

bool CEnemy::Init(int x, int y)
{
	return false;
}

void CEnemy::Update()
{
	if (m_nCurrentIdx < m_nPatternSize) 
		m_nCurrentIdx++;
	else 
		m_nPatternSize = 0;

	m_tPos.x += m_aPattern[m_nCurrentIdx].x;
	m_tPos.y += m_aPattern[m_nCurrentIdx].y;
}
