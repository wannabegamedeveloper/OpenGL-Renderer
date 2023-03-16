#include "Level1.h"

void Level1::Start()
{
	gridTex = new Texture("grid.jpg", GL_RGB);

	unlitTex = new Shader("unlit_textured.shader");
	unlitTex->AttachTextureToSlot(*gridTex, 0);
}

void Level1::Update()
{
	camera.setCamera(90.0f, 800, 800, 0.01f, 100.0f, *unlitTex);
	camera.SetPosition(glm::vec3(0.0f, 0.0f, 1.0f));

	camera.SetBackgroundColor(1.0f, 0.0f, 1.0f);

	cube.draw(*unlitTex, glm::vec3(0.0f, 0.0f, 0.0f));
	cube.SetRotation(40.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	cube.SetScale(glm::vec3(0.5f));

	cube.draw(*unlitTex, glm::vec3(0.0f, 1.0f, 0.0f));
	cube.SetRotation(40.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	cube.SetScale(glm::vec3(0.5f));
}

void Level1::ClearData()
{
	cube.clearData();
	unlitTex->Delete();
}