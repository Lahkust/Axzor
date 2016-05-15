/* En-tête du programme
*****************************************
Fichier :			potion.h
Auteur:				Guillaume Bergs
Date de création :  
Description :		
Commentaires :
*****************************************/

#pragma once
#include "sprite.h"

const int LARGEUR_POTION = 30;				 // Hauteur de la potion de soin
const int HAUTEUR_POTION = 50;				 // Largeur de la potion de soin

const float POINTS_VIE_POTION = 2.0;

class potion: public sprite
{
public:
	potion();
	~potion();
	potion(int x, int y, SDL_Renderer* render);
};

