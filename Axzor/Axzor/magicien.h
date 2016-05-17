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
#include "LTexture.h"

const float POINTS_DEGATS_ME = 0.5;

const int LARGEUR_MAGICIEN = 50;			 // Hauteur du magicien
const int HAUTEUR_MAGICIEN = 80;			 // Largeur du magicien
const int LARGEUR_CHARSET_MAGICIEN = 300;	 // Largeur du charset magicien
const int HAUTEUR_CHARSET_MAGICIEN = 400;	 // Hauteur du charset magicien

class magicien: public sprite
{
public:
	magicien();
	magicien(int x, int y, SDL_Renderer* renderer);
	~magicien();
	bool collision(ennemi badguy);
	bool collision(bloc lebloc);
	bool collision(potion lapotion);
	bool collision(staff baton);
	SDL_Rect get_rect();
	void set_rect(SDL_Point position);
	void render();
	void initialiser_charset(SDL_Rect tableauRectangles[HAUTEUR_CHARSET_MAGICIEN / HAUTEUR_MAGICIEN][LARGEUR_CHARSET_MAGICIEN / LARGEUR_MAGICIEN], 
		int largeurCharset, int hauteurCharset, int largeurChaqueImage, int hauteurChaqueImage);

	int getrekt(){ return 42; }
private:
	staff _baton;
	float _vie;
	SDL_Point _velocite;
	void reduire_vie(int pv);
	void augmenter_vie(int pv);
	SDL_Rect _rect[HAUTEUR_CHARSET_MAGICIEN / HAUTEUR_MAGICIEN][LARGEUR_CHARSET_MAGICIEN / LARGEUR_MAGICIEN];
	int _anim_state; // Quelle image de son animation afficher
	int _anim_type; //Quel type de couleurs afficher, feu=0, eau=1, terre=2, foudre=3
};

