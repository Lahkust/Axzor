/* En-tête du programme
*****************************************
Fichier :			sprite.h
Auteur:				Mylène Desrosiers
Date de création :  
Description :		
Commentaires :
*****************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "LTexture.h"


#pragma once
class sprite
{

	//champs de la classe

public:
	sprite();
	~sprite();

	bool chargerTexture(std::string nomFichier);

	char get_type();
	SDL_Point get_position();

	SDL_Rect get_rect();

	int get_hauteur();
	int get_largeur();


	void set_position(SDL_Point position);
	void set_type(char type);

	void set_renderer(SDL_Renderer* render);

	void set_hauteur(int hauteur);
	void set_largeur(int largeur);

	void sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE);
	void avancer();
	
	void render();

protected:

	double angle;

	/*int _position_x;
	int _position_y;*/

	/*
	int _largeur_sprite;
	int _hauteur_sprite;*/

	/*const float GRAVITE = 9.81;*/ //Ajouter dans le magicien

	SDL_RendererFlip flip;
	
	SDL_Rect rectangle_visible;
	char _type;

	char _direction;
	

	LTexture _sprite_texture;

	SDL_Point _position;
	

	char detecter_collision(SDL_Rect a, SDL_Rect b);


};


