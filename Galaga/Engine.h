#pragma once

#include "StdAfx.h"
#include <Windows.h>

class CEngine
	: public Singleton<CEngine>
{
public:
	CEngine();
	~CEngine();

private:
	HANDLE m_hConsole;
	bool m_bLoop;

public:
	bool Init();
	void Run();
	void ShowTitle();
	void SetConsolePos(int x, int y);
	void SetConsoleColor(int color);
	void End();

};

