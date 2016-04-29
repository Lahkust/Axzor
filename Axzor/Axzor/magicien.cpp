#include "magicien.h"


magicien::magicien()
{
	_vie = 0.0;
	_velocite = 0.0;
}


magicien::~magicien()
{
}


magicien::magicien(int x, int y, SDL_Renderer* render)
{
	this->set_x(x);
	this->set_y(y);
	this->set_renderer(render);
}


void magicien::reduire_vie(int pv)
{
	_vie -= pv;
}


void magicien::augmenter_vie(int pv)
{
	_vie += pv;
}


bool magicien::collision(ennemi badguy)
{
	return false;
}


bool magicien::collision(bloc lebloc)
{
	return false;
}


bool magicien::collision(potion lapotion)
{
	return false;
}


bool magicien::collision(staff baton)
{
	return false;
}
