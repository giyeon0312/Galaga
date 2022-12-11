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
	m_sActor = "˚";
	m_nActorColor = 0xf;

	// 초기 위치
	m_tPos.x = x;
	m_tPos.y = y;

	return true;
}

void CPBullet::Update()
{
	// 위로만 올라가면 될 듯.
	m_tPos.y -= 1;
}
