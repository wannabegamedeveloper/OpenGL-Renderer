#include "LevelManager.h"

int LevelManager::GetCurrentLevelIndex()
{
	return currentLevelIndex;
}

void LevelManager::ChangeLevel(int levelIndex)
{
	currentLevelIndex = levelIndex;

	Start();
}
void LevelManager::Start()
{
	if (currentLevelIndex == 1)
		level1.Start();
}

void LevelManager::Update()
{
	if (currentLevelIndex == 1)
		level1.Update();
}

void LevelManager::ClearData()
{
	if (currentLevelIndex == 1)
		level1.ClearData();
}