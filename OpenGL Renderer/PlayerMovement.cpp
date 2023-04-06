#include "PlayerMovement.h"

void PlayerMovement::Move(Cube& cube, float deltaTime, Shader shader)
{
	zPos += movementSpeed * deltaTime;

	position.y = -0.2f;
	position.z = zPos;
	
	if (inputManager.GetKey(GLFW_KEY_A))
		position.x += movementSpeed * deltaTime;
	else if (inputManager.GetKey(GLFW_KEY_D))
		position.x -= movementSpeed * deltaTime;

	if (zPos < -45.0f && zPos > -90.0f)
	{
		currentPhase = 1;
	}
	else if (zPos < -95.0f)
	{
		currentPhase = 2;
	}
	
	if (currentPhase == 0)
	{
		cube.SetColor(ps.phase1[col.CheckCollision(position.x, 0)]);
		position.x = clamp(position.x, -0.2f, 0.2f);
	}
	else if (currentPhase == 1)
	{
		cube.SetColor(ps.phase2[col.CheckCollision(position.x, 1)]);
		position.x = clamp(position.x, -0.4f, 0.4f);
	}
	else
	{
		cube.SetColor(ps.phase3[col.CheckCollision(position.x, 2)]);
		position.x = clamp(position.x, -0.6f, 0.6f);
	}

	os.StartSpawning(shader, ps.phase1, ps.phase2, ps.phase3);

	cube.SetPosition(position);
}

float PlayerMovement::clamp(float n, float lower, float upper)
{
	return std::max(lower, std::min(n, upper));
}