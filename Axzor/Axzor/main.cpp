/* En-tête du programme
*****************************************
Fichier :			main.cpp
Auteur:				Guillaume Bergs & Mylène Desrosiers
Date de création :  2016/01/01
Description :		Fonction principale du jeu Barkanoid
Commentaires :
*****************************************/


//*************************************** Déclarations pré-processeur
#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <cmath>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "LTexture.h"
#include <stdlib.h> 
#include <time.h>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>
#include <fstream>

#include "bloc.h"
#include "ennemi.h"
#include "magicien.h"
#include "potion.h"
#include "sprite.h"
#include "staff.h"
#include "projectile.h"

//***************************************** Prototypes
bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string path);
void charger_niveau(const char[], std::vector< std::vector<sprite> > &niveau);
bool testFichierExiste(const char[]);
bool testFichierVide(const char[]);
void ApparaitreProjectile(std::vector<projectile> &vecteurProjectile, char type);


//********************************* Variables globales (partie 1)

//La fenêtre dans laquelle le programme sera exécuté
SDL_Window* fenetreProgramme = NULL;

//Le 'renderer' associé à la fenêtre du programme. Le 'renderer' est l'endroit dans lequelle on placera des textures
SDL_Renderer* rendererFenetre = NULL;

//***********************************

//***********************************//CONSTANTES//*************************************//

//const int LARGEUR_FENETRE = 900;			 // Largeur de la fenêtre
//const int HAUTEUR_FENETRE = 550;			 // Hauteur de la fenêtre
const int LARGEUR_MAGICIEN = 50;			 // Hauteur du magicien
const int HAUTEUR_MAGICIEN = 80;			 // Largeur du magicien
const int LARGEUR_CHARSET_MAGICIEN = 300;	 // Largeur du charset magicien
const int HAUTEUR_CHARSET_MAGICIEN = 400;	 // Hauteur du charset magicien
const int LARGEUR_PROJECTILE = 25;			 // Largeur du projectile
const int HAUTEUR_PROJECTILE = 15;			 // Hauteur du projectile
const int LARGEUR_CHARSET_PROJECTILE = 50;	 // Largeur du charset projectile
const int HAUTEUR_CHARSET_PROJECTILE = 60;	 // Hauteur du charset projectile
const int LARGEUR_BLOC = 50;			 	 // Hauteur du bloc
const int HAUTEUR_BLOC = 50;				 // Largeur du bloc
const int LARGEUR_CHARSET_BLOC = 450;		 // Largeur du charset bloc
const int HAUTEUR_CHARSET_BLOC = 150;		 // Hauteur du charset bloc
const int LARGEUR_ENNEMI = 50;				 // Hauteur d’un ennemi
const int HAUTEUR_ENNEMI = 50;				 // Largeur d’un ennemi
const int LARGEUR_CHARSET_ENNEMI = 300;		 // Largeur du charset ennemi
const int HAUTEUR_CHARSET_ENNEMI = 200;		 // Hauteur du charset ennemi
const int LARGEUR_POTION = 30;				 // Hauteur de la potion de soin
const int HAUTEUR_POTION = 50;				 // Largeur de la potion de soin
const int LARGEUR_STAFF = 25;				 // Hauteur du staff
const int HAUTEUR_STAFF = 60;				 // Largeur du staff
const int LARGEUR_CHARSET_STAFF = 25;		 // Largeur du charset staff
const int HAUTEUR_CHARSET_STAFF = 300;		 // Hauteur du charset staff
const int VITESSE_PERSONNAGE = 1;			 // Vitesse de déplacement du personnage, horizontalement
const int VITESSE_PROJECTILE = 2;			 // Vitesse de déplacement d’un projectile, horizontalement
const int VITESSE_ENNEMI = 3;				 // Vitesse de déplacement d’un ennemi, horizontalement
const double GRAVITE = 9.81;				 // Constante de gravité
const double POINTS_DEGATS_EP = 2;			 // points de dégâts infligés à l’ennemi lorsqu’il est percuté par un projectile.
const double DEMI = 0.5;					 // gravité*temps depuis le début du saut divisé en deux.
//const double POINTS_DEGATS_ME = 0.1;		 // points de dégâts infligés au magicien lorsqu’il est percuté par un ennemi.




sprite wut;





//********************************* Fonctions du programme

//Cette fonction initialise SDL et créé la fenêtre du programme
bool init()
{
	//Cette variable indique si l'initialisation a été effectuée avec succès
	bool success = true;

	//Initialisation de SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Erreur lors de l'initialisation de SDL! - SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Création de la fenêtre du programme
		fenetreProgramme = SDL_CreateWindow("Titre fenetre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN);

		if (fenetreProgramme == NULL)
		{
			printf("Échec de création de la fenêtre ! -  SDL_Error %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Creation du 'renderer' en l'associant à la fenêtre du programme
			rendererFenetre = SDL_CreateRenderer(fenetreProgramme, -1, SDL_RENDERER_ACCELERATED);


			if (rendererFenetre == NULL)
			{
				printf("Échec de création du renderer ! - SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(rendererFenetre, 0xFF, 0xAA, 0xAA, 0xAA);

				//balleTexture.rendererFenetre = rendererFenetre;
				//barreGTexture.rendererFenetre = rendererFenetre;
				//barreMTexture.rendererFenetre = rendererFenetre;
				//barreDTexture.rendererFenetre = rendererFenetre;

				//Les commandes suivante permettent d'activer le chargement d'images dont le format est PNG
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("Échec d'initialisation de SDL_image ! -  SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}



//Cette fonction est utilisée pour charger les images du programme dans leurs textures correspondantes
bool loadMedia()
{
	////Cette variable indique si le chargément de l'élément a été effectué avec succès
	bool success = true;




	wut.set_renderer(rendererFenetre);
	wut.set_position(SDL_Point{ 25, 25 });
	std::cout << wut.chargerTexture("images/axzor_charset.png");
	wut.set_hauteur(80);
	wut.set_largeur(80);
	



	//

	////Load balle sprite texture
	//if (!magicienTexture.loadFromFile("images/axzor_charset.png"))
	//{
	//	printf("Échec de chargement de l'image ! \n");
	//	success = false;
	//}
	//else
	//{
	//	magicienRect.h = HAUTEUR_IMAGE_BALLE;
	//	magicienRect.w = LARGEUR_IMAGE_BALLE;
	//	magicienRect.x = 0;
	//	magicienRect.y = 0;
	//}

	////Load sprite barre G texture
	//if (!projectile::projectile_texture.loadFromFile("images/projectile.png"))
	//{
	//	printf("Échec de chargement de l'image ! \n");
	//	success = false;
	//}
	//else
	//{
	//	barreGRect.h = HAUTEUR_IMAGE_BARRE_G;
	//	barreGRect.w = LARGEUR_IMAGE_BARRE_G;
	//	barreGRect.x = 0;
	//	barreGRect.y = 0;
	//}

	////Load sprite barre M texture
	//if (!barreMTexture.loadFromFile("images/barreMilieu.png"))
	//{
	//	printf("Échec de chargement de l'image ! \n");
	//	success = false;
	//}
	//else
	//{
	//	barreMRect.h = HAUTEUR_IMAGE_BARRE_M;
	//	barreMRect.w = LARGEUR_IMAGE_BARRE_M;
	//	barreMRect.x = 0;
	//	barreMRect.y = 0;
	//}

	////Load sprite barre D texture
	//if (!barreDTexture.loadFromFile("images/barreDroite.png"))
	//{
	//	printf("Échec de chargement de l'image ! \n");
	//	success = false;
	//}
	//else
	//{
	//	barreDRect.h = HAUTEUR_IMAGE_BARRE_D;
	//	barreDRect.w = LARGEUR_IMAGE_BARRE_D;
	//	barreDRect.x = 0;
	//	barreDRect.y = 0;
	//}

	//
	return success;
}



//Cette fonction effectue une fermeture appropriée du programme, de l'environnement SDL et libère la mémoire des différents éléments SDL créés
void close()
{

	//On détruit les LTextures créées dans le programme
	//balleTexture.free();
	//barreGTexture.free();
	//barreMTexture.free();
	//barreDTexture.free();


	//Destroy window
	SDL_DestroyRenderer(rendererFenetre);
	SDL_DestroyWindow(fenetreProgramme);
	fenetreProgramme = NULL;
	rendererFenetre = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


//Cette fonction est responsable de charger dans une texture l'image indiqueé en paramètre
SDL_Texture* loadTexture(std::string path)
{
	//La texture finale
	SDL_Texture* newTexture = NULL;

	//Chargement de l'image dans la texture
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Échec de chargement de l'image dans la texture ! -  SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(rendererFenetre, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}



//Fonction principale du programme
int main(int argc, char* args[])
{



	//********VARIABLES*********\\

	SDL_Event e;        //Cette variable nous permet de détecter l'événement courant que le programme doit gérer (click, touche du clavier, etc.)

	bool quit = false;  //flag pour la boucle principale. Elle permet de déterminer si l'on doit quitter le programme
	//DÉCLARATION DES CHARSETS


	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			printf("Programme OK!\n");

			//Netoyer l'écran (Clear Screen)
			SDL_RenderClear(rendererFenetre);

			//Il est possible de définir une couleur de background du 'renderer'
			SDL_SetRenderDrawColor(rendererFenetre, 0xFF, 0xCC, 0xCC, 0xCC);




			//Mise à jour de 'rendererFenetre' (on redessine les images (contenues dans leurs textures) dans le renderer)
			SDL_RenderPresent(rendererFenetre);


			//Le programme reste ouvert tant que quit != true 
			while (!quit)
			{
				//SDL_get_keyboardstate
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//Si l'utilisateur appuiie sur le bouton 'fermer' de la fenêtre
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Si l'utilisateur fait un click de souris			//<--Utile pour le debug (reset)
					else if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						//quit = true;

					}

					//Si une touche du clavier a été appuyée
					else if (e.type == SDL_KEYDOWN)
					{

						//Avec ce switch on indique qoui faire lorsque l'utilisateur appuie sur une touche
						switch (e.key.keysym.sym)
						{
						case SDLK_s:  //La touche 's' a été appuyée
							//Lancer le staff (Attaque neutre)
							break;

						case SDLK_d:  ////La touche 'd' a été appuyée
							//Tirer (projectiles élémentaux)
							break;

						case SDLK_UP:
							//sauter
							break;

						case SDLK_DOWN:
							//pencher
							break;

						case SDLK_LEFT:
							//Aller à gauche
							break;

						case SDLK_RIGHT:
							//Aller à droite
							break;

						default:
							break;
						}//end switch
					}//end else if (e.type == SDL_KEYDOWN)
				}//end while (SDL_PollEvent(&e) != 0)


				//Clear screen
			/*	SDL_RenderClear(rendererFenetre);*/

				//*************RENDER DES TRUCS***************\\
										//hommeTexture.render(positionHommeX, positionHommeY, currentHommeRect);

				//render des blocs		<-- Utile pour le render des blocs du décors
				//for (int i = 0; i < 15; ++i)
				//	for (int j = 0; j < 15; ++j)
				//	{
				//		//Pour plus de clareté en bas
				//		int bX = blocs[i][j].x; // la coordonnée en x du bloc
				//		int bY = blocs[i][j].y; // la coordonnée en y du bloc

				//		blocs[i][j].blocTexture.render(bX,bY,&blocs[i][j].getRect());
				//	}





				wut.render();

				//Update screen
				SDL_RenderPresent(rendererFenetre);



				//SDL_Delay(10);   <--- (délais)

			}//end while (!quit)
		}
	}

	//system("pause");

	//Free resources and close SDL
	close();

	return 0;

}


void charger_niveau(const char nom_fichier[30], std::vector< std::vector<sprite> > &niveau)
{
	std::ifstream entree; //Le flux d,entree
	char lettre_actuelle; //La lettre actuellement traitee
	int index_ligne = 0; //La lettre sur la ligne

	if (testFichierExiste(nom_fichier)){
		if (testFichierVide(nom_fichier))	//Teste si le fichier existe et qu'il n'est pas vide avant tout
		{
			entree.open(nom_fichier); //ouverture du fichier
			
			// Variables contenant les dimensions duu niveau
			int nb_lignes = 0;
			int largeur_ligne = 0;

			// Variables temporaires pour créer de noyuvelles lignes, lettres, sprites vides

			std::vector<sprite> nouvelle_ligne;
			sprite sprite_vide;
			magicien axzor;
			SDL_Point point;


			// Lire les dimensions du niveau
			entree >> largeur_ligne;
			entree >> nb_lignes;

			//Pour chaque ligne du fichier
			for (int ligne = 0; ligne < nb_lignes; ++ligne)
			{
				//Ajouter une nouvelle ligne
				niveau.push_back(nouvelle_ligne);

				//Pour chaque lettre de cette ligne
				for (int lettre = 0; lettre < largeur_ligne; ++lettre)
				{
					//Lire la lettre
					entree.get(lettre_actuelle);

					//Interpréter la lettre

					//vide: _
					//bloc vide délimitation = .
					//bloc vide "espace réservé" = :
					//magicien = m
					//ennemi feu droite = F
					//ennemi feu gauche = f
					//ennemi eau droite = E
					//ennemi eau gauche = e
					//ennemi terre droite = T
					//ennemi terre gauche = t
					//ennemi foudre droite = V
					//ennemi foudre gauche = v
					//staff feu = !
					//staff eau = @
					//staff terre = £
					//staff foudre = $
					//bloc centre = 5
					//bloc haut gauche = 7
					//bloc haut centre = 8
					//bloc haut droite = 9
					//bloc droite = 6
					//bloc bas droite = 3
					//bloc bas = 2
					//bloc bas gauche = 1
					//bloc gauche = 4
					//potion = P

					switch (lettre_actuelle)
					{



					case'_':
						//vide
						niveau.at(ligne).push_back(sprite_vide);
						break;

					case'.':
						//bloc vide délimitation



						break;

					case':':
						//bloc vide "espace réservé"
						niveau.at(ligne).push_back(sprite_vide);
						break;

					case 'm':
						//Le magicien

						//Prendre sa position
						point.x = lettre * LARGEUR_BLOC;
						point.y = ligne * HAUTEUR_BLOC;
						axzor.set_position(point);

						//Placer le magicien dans le vecteur
						niveau.at(ligne).push_back(axzor);
						break;

					case'F':
						//ennemi feu droite
						break;

					case'f':
						//ennemi feu gauche
						break;

					case'E':
						//ennemi eau droite
						break;

					case'e':
						//ennemi eau gauche
						break;

					case'T':
						//ennemi terre droite
						break;

					case't':
						//ennemi terre gauche
						break;

					case'V':
						//ennemi foudre droite
						break;

					case'v':
						//ennemi foudre gauche
						break;

					case'!':
						//staff feu
						break;

					case'@':
						//staff eau
						break;

					case'£':
						//staff terre
						break;

					case'$':
						//staff foudre
						break;

					case'5':
						//bloc centre
						break;

					case'7':
						//bloc haut gauche
						break;

					case'8':
						//bloc haut centre
						break;

					case'9':
						//bloc haut droite
						break;

					case'6':
						//bloc droite
						break;

					case'3':
						//bloc bas droite
						break;

					case'2':
						//bloc bas
						break;

					case'1':
						//bloc bas gauche
						break;

					case'4':
						//bloc gauche
						break;

					case'P':
						//potion
						break;



					default:
						//Sinon, insérer le caractère comme étant un sprite vide
						niveau.at(ligne).push_back(sprite_vide);
						break;
					}

					std::cout << lettre_actuelle;
				}
				entree.get(lettre_actuelle); //ignorer le retour à la ligne
				std::cout << lettre_actuelle;
			}


			entree.close(); //fermeture du fichier
		}
		else //Si le fichier est vide
		{
			std::cout << "Le fichier " << nom_fichier << " est vide!" << std::endl;
		}
	}
	else //Si le fichier n'existe pas
	{
		std::cout << "Le fichier " << nom_fichier << " n'existe pas!" << std::endl;
	}


}


bool testFichierExiste(const char nomFichier[30])
{
	std::ifstream fichier(nomFichier);
	if (fichier.good()){ fichier.close(); return true; }
	else{ fichier.close(); return false; }
}

bool testFichierVide(const char nomFichier[30])
{
	bool sortie = false; //variable de sortie
	std::ifstream fichier(nomFichier); //ouvrir le fichier
	fichier.seekg(0, fichier.end); //aller a la fin
	if (fichier.tellg() > 0) sortie = true; // si le nb de caractères est superieur a zero, retourner vrai
	fichier.close(); //fermer le fichier
	return sortie;
}









void ApparaitreProjectile(std::vector<projectile> &vecteurProjectile, char type){
//
//
//	//vecteurProjectile.push_back(projectile(SDL_Rect{ 0, 0, TAILLE_PROJECTILE_X, TAILLE_PROJECTILE_Y }), rendererFenetre, type);		//Largeur de la fenêtre / 2 parce que la position en x de la balle sera toujours le centre de l'axe des x
//
}

