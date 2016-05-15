/* En-tête du programme
*****************************************
Fichier :			magicien.h
Auteur:				Guillaume Bergs
Date de création :  
Description :		
Commentaires :
*****************************************/

#pragma once
#include "sprite.h"
#include "staff.h"
#include "ennemi.h"
#include "bloc.h"
#include "potion.h"

const float POINTS_DEGATS_ME = 0.5;

const int LARGEUR_MAGICIEN = 50;			 // Hauteur du magicien
const int HAUTEUR_MAGICIEN = 80;			 // Largeur du magicien
const int LARGEUR_CHARSET_MAGICIEN = 300;	 // Largeur du charset magicien
const int HAUTEUR_CHARSET_MAGICIEN = 400;	 // Hauteur du charset magicien

class magicien: public sprite
{
public:
	magicien();
	~magicien();
private:
	staff _baton;
	float _vie;
	SDL_Point _velocite;
public:
	magicien(int x, int y, SDL_Renderer* renderer);
private:
	void reduire_vie(int pv);
	void augmenter_vie(int pv);
public:
	bool collision(ennemi badguy);
	bool collision(bloc lebloc);
	bool collision(potion lapotion);
	bool collision(staff baton);
};

