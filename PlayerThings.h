#pragma once
#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"
#include "player.cpp"


float acc = 0;
float acc2 = 0;
float accRand = rand();

int player = 0;
Player p2 = createPlayer(790, 'I', 'K');

void drawPlayer(const Player &p);
void updatePlayer(Player &p);

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
	ret.x = a_x;
	ret.up = a_up;
	ret.down = a_down;

	ret.size = 75;
	ret.y = 300;
	return ret;
}

