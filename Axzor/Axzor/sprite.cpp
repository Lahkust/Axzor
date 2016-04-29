#include "sprite.h"




sprite::sprite()
{
	_position_x = 0;
	_position_y = 0;
	_type = 0;
	_direction = 0;
}


sprite::~sprite()
{
}


int sprite::get_x()
{
	return _position_x;
}


int sprite::get_y()
{
	return _position_y;
}


SDL_Rect sprite::get_rect()
{
	return SDL_Rect();
}


void sprite::set_x(int x)
{

	_position_x = x;

}


void sprite::set_y(int y)
{

	_position_x = y;

}


void sprite::set_renderer(SDL_Renderer* render)
{

	_sprite_texure.setRenderer(render);

}


void sprite::sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE)
{

	_position_y += vitesse_verticale * temps_depuis_debut_saut - 0.5 * GRAVITE *  temps_depuis_debut_saut *  temps_depuis_debut_saut;

}


void sprite::avancer()
{
}


bool sprite::collision(SDL_Rect a, SDL_Rect b)
{
	//D�clarer les c�t�s de chaque hitbox

	int gaucheA, gaucheB;
	int droitA, droitB;
	int dessusA, dessusB;
	int dessousA, dessousB;
	//Assigner les c�t� des rectangles au variables des c�t�s de hitbox que l'on vient de cr�er


	//Calculer les c�t� du rectangle A
	gaucheA = a.x;
	droitA = a.x + a.w;
	dessusA = a.y;
	dessousA = a.y + a.h;

	//Calculer les c�t�s du rectangle B
	gaucheB = b.x;
	droitB = b.x + b.w;
	dessusB = b.y;
	dessousB = b.y + b.h;


	//Si n'importe quels des c�t�s de A est � l'int�rieur de la hitbox B

	if (dessousA <= dessusB)
	{
		return false;
	}

	if (dessusA >= dessousB)
	{
		return false;
	}

	if (droitA <= gaucheB)
	{
		return false;
	}

	if (gaucheA >= droitB)
	{
		return false;
	}

	//Si aucune c�t� de A n'est l� l'int�rieur de B
	return true;

}
