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
	m_sActor = "��";
	m_nActorColor = 0xA;

	// �ʱ� ��ġ
	m_tPos.x = 16;
	m_tPos.y = 24; 				

	return true;
}

void CPlayer::Update()
{
	if (GetAsyncKeyState('A') & 0x8000) // 0x8000�� ������ ���� ���� ���� ȣ�� �������� ���� ����
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
	// CStageManager���� GetCurrentStage()�� m_Stage�� ���� ������ ���̰ų� �ٸ� actor���� �ִ��� Ȯ�� �ʿ�.
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
