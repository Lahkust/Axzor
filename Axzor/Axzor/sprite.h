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


	int get_x();
	int get_y();
	SDL_Rect get_rect();
	void set_x(int x);
	void set_y(int y);
	void set_renderer(SDL_Renderer* render);
	void sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE);
	void avancer();
	bool collision(SDL_Rect a, SDL_Rect b);
	void render() {

		SDL_Point center;
		center.x = largeur_sprite / 2;
		center.y = hauteur_sprite / 2;

		_sprite_texure.render(_position_x, _position_y, &rect, angle, &center, flip);

	}


private:



	int _position_x;
	int _position_y;
	double angle;
	int largeur_sprite;
	int hauteur_sprite;
	SDL_RendererFlip flip;
	
	SDL_Rect rect;
	char _type;
	char _direction;

	LTexture _sprite_texure;

};


