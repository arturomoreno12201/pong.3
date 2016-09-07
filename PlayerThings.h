#pragma once
#include <cstdlib>
#include <random>
#include "sfwdraw.h"
#include "PlayerThings.h"
#include "player.cpp"

struct Player
{
	// How many variables do I need?
	float x, y;
	float size;
	char up, down;
};