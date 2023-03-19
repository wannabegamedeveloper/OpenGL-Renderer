#include "MainMenu.h"

void MainMenu::Start()
{
	
}

void MainMenu::Update()
{
	if (inputManager.GetKeyDown(GLFW_KEY_SPACE))
	{
		levelManager.ChangeLevel(1);
	}
}

void MainMenu::ClearData()
{

}
