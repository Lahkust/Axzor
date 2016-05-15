#include "staff.h"

const int LARGEUR_STAFF = 25;				 // Hauteur du staff
const int HAUTEUR_STAFF = 60;				 // Largeur du staff
const int LARGEUR_CHARSET_STAFF = 25;		 // Largeur du charset staff
const int HAUTEUR_CHARSET_STAFF = 300;		 // Hauteur du charset staff

staff::staff()
{

}

staff::staff(int x, int y, SDL_Renderer* render, char _type){

	sprite::sprite();	//apelle le constructeur de sprites, mais pour staff.
}
staff::~staff()
{

}
