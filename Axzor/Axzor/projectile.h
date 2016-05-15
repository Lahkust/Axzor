
#pragma once

#include "sprite.h"
#include "staff.h"
#include "ennemi.h"
#include <vector>



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