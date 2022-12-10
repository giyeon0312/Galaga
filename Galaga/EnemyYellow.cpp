#include "EnemyYellow.h"

CEnemyYellow::CEnemyYellow()
{
	Init();
}

CEnemyYellow::CEnemyYellow(int x, int y)
{
	Init(x,y);
}

CEnemyYellow::~CEnemyYellow()
{
}

bool CEnemyYellow::Init()
{
	m_sActor = "}{";
	m_nActorColor = 9;

	// �ʱ� ��ġ
	m_tPos.x = 10;
	m_tPos.y = 4;

	// ������ ���� �Է�. ( ���� ��ġ�� ���ؼ� ����Ѵ�.)
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));
	m_aPattern.push_back(POSITION(-1, 1));
	m_aPattern.push_back(POSITION(1, 1));

	m_nPatternSize = m_aPattern.size();
	m_nCurrentIdx = 0;

	return true;
}

bool CEnemyYellow::Init(int x, int y)
{
	m_sActor = "}{";
	m_nActorColor = 14;

	// �ʱ� ��ġ
	m_tPos.x = x;
	m_tPos.y = y;

	// ������ ���� �Է�. ( ���� ��ġ�� ���ؼ� ����Ѵ�.)
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

	m_tPos.x += m_aPattern[m_nCurrentIdx].x;
	m_tPos.y += m_aPattern[m_nCurrentIdx].y;
}
