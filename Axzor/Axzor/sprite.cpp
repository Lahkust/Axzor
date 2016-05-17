#include "sprite.h"

//cpnstructeurs
sprite::sprite()
{
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	_direction = 0;

}

//destructeurs
sprite::~sprite()
{

}



//getters


SDL_Point sprite::get_position(){

	return _position;

}



char sprite::get_type()
{
	return _type;
}



SDL_Rect sprite::get_rect()
{
	return SDL_Rect();
}

int sprite::get_hauteur()
{
	return rectangle_visible.h;
}

int sprite::get_largeur()
{
	return rectangle_visible.w;
}



//setters

void sprite::set_position(SDL_Point position){

	_position = position;

}

void sprite::set_type(char type)
{
	_type = type;
}



void sprite::set_renderer(SDL_Renderer* render)
{

	_sprite_texture.setRenderer(render);

}

void sprite::set_hauteur(int hauteur){

	rectangle_visible.h = hauteur;

}

void sprite::set_largeur(int largeur){

	rectangle_visible.w = largeur;

}


//MÉTHODES

bool sprite::chargerTexture(std::string nomFichier){

	//Load balle sprite texture
	return _sprite_texture.loadFromFile(nomFichier);
	
}


void sprite::sauter(float vitesse_verticale, float temps_depuis_debut_saut, const float GRAVITE)	//Fonction qui permet de faire sauter le personnage
{

	_position.y += vitesse_verticale * temps_depuis_debut_saut - 0.5 * GRAVITE *  temps_depuis_debut_saut *  temps_depuis_debut_saut;

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

		(droitA >= droitB And gaucheA <= gaucheB)) And			******************	Utiles ?

		((dessousA >= dessusB And dessousA <= dessousB) Or
		(dessusA >= dessusB And dessusA <= dessousB) Or

		(dessusA <= dessusB And dessousA >= dessousB)) Then		***************** Utile ?
		Return True
		Else
		Return False
		End If*/

	if (gaucheA >= gaucheB && gaucheA <= droitB){//Si le côté gauche de A est + loin que le côté gauche de B ET que le côté gauche de A est moins loin que le côté droit de B
		//(le côté gauche de A est entre les deux côtés de B)

		resultat = 'D';

	}

	if (droitA >= gaucheB && droitA <= droitB){	//Si le côté droit de A est + loin que le côté gauche de B ET que le côté droit de A est - loin que le côté droit de B
		//(Le côté droit de A est entre les deux côtés de B)

		resultat = 'G';

	}

	if (dessousA >= dessusB && dessousA <= dessousB){	//Si le dessous de A est + loin que le dessus de B ET que le dessous de A soit - loin que le dessous de B
		//(Le dessous de A est entre le dessus et le dessous de B)

		resultat = 'H';

	}

	if (dessusA >= dessusB && dessusA <= dessousB){	//Si le dessus de A est + loin que le dessus de B ET que le dessus de A est - loin que le dessous de B 
		//(le dessus de A est entre le dessus et le dessous de B)

		resultat = 'B';

	}
	else {

		resultat = 'F';
	}

	return resultat;




}

void sprite::render(){

			SDL_Point center;	//Contient le centre de l'image
			center.x = rectangle_visible.w / 2;
			center.y = rectangle_visible.h / 2;
			
			_sprite_texture.render(_position.x, _position.y, &rectangle_visible, angle, &center, flip);

			//_sprite_texture.render(_position.x, _position.y, &rect, angle, &center, flip);
			//_sprite_texture.render(_position.x, _position.y, NULL);

}