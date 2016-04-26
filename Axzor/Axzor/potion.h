#pragma once
#include "sprite.h"
class potion: public sprite
{
public:
	potion();
	~potion();
	potion(int x, int y, renderer render);
};

