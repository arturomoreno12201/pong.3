#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"
#include "player.cpp"
#include "Ball.h"

using namespace sfw;

/*
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
	ret.xpos   = b_xpos;
	ret.ypos   = b_ypos;
	ret.xvel   = b_xvel;
	ret.yvel   = b_yvel;
	ret.radius = b_rad;
	ret.steps  = b_steps;

	return ret;
}

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
}*/





int main()
{
	initContext(800, 600, "NSFW Draw");
	setBackgroundColor(WHITE);

	float acc = 0;
	float acc2 = 0;
	float accRand = rand();

	int player = 0;
	Player p2 = createPlayer(790, 'I', 'K');

	Ball b = createBall(400, 290, 100, 100, 10, 30);
	while (stepContext())
	{		
		drawLine(400, 0, 400, 600, BLACK);

			updatePlayer(p1);
			updatePlayer(p2);
			
			drawPlayer(p1);
			drawPlayer(p2);
		
			updateBall(b);
			drawBall(b);

			if (b.xpos < p1.x && b.ypos > p1.y && b.ypos < p1.y+p1.size)
			{
				b.xvel *= -1;
				b.xpos = p1.x;
			}

			if (b.xpos > p2.x && b.ypos > p2.y && b.ypos < p2.y+p2.size)
			{
				b.xvel *= -1;
				b.xpos = p2.x;
			}

	}
	termContext();
}