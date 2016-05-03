#include "magicien.h"


magicien::magicien()
{
	_vie = 10.0;
	_velocite = 0.0;
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
}


magicien::~magicien()
{
	_vie = 0.0;
	_velocite = 0.0;
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
}


magicien::magicien(int x, int y, SDL_Renderer* render)
{
	_vie = 10.0;
	_velocite = 0.0;
	_position.x = x;
	_position.y = y;
	set_renderer(render);
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
	if (detecter_collision(this->get_rect(), badguy.get_rect()) != '0')
	{
		this->reduire_vie(POINTS_DEGATS_ME);
		return true;
	}
	else
	{
		return false;
	}
}


bool magicien::collision(bloc lebloc)
{
	switch (detecter_collision(this->get_rect(), lebloc.get_rect()))
	{
	case '0':
		this->_velocite = 1; //Pas de bloc; tomber
		break; 
	case 'h':
		this->_velocite = 0; //Bloc en haut; stopper le saut
		break; 
	case 'b':
		this->_velocite = 0; //Bloc en bas; stopper la chute
		break; 
	case 'g':
		return true; // Bloc sur le côté gauche
		break;
	case 'd':
		return true; // Bloc sur le côté droit
		break;
	default:
		break;
	}

	return false;
}


bool magicien::collision(potion lapotion)
{
	if (detecter_collision(this->get_rect(), lapotion.get_rect()))
	{
		this->augmenter_vie(POINTS_VIE_POTION);
		lapotion.~potion();
	}
	else
	{
		return false;
	}

}


bool magicien::collision(staff baton)
{
	if (detecter_collision(this->get_rect(), baton.get_rect()))
	{
		this->_type = baton.get_type();
	}
	else
	{
		return false;
	}
}
