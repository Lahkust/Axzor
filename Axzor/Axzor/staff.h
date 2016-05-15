/* En-t�te du programme
*****************************************
Fichier :			staff.h
Auteur:				Myl�ne Desrosiers
Date de cr�ation :  
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


