#pragma once
#include "sprite.h"
#include "bloc.h"
class ennemi: public sprite
{
public:
	ennemi();
	~ennemi();
private:
	float vie;
	SDL_Point _velocite;
public:
	ennemi(int x, int y, SDL_Renderer* render, char type);
	bool collision(bloc lebloc);
	bool collision(ennemi badguy);
};

