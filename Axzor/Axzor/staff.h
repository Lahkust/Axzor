/* En-tête du programme
*****************************************
Fichier :			staff.h
Auteur:				Mylène Desrosiers
Date de création :  
Description :		
Commentaires :
*****************************************/
#pragma once



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


