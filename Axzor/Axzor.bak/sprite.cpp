#include "sprite.h"






sprite::sprite()
{
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	_direction = 0;

}


sprite::~sprite()
{
}


char sprite::get_type()
{
	return _type;
}

SDL_Rect sprite::get_rect()
{
	return SDL_Rect();
}

char sprite::set_type(char type)
{
	_type = type;
}



void sprite::set_renderer(SDL_Renderer* render)
{

	_sprite_texure.setRenderer(render);

}


void sprite::sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE)	//Fonction qui permet de faire sauter le personnage
{

	_position_y += vitesse_verticale * temps_depuis_debut_saut - 0.5 * GRAVITE *  temps_depuis_debut_saut *  temps_depuis_debut_saut;

}


void sprite::avancer()		//Fonction qui fait avancer le personnage
{

}


char sprite::detecter_collision(SDL_Rect a, SDL_Rect b)	//Fonction qui détecte s'il y a eu une collision
{
	//Déclarer les côtés de chaque hitbox

	int gaucheA, gaucheB;
	int droitA, droitB;
	int dessusA, dessusB;
	int dessousA, dessousB;
	char resultat;
	//Assigner les côté des rectangles au variables des côtés de hitbox que l'on vient de créer


	//Calculer les côté du rectangle A
	gaucheA = a.x;
	droitA = a.x + a.w;
	dessusA = a.y;
	dessousA = a.y + a.h;

	//Calculer les côtés du rectangle B
	gaucheB = b.x;
	droitB = b.x + b.w;
	dessusB = b.y;
	dessousB = b.y + b.h;






	/*'Vérifier le personnage entre en collision en obstacle.
		If((gaucheA >= gaucheB And gaucheA <= droitB) Or
		(droitA >= gaucheB And droitA <= droitB) Or
		(droitA >= droitB And gaucheA <= gaucheB)) And
		((dessousA >= dessusB And dessousA <= dessousB) Or
		(dessusA >= dessusB And dessusA <= dessousB) Or
		(dessusA <= dessusB And dessousA >= dessousB)) Then
		Return True
		Else
		Return False
		End If*/

	if (gaucheA >= gaucheB && gaucheA <= droitB){//Si le côté gauche de A est + loin que le côté gauche de B ET que 

		resultat = 'D';

	}

	if (droitA >= gaucheB && droitA <= droitB){	//S'il y a une collision par la gauche, retourner 'D'

		resultat = 'G';

	}








}

void sprite::render(){

			SDL_Point center;	//Contient le centre de l'image
			center.x = _largeur_sprite / 2;
			center.y = _hauteur_sprite / 2;

			_sprite_texure.render(_position_x, _position_y, &rect, angle, &center, flip);


}