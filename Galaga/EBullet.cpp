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

	// 초기 위치
	m_tPos.x = x;
	m_tPos.y = y;

	return true;
}

void CEBullet::Update()
{
	// 아래로 쏜다.
	// 후에 타겟 지정하는 것으로 바꾸기. 
	m_tPos.y += 1;
}
