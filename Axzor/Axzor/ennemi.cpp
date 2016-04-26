#include "ennemi.h"
#include "bloc.h"

ennemi::ennemi()
{
	vie = 0.0f;
}


ennemi::~ennemi()
{
}


ennemi::ennemi(int x, int y, renderer render, char type)
{
}


bool ennemi::collision(bloc lebloc)
{
	return false;
}

bool ennemi::collision(ennemi badguy)
{
	return false;
}
