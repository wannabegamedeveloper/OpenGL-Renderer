#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CollisionDetector
{
private:
	glm::vec2 p1pos[3] = { glm::vec2(-0.3f, -0.1f), glm::vec2(-0.1f, 0.1f), 
		glm::vec2(0.1f, 0.3f)};

	glm::vec2 p2pos[5] = { glm::vec2(-0.5f, -0.3f), glm::vec2(-0.3f, -0.1f),
		glm::vec2(-0.1f, 0.1f), glm::vec2(0.1f, 0.3f), glm::vec2(0.3f, 0.5f) };

	glm::vec2 p3pos[7] = { glm::vec2(-0.7f, -0.5f), glm::vec2(-0.5f, -0.3f),
		glm::vec2(-0.3f, -0.1f), glm::vec2(-0.1f, 0.1f), glm::vec2(0.1f, 0.3f),
		glm::vec2(0.3f, 0.5f), glm::vec2(0.5f, 0.7f) };

public:
	int CheckCollision(float x, int index);

};