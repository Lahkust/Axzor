# include "projectile.h"


//Constructeur
projectile::projectile()
{

	_position.x = 0;
	_position.y = 0;
	_type = 0;
	set_renderer(NULL);
}

projectile::projectile(staff baton, SDL_Rect _sprite_texture, SDL_Renderer *render, char type)
{
	
	_position.x = 0;
	_position.y = 0;
	_type = 0;
	set_type(type);
	set_renderer(render);

}



//Destructeur
projectile::~projectile()
{

}


int projectile::collision(ennemi mechant){

	int degats = 0;


	switch (_type)
	{

	case 'F':	//Si le projectile est de type feu

	{

		switch (mechant.get_type()){

		case 'F':	//Si le type du méchant est feu
		{
			degats = 0;
			break;
		}

		case 'W':	//Si le type du méchant est eau
		{
			degats = POINT_DEGAT_EP_FAIBLE;
			break;
		}
		case 'L':	//Si le type du méchant est foudre
		{
			degats = POINT_DEGAT_EP_NEUTRE;
			break;
		}
		case 'T':	//Si le type du méchant est terre
		{
			degats = POINT_DEGAT_EP_FORT;
			break;
		}
		}
	}

	case 'W':	//Si le type du projectile est eau
	{
		switch (mechant.get_type()){

		case 'F':	//Si le type du méchant est feu
		{
			degats = POINT_DEGAT_EP_FORT;
			break;
		}

		case 'W':	//Si le type du méchant est eau
		{
			degats = 0;
			break;
		}
		case 'L':	//Si le type du méchant est foudre
		{
			degats = POINT_DEGAT_EP_FAIBLE;
			break;
		}
		case 'T':	//Si le type du méchant est terre
		{
			degats = POINT_DEGAT_EP_NEUTRE;
			break;
		}
		}
	}

	case 'L':	//Si le type du projectile est foudre
	{
		switch (mechant.get_type()){

		case 'F':	//Si le type du méchant est feu
		{
			degats = POINT_DEGAT_EP_NEUTRE;
			break;
		}

		case 'W':	//Si le type du méchant est eau
		{
			degats = POINT_DEGAT_EP_FORT;
			break;
		}
		case 'L':	//Si le type du méchant est foudre
		{
			degats = 0;
			break;
		}
		case 'T':	//Si le type du méchant est terre
		{
			degats = POINT_DEGAT_EP_FAIBLE;
			break;
		}
		}
	}

	case 'T':	//Si le type du projectile est foudre
	{
		switch (mechant.get_type()){

		case 'F':	//Si le type du méchant est feu
		{
			degats = POINT_DEGAT_EP_FAIBLE;
			break;
		}

		case 'W':	//Si le type du méchant est eau
		{
			degats = POINT_DEGAT_EP_NEUTRE;
			break;
		}
		case 'L':	//Si le type du méchant est foudre
		{
			degats = POINT_DEGAT_EP_FORT;
			break;
		}
		case 'T':	//Si le type du méchant est terre
		{
			degats = 0;
			break;
		}
		}
	}

	default:
		break;
	}


	return degats;


}





