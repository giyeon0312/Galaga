#include "StageManager.h"
#include "Stage.h"

CStageManager* CStageManager::_instance = nullptr;

CStageManager::CStageManager()
{
}

CStageManager::~CStageManager()
{
}

bool CStageManager::Init()
{
	// 기본 스테이지 생성
	m_pCurStage = new CStage();
	if(!m_pCurStage->Init())
		return false;
	
	return true;
}

void CStageManager::Run()
{
	m_pCurStage->Render();
}
