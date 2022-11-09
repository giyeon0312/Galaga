#include "Stage.h"

CStage::CStage()
{
	m_nSpeed = 10;
}

CStage::~CStage()
{
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
				cout << "��";
			else if (i == STAGE_HEIGHT + 1)
				cout << "��";
			else if (j == STAGE_WIDTH + 1)
				cout << "��";
			else
				cout << "  ";
			/*int actor = m_Stage[i][j];
			switch (actor)
			{
			case ACTOR_PLAYER:
				cout << "��";
				break;
			case ACTOR_PBULLET:
				cout << "��";
				break;
			case ACTOR_ENEMY1:
				cout << ")  (";
				break;
			case ACTOR_ENEMY2:
				cout << "����";
				break;
			case ACTOR_ENEMY3:
				cout << "����";
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
