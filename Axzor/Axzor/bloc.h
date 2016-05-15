/* En-t�te du programme
*****************************************
Fichier :			bloc.h
Auteur:				Myl�ne Desrosiers
Date de cr�ation :  
Description :		
Commentaires :
*****************************************/

#pragma once
#include "SDL/SDL.h"
#include "sprite.h"

const int LARGEUR_BLOC = 50;			 	 // Hauteur du bloc
const int HAUTEUR_BLOC = 50;				 // Largeur du bloc
const int LARGEUR_CHARSET_BLOC = 450;		 // Largeur du charset bloc
const int HAUTEUR_CHARSET_BLOC = 150;		 // Hauteur du charset bloc

class bloc : public sprite
{
public:
	bloc();
	~bloc();
	bloc(char type, SDL_Renderer* renderer);
	void setRenderer(SDL_Renderer *renderer);

};