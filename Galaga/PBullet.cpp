#include "PBullet.h"

CPBullet::CPBullet()
{
	Init();
}

CPBullet::CPBullet(int x, int y)
{
	Init(x, y);
}

CPBullet::~CPBullet()
{
}

bool CPBullet::Init()
{
	return true;
}

bool CPBullet::Init(int x, int y)
{
	m_sActor = "��";
	m_nActorColor = 0xf;

	// �ʱ� ��ġ
	m_tPos.x = x;
	m_tPos.y = y;

	return true;
}

void CPBullet::Update()
{
	// ���θ� �ö󰡸� �� ��.
	m_tPos.y -= 1;
}
