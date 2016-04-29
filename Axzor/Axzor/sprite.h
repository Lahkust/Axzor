#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "LTexture.h"


#pragma once
class sprite
{

public:
	sprite();
	~sprite();

	char get_type();

	SDL_Rect get_rect();



	char set_type(char type);

	void set_renderer(SDL_Renderer* render);
	void sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE);
	void avancer();
	
	void render() {

		SDL_Point center;	//Contient le centre de l'image
		center.x = _largeur_sprite / 2;
		center.y = _hauteur_sprite / 2;

		_sprite_texure.render(_position_x, _position_y, &rect, angle, &center, flip);

	}

protected:


	int _position_x;
	int _position_y;

	double angle;

	int _largeur_sprite;
	int _hauteur_sprite;

	const float GRAVITE = 9.81;

	SDL_RendererFlip flip;
	
	SDL_Rect rect;
	char _type;

	char _direction;

	LTexture _sprite_texure;

	SDL_Point _position;
	

	bool detecter_collision(SDL_Rect a, SDL_Rect b);


};


