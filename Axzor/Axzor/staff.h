/* En-tête du programme
*****************************************
Fichier :			staff.h
Auteur:				Mylène Desrosiers
Date de création :  
Description :		
Commentaires :
*****************************************/
#pragma once

const int LARGEUR_STAFF = 25;				 // Hauteur du staff
const int HAUTEUR_STAFF = 60;				 // Largeur du staff
const int LARGEUR_CHARSET_STAFF = 25;		 // Largeur du charset staff
const int HAUTEUR_CHARSET_STAFF = 300;		 // Hauteur du charset staff

#include "sprite.h"



class staff : public sprite
{
public:
	staff();
	staff(int x, int y, SDL_Renderer* render, char _type);
	~staff();
	


private:

	

	SDL_Rect rect;
	char _type;
	char _direction;

	LTexture _sprite_texure;

};


