#include "EBullet.h"

CEBullet::CEBullet()
{
	Init();
}

CEBullet::CEBullet(int x, int y)
{
	Init(x, y);
}

CEBullet::~CEBullet()
{
}

bool CEBullet::Init()
{
	return true;
}

bool CEBullet::Init(int x, int y)
{
	m_sActor = "*";
	m_nActorColor = 9;

	// �ʱ� ��ġ
	m_tPos.x = x;
	m_tPos.y = y;

	return true;
}

void CEBullet::Update()
{
	// �Ʒ��� ���.
	// �Ŀ� Ÿ�� �����ϴ� ������ �ٲٱ�. 
	m_tPos.y += 1;
}
