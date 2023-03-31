#include "PlayerMovement.h"

void PlayerMovement::Move(Cube& cube, Time time)
{
	zPos += movementSpeed * time.GetDeltaTime();

	position.y = -0.2f;
	position.z = zPos;
	
	if (inputManager.GetKey(GLFW_KEY_A))
		position.x += movementSpeed * time.GetDeltaTime();
	else if (inputManager.GetKey(GLFW_KEY_D))
		position.x -= movementSpeed * time.GetDeltaTime();

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
		cube.SetColor(phase1[col.CheckCollision(position.x, 0)]);
		position.x = clamp(position.x, -0.2f, 0.2f);
	}
	else if (currentPhase == 1)
	{
		cube.SetColor(phase2[col.CheckCollision(position.x, 1)]);
		position.x = clamp(position.x, -0.4f, 0.4f);
	}
	else
	{
		cube.SetColor(phase3[col.CheckCollision(position.x, 2)]);
		position.x = clamp(position.x, -0.6f, 0.6f);
	}

	cube.SetPosition(position);
}

float PlayerMovement::clamp(float n, float lower, float upper)
{
	return std::max(lower, std::min(n, upper));
}