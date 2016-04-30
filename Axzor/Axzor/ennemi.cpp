#include "ennemi.h"
#include "bloc.h"

ennemi::ennemi()
{
	this->set_x(0);
	this->set_y(0);
	this->set_renderer(NULL);		
	vie = 0.0;
}


ennemi::~ennemi()
{

	this->_position_x;
}


ennemi::ennemi(int x, int y, SDL_Renderer* renderer, char type)
{
	this->set_x(x);
	this->set_y(y);
	_renderer = render;
	_type = type;
}


bool ennemi::collision(bloc lebloc)
{
	if(this->detecter_collision(this->get_rect(), lebloc.get_rect()))
		switch (lebloc.get_type())
	{
		case 'V': this->
			break;

		case 'I':
			break;

		default:
			break;
	}

	return false;
}

bool ennemi::collision(ennemi badguy)
{
	return false;
}
