/* En-t�te du programme
*****************************************
Fichier :			main.cpp
Auteur:				Guillaume Bergs & Shawn Corriveau
Date de cr�ation :  2016/01/01
Description :		Fonction principale du jeu Barkanoid
Commentaires :
*****************************************/


//*************************************** D�clarations pr�-processeur
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

//***************************************** Prototypes
bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string path);
void charger_niveau(const char[], std::vector< std::vector<sprite> > &niveau);
bool testFichierExiste(const char[]);
bool testFichierVide(const char[]);


//********************************* Variables globales (partie 1)

//La fen�tre dans laquelle le programme sera ex�cut�
SDL_Window* fenetreProgramme = NULL;

//Le 'renderer' associ� � la fen�tre du programme. Le 'renderer' est l'endroit dans lequelle on placera des textures
SDL_Renderer* rendererFenetre = NULL;

//***********************************


//***********************************//CONSTANTES//*************************************//
const int TAILLE_PROJECTILE_X = 25;
const int TAILLE_PROJECTILE_Y = 15;

sprite wut;






//********************************* Fonctions du programme

//Cette fonction initialise SDL et cr�� la fen�tre du programme
bool init()
{
	//Cette variable indique si l'initialisation a �t� effectu�e avec succ�s
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

		//Cr�ation de la fen�tre du programme
		fenetreProgramme = SDL_CreateWindow("Titre fenetre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN);

		if (fenetreProgramme == NULL)
		{
			printf("�chec de cr�ation de la fen�tre ! -  SDL_Error %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Creation du 'renderer' en l'associant � la fen�tre du programme
			rendererFenetre = SDL_CreateRenderer(fenetreProgramme, -1, SDL_RENDERER_ACCELERATED);


			if (rendererFenetre == NULL)
			{
				printf("�chec de cr�ation du renderer ! - SDL Error: %s\n", SDL_GetError());
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
					printf("�chec d'initialisation de SDL_image ! -  SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}



//Cette fonction est utilis�e pour charger les images du programme dans leurs textures correspondantes
bool loadMedia()
{
	//Cette variable indique si le charg�ment de l'�l�ment a �t� effectu� avec succ�s
	bool success = true;


	wut.set_renderer(rendererFenetre);
	wut.set_position(SDL_Point{ 25, 25 });
	std::cout << wut.chargerTexture("images/axzor_charset.png");
	wut.set_hauteur(80);
	wut.set_largeur(80);






	/*

	//Load balle sprite texture
	if (!magicienTexture.loadFromFile("images/axzor_charset.png"))
	{
		printf("�chec de chargement de l'image ! \n");
		success = false;
	}
	else
	{
		magicienRect.h = HAUTEUR_IMAGE_BALLE;
		magicienRect.w = LARGEUR_IMAGE_BALLE;
		magicienRect.x = 0;
		magicienRect.y = 0;
	}

	//Load sprite barre G texture
	if (!barreGTexture.loadFromFile("images/barreGauche.png"))
	{
		printf("�chec de chargement de l'image ! \n");
		success = false;
	}
	else
	{
		barreGRect.h = HAUTEUR_IMAGE_BARRE_G;
		barreGRect.w = LARGEUR_IMAGE_BARRE_G;
		barreGRect.x = 0;
		barreGRect.y = 0;
	}

	//Load sprite barre M texture
	if (!barreMTexture.loadFromFile("images/barreMilieu.png"))
	{
		printf("�chec de chargement de l'image ! \n");
		success = false;
	}
	else
	{
		barreMRect.h = HAUTEUR_IMAGE_BARRE_M;
		barreMRect.w = LARGEUR_IMAGE_BARRE_M;
		barreMRect.x = 0;
		barreMRect.y = 0;
	}

	//Load sprite barre D texture
	if (!barreDTexture.loadFromFile("images/barreDroite.png"))
	{
		printf("�chec de chargement de l'image ! \n");
		success = false;
	}
	else
	{
		barreDRect.h = HAUTEUR_IMAGE_BARRE_D;
		barreDRect.w = LARGEUR_IMAGE_BARRE_D;
		barreDRect.x = 0;
		barreDRect.y = 0;
	}

	*/
	return success;
}



//Cette fonction effectue une fermeture appropri�e du programme, de l'environnement SDL et lib�re la m�moire des diff�rents �l�ments SDL cr��s
void close()
{

	//On d�truit les LTextures cr��es dans le programme
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


//Cette fonction est responsable de charger dans une texture l'image indique� en param�tre
SDL_Texture* loadTexture(std::string path)
{
	//La texture finale
	SDL_Texture* newTexture = NULL;

	//Chargement de l'image dans la texture
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("�chec de chargement de l'image dans la texture ! -  SDL_image Error: %s\n", path.c_str(), IMG_GetError());
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
	
	

	std::vector< std::vector<sprite> > level; // Le niveau lui-m�me




	//CHARGER LE NIVEAU
	charger_niveau("levels/lvl1.axz", level );
	system("pause");








	SDL_Event e;        //Cette variable nous permet de d�tecter l'�v�nement courant que le programme doit g�rer (click, touche du clavier, etc.)

	bool quit = false;  //flag pour la boucle principale. Elle permet de d�terminer si l'on doit quitter le programme
	//D�CLARATION DES CHARSETS


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

			//Netoyer l'�cran (Clear Screen)
			SDL_RenderClear(rendererFenetre);

			//Il est possible de d�finir une couleur de background du 'renderer'
			SDL_SetRenderDrawColor(rendererFenetre, 0xFF, 0xCC, 0xCC, 0xCC);




			//Mise � jour de 'rendererFenetre' (on redessine les images (contenues dans leurs textures) dans le renderer)
			SDL_RenderPresent(rendererFenetre);


			//Le programme reste ouvert tant que quit != true 
			while (!quit)
			{
				//SDL_get_keyboardstate
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//Si l'utilisateur appuiie sur le bouton 'fermer' de la fen�tre
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Si l'utilisateur fait un click de souris			//<--Utile pour le debug (reset)
					else if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						//quit = true;

					}

					//Si une touche du clavier a �t� appuy�e
					else if (e.type == SDL_KEYDOWN)
					{

						//Avec ce switch on indique qoui faire lorsque l'utilisateur appuie sur une touche
						switch (e.key.keysym.sym)
						{
						case SDLK_s:  //La touche 's' a �t� appuy�e
							//Lancer le staff (Attaque neutre)
							break;

						case SDLK_d:  ////La touche 'd' a �t� appuy�e
							//Tirer (projectiles �l�mentaux)
							break;

						case SDLK_UP:
							//sauter
							break;

						case SDLK_DOWN:
							//pencher
							break;

						case SDLK_LEFT:
							//Aller � gauche
							break;

						case SDLK_RIGHT:
							//Aller � droite
							break;

						default:
							break;
						}//end switch
					}//end else if (e.type == SDL_KEYDOWN)
				}//end while (SDL_PollEvent(&e) != 0)


				//Clear screen
				SDL_RenderClear(rendererFenetre);

				//*************RENDER DES TRUCS***************\\
										//hommeTexture.render(positionHommeX, positionHommeY, currentHommeRect);

				//render des blocs		<-- Utile pour le render des blocs du d�cors
				//for (int i = 0; i < 15; ++i)
				//	for (int j = 0; j < 15; ++j)
				//	{
				//		//Pour plus de claret� en bas
				//		int bX = blocs[i][j].x; // la coordonn�e en x du bloc
				//		int bY = blocs[i][j].y; // la coordonn�e en y du bloc

				//		blocs[i][j].blocTexture.render(bX,bY,&blocs[i][j].getRect());
				//	}


				//Update screen
				SDL_RenderPresent(rendererFenetre);



				//SDL_Delay(10);   <--- (d�lais)

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

			int nb_lignes =0;
			int largeur_ligne =0;

			entree >> largeur_ligne;
			entree >> nb_lignes;
			

			for (int ligne = 0; ligne < nb_lignes; ++ligne)
			{
				for (int lettre = 0; lettre < largeur_ligne; ++lettre)
				{
					 entree.get(lettre_actuelle);

					 std::cout << lettre_actuelle;
				}
				entree.get(lettre_actuelle); //ignorer le retour � la ligne
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
	if (fichier.tellg() > 0) sortie = true; // si le nb de caract�res est superieur a zero, retourner vrai
	fichier.close(); //fermer le fichier
	return sortie;
}
