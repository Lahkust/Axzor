
#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "LTexture.h"
#include "sprite.h"


class staff : public sprite
{
public:
	staff(){

		sprite::sprite();	//apelle le constructeur de sprites, mais pour staff.

	}
	staff(int x, int y, SDL_Renderer* render, char _type);
	~staff();


	void Tirer();


private:



	int _position_x;
	int _position_y;

	SDL_Rect rect;
	char _type;
	char _direction;

	LTexture _sprite_texure;

};


