#include "Actor.h"

CActor::CActor()
{
}

CActor::~CActor()
{
}

bool CActor::Init()
{
	// 액터 모양
	//for (int i = 0; i < ACTOR_SIZE; ++i)
	//	m_sActor[i] = '\0';

	m_sActor = "\0";
	//m_nActorSize = strlen(m_sActor.c_str());
	m_nActorSize = m_sActor.length();


	m_tPos.x = 0;
	m_tPos.y = 3; 				// 현재 위치

	return true;
}

void CActor::DrawActor()
{
}

void CActor::MoveDown()
{
}

void CActor::MoveUp()
{
}

void CActor::MoveRight()
{
}

void CActor::MovdLeft()
{
}
