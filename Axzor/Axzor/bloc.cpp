#include "bloc.h"


bloc::bloc()
{
	this->set_x(0);
	this->set_y(0);
	this->set_renderer(NULL);
}


bloc::~bloc()
{
	this->set_x(0);
	this->set_y(0);
	this->set_type(0);
	this->set_renderer(NULL);
}


bloc::bloc(int x, int y, char type, SDL_Renderer* render)
{
	this->set_x(x);
	this->set_y(y);
	this->set_type(type);
	this->set_renderer(render);
}

void bloc::setRenderer(SDL_Renderer *renderer)
{
	this->blocTexture.rendererFenetre = renderer;

	//Load bloc sprite sheet texture
	if (!blocTexture.loadFromFile("images/blocCharset.png"))
	{
		printf("Échec de chargement de l'image ! \n");
		//system("pause");
		//success = false;
	}
	else
	{
		//On initialise chaque rectangle du tableau 'blocRect'
		printf("Chargement OK ! \n");
		//system("pause");
		initialiserCharset(blocRect, NOMBRE_IMAGES_BLOC_CHARSET, LARGEUR_IMAGE_BLOC_CHARSET, HAUTEUR_IMAGE_BLOC_CHARSET);
	}
}
