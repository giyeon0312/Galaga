#include "Engine.h"
#include "StageManager.h"
#include "ActorManager.h"

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
	// �ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	if (!CStageManager::GetInstance()->Init())
		return false;

	CActorManager::GetInstance()->CreateActor(ACTOR_TYPE::ACTOR_PLAYER);
	
	return true;
}

void CEngine::Run()
{
	while (m_bLoop)
	{
		system("cls");

		CActorManager::GetInstance()->Update();

		CStageManager::GetInstance()->Run();	// �������� ����
		CActorManager::GetInstance()->Render(); // ���� ����.

		Sleep(5);

	}
}

void CEngine::SetConsolePos(int x, int y)
{
	// �� ĭ�� 2byte�� ����ϹǷ�
	COORD	pos = { (x + 1) * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}

