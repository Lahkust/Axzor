/* En-tête du programme
*****************************************
Fichier :			projectile.h
Auteur:				Mylène Desrosiers
Date de création :  
Description :		
Commentaires :
*****************************************/

#pragma once

#include "sprite.h"
#include "staff.h"
#include "ennemi.h"
#include <vector>

const int LARGEUR_PROJECTILE = 25;			 // Largeur du projectile
const int HAUTEUR_PROJECTILE = 15;			 // Hauteur du projectile
const int LARGEUR_CHARSET_PROJECTILE = 50;	 // Largeur du charset projectile
const int HAUTEUR_CHARSET_PROJECTILE = 60;	 // Hauteur du charset projectile

class projectile : public sprite{


public:

	//constructeur
	projectile();
	projectile(staff baton, SDL_Rect projectile_Rect_Texture, SDL_Renderer *render, char type);
	//destructeur
	~projectile();

	//Méthode
	int collision(ennemi mechant);

private:

	char direction;
	const float POINT_DEGAT_EP_NEUTRE = 2;
	const float POINT_DEGAT_EP_FAIBLE = 1;
	const float POINT_DEGAT_EP_FORT = 3;





	







};