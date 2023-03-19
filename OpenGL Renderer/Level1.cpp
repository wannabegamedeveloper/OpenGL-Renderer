#include "Level1.h"

void Level1::Start()
{
	gridTex = new Texture("grid.jpg", GL_RGB);

	unlitTex = new Shader("unlit_textured.shader");
	unlitTex->AttachTextureToSlot(*gridTex, 0);

	levelStarted = true;
}

void Level1::Update()
{
	if (!levelStarted)
	{
		Start();
		return;
	}

	camera.setCamera(90.0f, 800, 800, 0.01f, 100.0f, *unlitTex);
	camera.SetPosition(glm::vec3(0.0f, 0.0f, 1.0f));

	camera.SetBackgroundColor(0.4f, 0.2f, 0.9f);

	platform.draw(*unlitTex, glm::vec3(0.0f, -0.5f, 0.0f));
	platform.SetRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	platform.SetScale(glm::vec3(0.5f, 0.1f, 10.0f));
}

void Level1::ClearData()
{
	platform.clearData();
	unlitTex->Delete();
}