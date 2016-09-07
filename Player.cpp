#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"

using namespace sfw;

Player createPlayer(float a_x, char a_up, char a_down)
{
	Player ret;
	ret.x = a_x;
	ret.up = a_up;
	ret.down = a_down;

	ret.size = 75;
	ret.y = 300;
	return ret;
}

void drawPlayer(const Player &p)
{
	drawLine(p.x, p.y, p.x, p.y + p.size, RED);
}

void updatePlayer(Player &p)
{
	if (getKey(p.up))
	{
		p.y += getDeltaTime() * 500;
	}

	// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
	if (getKey(p.down))
	{
		p.y -= getDeltaTime() * 500;
	}


	if (p.y < 0)
	{
		p.y = 0;
	}

	if (p.y > 540)
	{
		p.y = 540;
	}
}
