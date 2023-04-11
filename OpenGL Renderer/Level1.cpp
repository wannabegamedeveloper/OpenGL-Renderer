#include "Level1.h"

void Level1::Start()
{
	gridTex = new Texture("grid.jpg", GL_RGB);
	unlitTex = new Shader("unlit_textured.shader");

	containerTex = new Texture("circle.png", GL_RGBA);
	unlitColor = new Shader("unlit_color.shader");

	litColor = new Shader("lit_color.shader");
	litTex = new Shader("lit_textured.shader");

	levelStarted = true;
}

void Level1::Update(float deltaTime)
{
	if (!levelStarted)
	{
		Start();
		return;
	}

	positionZ -= speed * deltaTime;

	camera.setCamera();
	camera.SetPosition(glm::vec3(0.0f, 1.5f, positionZ));
	camera.SetRotation(glm::vec3(0.0f, -50.0f, 0.0f));

	pointLight.SetPosition(glm::vec3(0.0f, -0.2f, positionZ), *litColor, camera);
	pointLight.SetPosition(glm::vec3(0.0f, -0.2f, positionZ), *litTex, camera);
	pointLight.SetColor(glm::vec3(1.0f, 1.0f, 1.0f), *litColor);
	pointLight.SetColor(glm::vec3(1.0f, 1.0f, 1.0f), *litTex);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *litColor);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *litTex);
	pointLight.SetupLight(*unlitColor);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *unlitColor);

	camera.SetBackgroundColor(0.4f, 0.2f, 0.9f);

	playerCube.draw(*litTex, glm::vec2(1.0f, 1.0f));
	litTex->AttachTextureToSlot(*containerTex, 0);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *litTex);

	playerMovement.Move(playerCube, deltaTime, *litTex);

	platform.SetPosition(glm::vec3(0.0f, -0.5f, -0.0f));
	platform.SetRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	platform.SetScale(glm::vec3(0.7f, 0.1f, 10.0f));

	platformSpawner.Spawn(platform, *litColor);
	camera.AttachShader(90.0f, 800, 800, 0.01f, 100.0f, *litColor);

	playerCube.SetScale(glm::vec3(0.2f));
}

void Level1::ClearData()
{
	platform.clearData();
	unlitTex->Delete();
}