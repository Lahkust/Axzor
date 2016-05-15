/* En-tête du programme
*****************************************
Fichier :			ennemi.h
Auteur:				Guillaume Bergs
Date de création :  
Description :		
Commentaires :
*****************************************/

#pragma once
#include "sprite.h"
#include "bloc.h"

const int LARGEUR_ENNEMI = 50;				 // Hauteur d’un ennemi
const int HAUTEUR_ENNEMI = 50;				 // Largeur d’un ennemi
const int LARGEUR_CHARSET_ENNEMI = 300;		 // Largeur du charset ennemi
const int HAUTEUR_CHARSET_ENNEMI = 200;		 // Hauteur du charset ennemi

class ennemi: public sprite
{
private:
	float vie;
	SDL_Point _velocite;

public:
	ennemi();
	~ennemi();
	ennemi(int x, int y, SDL_Renderer* render, char type);
	bool collision(bloc lebloc);
	bool collision(ennemi badguy);
	SDL_Point get_velocite();
	void set_velocite(SDL_Point velocite);
	void flip_horizontal();
	void flip_vertical();
};

