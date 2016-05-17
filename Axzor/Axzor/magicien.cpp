#include "magicien.h"
//Initialisation des rectangles qui vont s'associer aux différentes images du charset


magicien::magicien()
{
	_vie = 10.0;
	_velocite.x = 0;
	_velocite.y = 0;
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
	initialiser_charset(_rect, LARGEUR_CHARSET_MAGICIEN, HAUTEUR_CHARSET_MAGICIEN, LARGEUR_MAGICIEN, HAUTEUR_MAGICIEN);
}


magicien::~magicien()
{
	_vie = 0.0;
	_velocite.x = 0;
	_velocite.y = 0;
	_position.x = 0;
	_position.y = 0;
	set_renderer(NULL);
}


magicien::magicien(int x, int y, SDL_Renderer* render)
{
	_vie = 10.0;
	_velocite.x = 0;
	_velocite.y = 0;
	_position.x = x;
	_position.y = y;
	set_renderer(render);
	initialiser_charset(_rect, LARGEUR_CHARSET_MAGICIEN, HAUTEUR_CHARSET_MAGICIEN, LARGEUR_MAGICIEN, HAUTEUR_MAGICIEN);
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
	if (detecter_collision(this->get_rect(), badguy.get_rect()) != 'F')
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
		this->_velocite.y = 1; //Pas de bloc; tomber
		break; 
	case 'h':
		this->_velocite.y = 0; //Bloc en haut; stopper le saut
		break; 
	case 'b':
		this->_velocite.y = 0; //Bloc en bas; stopper la chute
		break; 
	case 'g':
		this->_velocite.x = 0;
		return true; // Bloc sur le côté gauche
		break;
	case 'd':
		this->_velocite.x = 0;
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



SDL_Rect magicien::get_rect()
{
	return _rect[_anim_type][_anim_state];
}


void magicien::set_rect(SDL_Point position)
{
	_anim_type = position.y;
	_anim_state = position.x;
}


void magicien::render(){
	initialiser_charset(_rect, LARGEUR_CHARSET_MAGICIEN, HAUTEUR_CHARSET_MAGICIEN, LARGEUR_MAGICIEN, HAUTEUR_MAGICIEN);

	SDL_Point center;	//Contient le centre de l'image
	center.x = get_rect().w / 2;
	center.y = get_rect().h / 2;

	_sprite_texture.render(_position.x, _position.y, &_rect[_anim_type][_anim_state], angle, &center, flip);

	//_sprite_texture.render(_position.x, _position.y, &rect, angle, &center, flip);
	//_sprite_texture.render(_position.x, _position.y, NULL);

}

void magicien::initialiser_charset(SDL_Rect tableauRectangles[HAUTEUR_CHARSET_MAGICIEN / HAUTEUR_MAGICIEN][LARGEUR_CHARSET_MAGICIEN / LARGEUR_MAGICIEN],
	int largeurCharset, int hauteurCharset, int largeurChaqueImage, int hauteurChaqueImage)
{
	for (int ligne = 0; ligne < (hauteurCharset / hauteurChaqueImage); ++ligne)
	{
		for (int colonne = 0; colonne < (largeurCharset / largeurChaqueImage); ++colonne)
		{
			tableauRectangles[ligne][colonne].x = largeurChaqueImage * colonne;
			tableauRectangles[ligne][colonne].y = hauteurChaqueImage * ligne;
			tableauRectangles[ligne][colonne].w = largeurChaqueImage;
			tableauRectangles[ligne][colonne].h = hauteurChaqueImage;
		}
	}
}