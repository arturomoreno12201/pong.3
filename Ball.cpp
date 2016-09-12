#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"
#include "player.cpp"
#include "Ball.h"


void drawBall(const Ball &b)
{
	drawCircle(b.xpos, b.ypos, b.radius, b.steps, BLACK);
}
//fs

void updateBall(Ball &b)
{
	b.xpos += b.xvel * getDeltaTime();
	b.ypos += b.yvel * getDeltaTime();

	if (b.ypos < 0)
	{
		b.yvel *= -1;
	}

	if (b.ypos > 600)
	{
		b.yvel *= -1;
	}

	if (b.xpos < 0)
	{
		//b.xvel *= -1;
		b.xpos = 400;
		b.ypos = 300;

		b.xvel = rand() % 1000 - 10;
		b.yvel = rand() % 1000 - 10;
	}

	if (b.xpos > 800)
	{
		//b.xvel *= -1;
		b.xpos = 400;
		b.ypos = 300;

		b.xvel = rand() % 1000 - 1010;
		b.yvel = rand() % 1000 - 1010;
	}
}