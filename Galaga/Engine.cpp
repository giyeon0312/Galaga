#include "Engine.h"
#include "StageManager.h"

CEngine* CEngine::_instance = nullptr;

CEngine::CEngine()
	:m_bLoop(true)
{
	srand(time(0));
}

CEngine::~CEngine()
{
	CStageManager::GetInstance()->DestroyInstance();
}

bool CEngine::Init()
{
	if (!CStageManager::GetInstance()->Init())
		return false;

	return true;
}

void CEngine::Run()
{
	while (m_bLoop)
	{
		system("cls");

		CStageManager::GetInstance()->Run();

		Sleep(5);

	}
}

void CEngine::SetConsolePos(int x, int y)
{
}

