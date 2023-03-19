#pragma once
#include <iostream>

class LevelManager
{
public:
	int GetCurrentLevelIndex();

	void ChangeLevel(int index);
};