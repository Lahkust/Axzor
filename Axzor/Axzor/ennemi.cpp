#include "ennemi.h"
#include "bloc.h"

ennemi::ennemi()
{
	_position.x = 0;
	_position.y = 0;
	this->set_renderer(NULL);
	vie = 0.0;
}


ennemi::~ennemi()
{
	_position.x = 0;
	_position.y = 0;
	this->set_renderer(NULL);
	vie = 0.0;
}


ennemi::ennemi(int x, int y, SDL_Renderer* renderer, char type)
{
	_position.x = x;
	_position.y = y;
	set_renderer(renderer);
	_type = type;
	vie = 10.0;
}


bool ennemi::collision(bloc lebloc)
{
	switch (detecter_collision(this->get_rect(), lebloc.get_rect()))
	{
	case 'H': //Contact en haut
		switch (lebloc.get_type())
		{
		case 'V': //Contact en haut Par un bloc visible

			switch (this->get_type())
			{
			case 'E': //impossible, th�oriquement
				break;

			case 'F': //arr�ter le saut
				_velocite.y = -0.1;

				break;

			case 'T': //impossible, th�oriquement
				break;

			case 'V': //impossible, th�oriquement
				break;

			default:
				break;
			}
			break;

		case 'I': //Contact en haut Par un bloc invisible

			switch (this->get_type())
			{
			case 'E': //impossible, th�oriquement
				break;

			case 'F': //ne rien faire
				break;

			case 'T': //impossible, th�oriquement
				break;

			case 'V': //impossible, th�oriquement
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}

		break;

	case 'B': //Contact en bas
		switch (lebloc.get_type())
		{
		case 'V': //Contact en bas Par un bloc visible

			//Ne pas tomber

			break;

		case 'I': //Contact en bas Par un bloc invisible

			//Tomber
			if (_velocite.y >= 0)
				_velocite.y -= 0.1;
			
			break;

		default:
			break;
		}

		break;

	case 'G': //Contact � gauche
		switch (lebloc.get_type())
		{
		case 'V': //Contact � gauche Par un bloc visible

			//Aller � droite
			_velocite.x *= -1;
			
			break;

		case 'I': //Contact � gauche Par un bloc invisible

			switch (this->get_type())
			{
			case 'E': //Aller � droite
				_velocite.x *= -1;
				break;

			case 'F': //Continuer d'aller � gauche
				break;

			case 'T': //Continuer d'aller � gauche
				break;

			case 'V': //Aller � droite
				_velocite.x *= -1;
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}

		break;

	case 'D': //Contact � droite
		switch (lebloc.get_type())
		{
		case 'V': //Contact � droite Par un bloc visible


			//Aller � gauche
			_velocite.x *= -1;

			break;

		case 'I': //Contact � droite Par un bloc invisible

			switch (this->get_type())
			{
			case 'E': //Aller � gauche
				_velocite.x *= -1;
				break;

			case 'F': //Continuer d'aller � droite
				break;

			case 'T': //Continuer d'aller � droite
				break;

			case 'V': //Aller � gauche
				_velocite.x *= -1;
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}

		break;


	}


	return false;
}

bool ennemi::collision(ennemi badguy)
{

	//Inverser la direction

	this->_velocite.x *= -1;
	
	//Inverser la direction de l'autre

	badguy._velocite.x *= -1;

	return false;
}


SDL_Point ennemi::get_velocite()
{
	return _velocite;
}


void ennemi::set_velocite(SDL_Point velocite)
{
	_velocite = velocite;
}


void ennemi::flip_horizontal()
{
	_velocite.x *= -1;
}


void ennemi::flip_vertical()
{
	_velocite.y *= -1;
}
