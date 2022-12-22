#include "Stage.h"
#include "Engine.h"

CStage::CStage()
{
	m_nSpeed = 10;
}

CStage::~CStage()
{
}

int CStage::GetStageState(int x, int y)
{
	if (y <= 0 || y >= STAGE_HEIGHT)
		return -1;
	if (x <= 0 || x >= STAGE_WIDTH)
		return -1;
	return m_Stage[y][x];
}

bool CStage::Init()
{
	for (int i = 0; i < STAGE_HEIGHT; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH; ++j)
		{
			m_Stage[i][j] = 0;
		}
	}
	return true;
}


void CStage::Render()
{
	for (int i = 0; i < STAGE_HEIGHT + 2; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (i == 0 || j == 0)
				cout << "бс";
			else if (i == STAGE_HEIGHT + 1)
				cout << "бс";
			else if (j == STAGE_WIDTH + 1)
				cout << "бс";
			else
				cout << "  ";

			/*int actor = m_Stage[i][j];
			switch (actor)
			{
			case ACTOR_PLAYER:
				cout << "Ї╚";
				break;
			case ACTOR_PBULLET:
				cout << "вк";
				break;
			case ACTOR_ENEMY1:
				cout << ")  (";
				break;
			case ACTOR_ENEMY2:
				cout << "б│б▓";
				break;
			case ACTOR_ENEMY3:
				cout << "б╜б╝";
				break;
			case ACTOR_EBULLET:
				cout << "*";
				break;
			default:
				cout << "  ";
				break;
			}*/
		}
		cout << '\n';
	}
	
	for (int i = 0; i < 4; i++)
	{
		CEngine::GetInstance()->SetConsolePos(STAGE_WIDTH + 8,i);
		cout << "бс";
	}
	for (int i = STAGE_WIDTH + 1; i <= STAGE_WIDTH + 8; i++)
	{
		CEngine::GetInstance()->SetConsolePos(i, 4);
		cout << "бс";
	}
}
