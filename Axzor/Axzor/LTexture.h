/* En-tête du programme
*****************************************
Fichier :			visuel.h
Auteur:				Guillaume Bergs & Shawn Corriveau
Date de création :  2016/01/01
Description :		Tout ce qui concerne l'affichage d'images à l'écran
Commentaires :
*****************************************/

#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

//Taille de l'écran en pixels
const int LARGEUR_FENETRE = 900;
const int HAUTEUR_FENETRE = 550;
const int FACTEUR_RALENTISSEMENT_ANIMATION = 10;  //Pour rendre l'animation plus rapide, indiquer un chiffre plus petit


//Les définitions de fonctions

//***************************************** Classe qui nous permet de manipuler les textures (Ne pas éditer)

////Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();
	LTexture(SDL_Renderer *renderer);


	//Deallocates memory
	~LTexture();

	void setRenderer(SDL_Renderer* renderer);


	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL);
	void render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//Renderer
	SDL_Renderer *rendererFenetre;
private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

