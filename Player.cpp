#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"

using namespace sfw;


int player = 0;
Player p2 = createPlayer(790, 'I', 'K');
Player p1 = createPlayer(790, 'W', 'S');



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
