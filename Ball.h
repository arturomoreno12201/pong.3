#pragma once
#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"
#include "player.cpp"
#include "Ball.h"


void drawBall(const Ball &b);
void updateBall(Ball &b);

struct Ball
{
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned steps;
};

Ball createBall(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps)
{
	Ball ret;
	ret.xpos = b_xpos;
	ret.ypos = b_ypos;
	ret.xvel = b_xvel;
	ret.yvel = b_yvel;
	ret.radius = b_rad;
	ret.steps = b_steps;

	return ret;
}