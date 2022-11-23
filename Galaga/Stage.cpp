#include "Stage.h"

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
				cout << "¡á";
			else if (i == STAGE_HEIGHT + 1)
				cout << "¡á";
			else if (j == STAGE_WIDTH + 1)
				cout << "¡á";
			else
				cout << "  ";

			/*int actor = m_Stage[i][j];
			switch (actor)
			{
			case ACTOR_PLAYER:
				cout << "ôÈ";
				break;
			case ACTOR_PBULLET:
				cout << "¢ª";
				break;
			case ACTOR_ENEMY1:
				cout << ")  (";
				break;
			case ACTOR_ENEMY2:
				cout << "¡³¡²";
				break;
			case ACTOR_ENEMY3:
				cout << "¡½¡¼";
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
}
