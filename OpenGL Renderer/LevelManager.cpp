#include "LevelManager.h"

int currentLevelIndex;

void LevelManager::ChangeLevel(int index)
{
	currentLevelIndex = index; 
}

int LevelManager::GetCurrentLevelIndex()
{
	return currentLevelIndex;
}