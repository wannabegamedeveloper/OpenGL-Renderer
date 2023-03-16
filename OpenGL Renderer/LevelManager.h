#pragma once
#include "Level1.h"

class LevelManager
{
private:
	int currentLevelIndex;
	Level1 level1;

public:
	int GetCurrentLevelIndex();
	void ChangeLevel(int levelIndex);

	void Start();
	void Update();
	void ClearData();
};