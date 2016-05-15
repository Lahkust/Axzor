#pragma once
#include "sprite.h"

const float POINTS_VIE_POTION = 2.0;

class potion: public sprite
{
public:
	potion();
	~potion();
	potion(int x, int y, SDL_Renderer* render);
};

