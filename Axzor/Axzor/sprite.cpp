#include "sprite.h"


sprite::sprite()
{
	position_x = 0;
	position_y = 0;
	type = 0;
	direction = 0;
}


sprite::~sprite()
{
}


int sprite::get_x()
{
	return 0;
}


int sprite::get_y()
{
	return 0;
}


SDL_Rect sprite::get_rect()
{
	return SDL_Rect();
}


void sprite::set_x(int x)
{
}


void sprite::set_y(int y)
{
}


void sprite::set_renderer(renderer render)
{
}


void sprite::sauter()
{
}


void sprite::avancer()
{
}


bool sprite::collision()
{
	return false;
}
