#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "visuel.h"


#pragma once
class sprite
{
public:
	sprite();
	~sprite();
private:



	int _position_x;
	int _position_y;
	
	SDL_Rect rect;
	char _type;
	renderer render;
	char _direction;


public:

	int get_x();
	int get_y();
	SDL_Rect get_rect();
	void set_x(int x);
	void set_y(int y);
	void set_renderer(renderer render);
	void sauter();
	void avancer();
	bool collision();
};

