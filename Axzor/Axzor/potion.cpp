#include "potion.h"


potion::potion()
{
}


potion::~potion()
{
}


potion::potion(int x, int y, SDL_Renderer* render)
{
	this->set_x(x);
	this->set_y(y);
	this->set_renderer(render);
}
