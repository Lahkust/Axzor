#pragma once
class ennemi
{
public:
	ennemi();
	~ennemi();
private:
	float vie;
public:
	ennemi(int x, int y, renderer render, char type);
	bool collision(bloc lebloc);
	bool collision(ennemi badguy);
};

