#pragma once
#include "sprite.h"
#include "staff.h"
#include "ennemi.h"
#include "bloc.h"
#include "potion.h"

const float POINTS_DEGATS_ME = 0.5;

class magicien: public sprite
{
public:
	magicien();
	~magicien();
private:
	staff _baton;
	float _vie;
	SDL_Point _velocite;
public:
	magicien(int x, int y, SDL_Renderer* renderer);
private:
	void reduire_vie(int pv);
	void augmenter_vie(int pv);
public:
	bool collision(ennemi badguy);
	bool collision(bloc lebloc);
	bool collision(potion lapotion);
	bool collision(staff baton);
};

