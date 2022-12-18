#include "Player.h"
#include "StageManager.h"
#include "ActorManager.h"
#include "Stage.h"

#include <Windows.h>

CPlayer::CPlayer()
{
	Init();
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_sActor = "♣";
	m_nActorColor = 0xA;

	// 초기 위치
	m_tPos.x = 16;
	m_tPos.y = 24; 				

	return true;
}

void CPlayer::Update()
{
	if (GetAsyncKeyState('A') & 0x8000) // 0x8000은 이전에 누른 적이 없고 호출 시점에서 눌린 상태
	{
		MoveLeft();
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		MoveRight();
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		MoveUp();
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		MoveDown();
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Shoot();
	}

}


void CPlayer::MoveDown()
{
	// CStageManager에서 GetCurrentStage()로 m_Stage의 정보 가져와 벽이거나 다른 actor정보 있는지 확인 필요.
	CStage* pCurStage = CStageManager::GetInstance()->GetCurrentStage();
	if (pCurStage->GetStageState(m_tPos.x, m_tPos.y + 1) != 0)
		return;
	m_tPos.y += 1;
}

void CPlayer::MoveUp()
{
	CStage* pCurStage = CStageManager::GetInstance()->GetCurrentStage();
	if (pCurStage->GetStageState(m_tPos.x, m_tPos.y - 1) != 0)
		return;
	m_tPos.y -= 1;
}

void CPlayer::MoveRight()
{
	CStage* pCurStage = CStageManager::GetInstance()->GetCurrentStage();
	if (pCurStage->GetStageState(m_tPos.x + 1, m_tPos.y) != 0)
		return;
	m_tPos.x += 1;
}

void CPlayer::MoveLeft()
{
	CStage* pCurStage = CStageManager::GetInstance()->GetCurrentStage();
	if (pCurStage->GetStageState(m_tPos.x - 1, m_tPos.y) != 0)
		return;
	m_tPos.x -= 1;
}

void CPlayer::Shoot()
{
	CActorManager::GetInstance()->CreatePBullet(m_tPos.x, m_tPos.y);
}
