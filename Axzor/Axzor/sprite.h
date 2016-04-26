#pragma once
class sprite
{
public:
	sprite();
	~sprite();
private:
	int position_x;
	int position_y;
	L_Texture texture;
	SDL_Rect rect;
	char type;
	renderer render;
public:
	int get_x();
	int get_y();
	SDL_Rect get_rect();
	void set_x(int x);
	void set_y(int y);
	void set_renderer(renderer render);
	void sauter();
private:
	char direction;
public:
	void avancer();
	bool collision();
};

