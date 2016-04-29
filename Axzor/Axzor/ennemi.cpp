#include "ennemi.h"
#include "bloc.h"

ennemi::ennemi()
{
	this->set_x(0);
	this->set_y(0);
	this->set_renderer(renderer());		//Remplacer renderer par NULL pour créer un renderer vide ?
	vie = 0.0;
}


ennemi::~ennemi()
{
}


ennemi::ennemi(int x, int y, SDL_Renderer* render, char type)
{
	this->set_x(x);
	this->set_y(y);
	this->set_renderer(render);
	this->set_type(type);
}


bool ennemi::collision(bloc lebloc)
{
	return false;
}

bool ennemi::collision(ennemi badguy)
{
	return false;
}
