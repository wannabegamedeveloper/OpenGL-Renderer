#include "Level1.h"

void Level1::Start()
{
	gridTex = new Texture("grid.jpg", GL_RGB);
	unlitTex = new Shader("unlit_textured.shader");

	containerTex = new Texture("circle.png", GL_RGBA);
	unlitColor = new Shader("unlit_color.shader");

	levelStarted = true;
}

void Level1::Update()
{
	if (!levelStarted)
	{
		Start();
		return;
	}

	time.CreateDeltaTime();

	positionZ -= speed * time.GetDeltaTime();

	camera.setCamera();
	camera.SetPosition(glm::vec3(0.0f, 1.5f, positionZ));
	camera.SetRotation(glm::vec3(0.0f, -50.0f, 0.0f));

	camera.SetBackgroundColor(0.4f, 0.2f, 0.9f);

	playerCube.draw(*unlitTex, glm::vec2(1.0f, 1.0f));
	unlitTex->AttachTextureToSlot(*containerTex, 0);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *unlitTex);

	playerMovement.Move(playerCube, time);

	platform.SetPosition(glm::vec3(0.0f, -0.5f, -0.0f));
	platform.SetRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	platform.SetScale(glm::vec3(0.7f, 0.1f, 10.0f));

	platformSpawner.Spawn(platform, *unlitColor);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *unlitColor);

	playerCube.SetScale(glm::vec3(0.2f));
}

void Level1::ClearData()
{
	platform.clearData();
	unlitTex->Delete();
}