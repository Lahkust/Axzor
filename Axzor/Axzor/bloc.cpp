#include "bloc.h"


bloc::bloc()
{
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	set_renderer(NULL);
}


bloc::~bloc()
{
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	set_type(0);
	set_renderer(NULL);
}


bloc::bloc(char type, SDL_Renderer* render)
{
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	set_type(type);
	set_renderer(render);
}



