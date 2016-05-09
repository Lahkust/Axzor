#include "potion.h"


potion::potion()
{
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
}


potion::~potion()
{
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
}


potion::potion(int x, int y, SDL_Renderer* render)
{
	_position.x = x;
	_position.y = y;
	set_renderer(render);
}
