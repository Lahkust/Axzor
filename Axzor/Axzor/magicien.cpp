#include "magicien.h"


magicien::magicien()
{
	vie = 0.0f;
	_velocite = 0.0f;
}


magicien::~magicien()
{
}


magicien::magicien(int x, int y, renderer render)
{
}


void magicien::reduire_vie(int pv)
{
}


int magicien::augmenter_vie(int pv)
{
	return 0;
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
