#pragma once
#include "SDL/SDL.h"
#include "sprite.h"

class bloc : public sprite
{
public:
	bloc();
	~bloc();
	bloc(char type, SDL_Renderer* renderer);
	void setRenderer(SDL_Renderer *renderer);








};