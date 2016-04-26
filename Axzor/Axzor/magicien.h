#pragma once
#include "sprite.h"
#include "staff.h"
#include "ennemi.h"
#include "bloc.h"
#include "potion.h"

class magicien: public sprite
{
public:
	magicien();
	~magicien();
private:
	staff _baton;
	float _vie;
	float _velocite;
public:
	magicien(int x, int y, renderer render);
private:
	void reduire_vie(int pv);
	void augmenter_vie(int pv);
public:
	bool collision(ennemi badguy);
	bool collision(bloc lebloc);
	bool collision(potion lapotion);
	bool collision(staff baton);
};

