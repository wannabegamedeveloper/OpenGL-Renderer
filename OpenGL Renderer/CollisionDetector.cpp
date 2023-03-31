#include "CollisionDetector.h"

int CollisionDetector::CheckCollision(float x, int index)
{
	if (index == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (x > p1pos[i].x && x < p1pos[i].y)
				return i;
		}
	}
	else if (index == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (x > p2pos[i].x && x < p2pos[i].y)
				return i;
		}
	}
	else if (index == 2)
	{
		for (int i = 0; i < 7; i++)
		{
			if (x > p3pos[i].x && x < p3pos[i].y)
				return i;
		}
	}
}