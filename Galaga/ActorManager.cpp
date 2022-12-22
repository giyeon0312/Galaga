#include "ActorManager.h"

CActorManager* CActorManager::_instance = nullptr;

CActorManager::CActorManager()
{
}

CActorManager::~CActorManager()
{
}

void CActorManager::Init()
{
	m_pPlayer = new CPlayer();
	CreateActor(ACTOR_TYPE::ACTOR_ENEMY_RED, 20, 5);
	CreateActor(ACTOR_TYPE::ACTOR_ENEMY_BLUE, 10, 4);
	CreateActor(ACTOR_ENEMY_YELLOW, 15, 2, false);
	CreateActor(ACTOR_ENEMY_YELLOW, 30, 2, true);
}

void CActorManager::Update()
{
	m_pPlayer->Update();

	int cnt = m_pEnemys.size();

	for (vector<CEnemy*>::iterator iter = m_pEnemys.begin(); iter != m_pEnemys.end();)
	{
		CActor* actor = *iter;
		actor->Update();

		// �׵θ� ������ ������ �����ϱ�.
		POSITION pos = actor->GetPosition();
		if (pos.y <= 0 || pos.y >= STAGE_HEIGHT || pos.x <= 0 || pos.x >= STAGE_WIDTH)
		{
			// ���Ϳ��� �����
			SAFE_DELETE(actor);
			iter = m_pEnemys.erase(iter); // ���� iterator ��ȯ�Ѵ�.
			// ���� ���� ��� ���� iter�� ���⼭ �޾ư��� ������ iter++�� �ϸ� ������ �ǳʶٰ� �ȴ�.
		}
		else
			iter++;
	}

	for (vector<CEBullet*>::iterator iter = m_pEBullets.begin(); iter != m_pEBullets.end();)
	{
		CEBullet* actor = *iter;
		actor->Update();

		// �׵θ� ������ ������ �����ϱ�.
		POSITION pos = actor->GetPosition();
		if (pos.y <= 0 || pos.y >= STAGE_HEIGHT || pos.x <= 0 || pos.x >= STAGE_WIDTH)
		{
			// ���Ϳ��� �����
			SAFE_DELETE(actor);
			iter = m_pEBullets.erase(iter); // ���� iterator ��ȯ�Ѵ�.
			// ���� ���� ��� ���� iter�� ���⼭ �޾ư��� ������ iter++�� �ϸ� ������ �ǳʶٰ� �ȴ�.
		}
		else
			iter++;
	}

	for (vector<CPBullet*>::iterator iter = m_pPBullets.begin(); iter != m_pPBullets.end();)
	{
		CPBullet* actor = *iter;
		actor->Update();

		// �׵θ� ������ ������ �����ϱ�.
		POSITION pos = actor->GetPosition();
		if (pos.y <= 0 || pos.y >= STAGE_HEIGHT || pos.x <= 0 || pos.x >= STAGE_WIDTH)
		{
			// ���Ϳ��� �����
			SAFE_DELETE(actor);
			iter = m_pPBullets.erase(iter); // ���� iterator ��ȯ�Ѵ�.
			// ���� ���� ��� ���� iter�� ���⼭ �޾ư��� ������ iter++�� �ϸ� ������ �ǳʶٰ� �ȴ�.
		}
		else
			iter++;
	}

	// �浹 ó��.
	// ���ʹ� �浹 ó��.
	for (vector<CPBullet*>::iterator pBulletIter = m_pPBullets.begin(); pBulletIter != m_pPBullets.end(); pBulletIter++)
	{
		CPBullet* pBullet = *pBulletIter;
		POSITION bulletPos = pBullet->GetPosition();
		for (vector<CEnemy*>::iterator enemyIter = m_pEnemys.begin(); enemyIter != m_pEnemys.end();)
		{
			CEnemy* pEnemy = *enemyIter;
			POSITION enemyPos = pEnemy->GetPosition();
			if ((bulletPos.x == enemyPos.x) && (bulletPos.y == enemyPos.y))
			{
				// ���Ϳ��� �����
				SAFE_DELETE(pEnemy);
				enemyIter = m_pEnemys.erase(enemyIter); // ���� iterator ��ȯ�Ѵ�.
			}
			else
				enemyIter++;
		}
	}
	
	// ���ʹ� �浹 üũ.
	for (vector<CPBullet*>::iterator pBulletIter = m_pPBullets.begin(); pBulletIter != m_pPBullets.end(); pBulletIter++)
	{
		CPBullet* pBullet = *pBulletIter;
		POSITION bulletPos = pBullet->GetPosition();
		for (vector<CEnemy*>::iterator enemyIter = m_pEnemys.begin(); enemyIter != m_pEnemys.end();)
		{
			CEnemy* pEnemy = *enemyIter;
			POSITION enemyPos = pEnemy->GetPosition();
			if ((bulletPos.x == enemyPos.x) && (bulletPos.y == enemyPos.y))
			{
				// ���Ϳ��� �����
				SAFE_DELETE(pEnemy);
				enemyIter = m_pEnemys.erase(enemyIter); // ���� iterator ��ȯ�Ѵ�.
			}
			else
				enemyIter++;
		}
	}

	// �÷��̾� �浹 üũ.
	for (vector<CEBullet*>::iterator eBulletIter = m_pEBullets.begin(); eBulletIter != m_pEBullets.end(); eBulletIter++)
	{
		CEBullet* eBullet = *eBulletIter;
		POSITION bulletPos = eBullet->GetPosition();
		POSITION playerPos = m_pPlayer->GetPosition();
		if ((bulletPos.x == playerPos.x) && (bulletPos.y == playerPos.y))
		{
			m_pPlayer->Die();
			if(m_pPlayer->GetHeartCnt() == 0)
				CEngine::GetInstance()->End();
		}
	}

}

void CActorManager::Render()
{
	m_pPlayer->DrawActor();

	int cnt = m_pEnemys.size();
	for (int i = 0; i < cnt; i++)
	{
		CActor* actor = m_pEnemys[i];
		actor->DrawActor();
	}

	cnt = m_pEBullets.size();
	for (int i = 0; i < cnt; i++)
	{
		CActor* bullet = m_pEBullets[i];
		bullet->DrawActor();
	}

	cnt = m_pPBullets.size();
	for (int i = 0; i < cnt; i++)
	{
		CActor* bullet = m_pPBullets[i];
		bullet->DrawActor();
	}

	// �÷��̾� ��� �׸���.
	for (int i = 0; i < m_pPlayer->GetHeartCnt(); i++)
	{
		CEngine::GetInstance()->SetConsolePos(STAGE_WIDTH + 1 +  i, 2);
		CEngine::GetInstance()->SetConsoleColor(13);  // pink
		cout << "��";
		CEngine::GetInstance()->SetConsoleColor(0xF); // �⺻ ForeColor ���.
	}

}

void CActorManager::CreateActor(ACTOR_TYPE eType, int x, int y, bool direction)
{
	//CActor* pActor = NULL;
	CEnemy* pActor = NULL;

	switch (eType)
	{
	//case ACTOR_PLAYER:
	//	pActor = new CPlayer();
	//	break;
	case ACTOR_ENEMY_RED:
		pActor = new CEnemyRed(x, y);
		break;
	case ACTOR_ENEMY_BLUE:
		pActor = new CEnemyBlue(x, y);
		break;
	case ACTOR_ENEMY_YELLOW:
		pActor = new CEnemyYellow(x, y, direction);
		break;
	//case ACTOR_EBULLET:
	//	pActor = new CEBullet(x, y);
	//	break;
	//case ACTOR_PBULLET:
	//	pActor = new CPBullet(x, y);
	//	break;
	}

	//if (!pActor->Init())
	//{
	//	SAFE_DELETE(pActor);
	//}

	m_pEnemys.push_back(pActor);
}

void CActorManager::CreateEBullet(int x, int y)
{
	m_pEBullets.push_back(new CEBullet(x, y));
}

void CActorManager::CreatePBullet(int x, int y)
{
	m_pPBullets.push_back(new CPBullet(x, y));
}


