#include <cstdlib>
#include <random>
#include "sfwdraw.h"

using namespace sfw;

void cool()
{
	

	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png",16,16);
	unsigned r = loadTextureMap("./res/background.jpg");
	unsigned u = loadTextureMap("./res/crosshair.png");

	float acc = 0;
	char c = '\0';

	
	{	
		drawString(f, " !\"#$%&'()*+,./-\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n`abcdefghijklmno\npqrstuvwxyz{|}~", 0, 600, 48, 48, 0, ' ');
		drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);

		acc += getDeltaTime();
		drawString(d, "TIME 4 FUN", 400, 300, 48, 48, -acc*24,'\0',RED);
		
		drawString(d, "This is Rice", 200, 100, 48, 48);
		drawString(d, "6", 400, 32, 24, 24);
		drawString(d, "12", 400, 600 - 32, 24, 24);
		drawString(d, "3", 800-32, 300, 24, 24);
		drawString(d, "9", 32, 300, 24, 24);

		if(getMouseButton(MOUSE_BUTTON_RIGHT))
			drawTexture(u, getMouseX(), getMouseY(), getTextureWidth(u)/2.5, getTextureHeight(u)/2.5,45,true,0,0x88ffffff);
		else drawTexture(u, getMouseX(), getMouseY(), getTextureWidth(u)/2, getTextureHeight(u)/2);
	}

	termContext();
}

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
}

struct Player
{
	// How many variables do I need?
	float x, y;
	float size;
	char up, down;
};

Player createPlayer(float a_x, char a_up, char a_down)
{
	Player ret;
	ret.x    = a_x;
	ret.up   = a_up;
	ret.down = a_down;

	ret.size = 75;
	ret.y	 = 300;
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

int main()
{
	initContext(800, 600, "NSFW Draw");
	setBackgroundColor(WHITE);

	float acc = 0;
	float acc2 = 0;
	float accRand = rand();

	int player = 0;
	Player p1 = createPlayer( 10, 'W', 'S');
	Player p2 = createPlayer(790, 'I', 'K');
	Ball b = createBall(400, 290, 100, 100, 10, 30);
	while (stepContext())
	{		
		drawLine(400, 0, 400, 600, BLACK);

			updatePlayer(p1);
			updatePlayer(p2);
			
			drawPlayer(p1);
			drawPlayer(p2);
		/*
		// PADDLE 1
		// If the key is W, then P1 will go up (+=) by the speed of delta time times 500
		if (getKey('W'))
		{
			acc += getDeltaTime() * 500;
		}

		// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
		if (getKey('S'))
		{
			acc -= getDeltaTime() * 500;
		}

		//The line
		drawLine(10, 300 + acc, 10,  250 + acc, RED);

		// PADDLE 2
		// If the key is I, then P2 will go up (+=) by the speed of delta time times 500
		if (getKey('I'))
		{
			acc2 += getDeltaTime() * 500;
		}

		// If the key is K, then P2 will go down (-=) by the speed of delta time times 500
		if (getKey('K'))
		{
			acc2 -= getDeltaTime() * 500;
		}

		//The line
		drawLine(790, 300 + acc2, 790, 250 + acc2, BLUE);
		
		accRand += getDeltaTime() * 100;

		drawCircle(400 + accRand, 300 + accRand, 10, 30, BLACK);
		*/
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