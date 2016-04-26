#include "sprite.h"
#include "visuel.h"

//
//
//bool init()
//{
//	//Cette variable indique si l'initialisation a été effectuée avec succès
//	bool success = true;
//
//	//Initialisation de SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("Erreur lors de l'initialisation de SDL! - SDL Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else
//	{
//		//Set texture filtering to linear
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
//		{
//			printf("Warning: Linear texture filtering not enabled!");
//		}
//
//		//Création de la fenêtre du programme
//		fenetreProgramme = SDL_CreateWindow("Titre fenetre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN);
//
//		if (fenetreProgramme == NULL)
//		{
//			printf("Échec de création de la fenêtre ! -  SDL_Error %s\n", SDL_GetError());
//			success = false;
//		}
//		else
//		{
//			//Creation du 'renderer' en l'associant à la fenêtre du programme
//			rendererFenetre = SDL_CreateRenderer(fenetreProgramme, -1, SDL_RENDERER_ACCELERATED);
//
//
//			if (rendererFenetre == NULL)
//			{
//				printf("Échec de création du renderer ! - SDL Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else
//			{
//				//Initialize renderer color
//				SDL_SetRenderDrawColor(rendererFenetre, 0xFF, 0xAA, 0xAA, 0xAA);
//
//				balleTexture.rendererFenetre = rendererFenetre;
//				barreGTexture.rendererFenetre = rendererFenetre;
//				barreMTexture.rendererFenetre = rendererFenetre;
//				barreDTexture.rendererFenetre = rendererFenetre;
//
//				//Les commandes suivante permettent d'activer le chargement d'images dont le format est PNG
//				int imgFlags = IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags))
//				{
//					printf("Échec d'initialisation de SDL_image ! -  SDL_image Error: %s\n", IMG_GetError());
//					success = false;
//				}
//			}
//		}
//	}
//
//	return success;
//}
//
//class LTexture
//{
//public:
//	//Initializes variables
//	LTexture();
//	LTexture(SDL_Renderer *renderer);
//
//
//	//Deallocates memory
//	~LTexture();
//
//	//Loads image at specified path
//	bool loadFromFile(std::string path);
//
//	//Deallocates texture
//	void free();
//
//	//Set color modulation
//	void setColor(Uint8 red, Uint8 green, Uint8 blue);
//
//	//Set blending
//	void setBlendMode(SDL_BlendMode blending);
//
//	//Set alpha modulation
//	void setAlpha(Uint8 alpha);
//
//	//Renders texture at given point
//	void render(int x, int y, SDL_Rect* clip = NULL);
//	void render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
//
//	//Gets image dimensions
//	int getWidth();
//	int getHeight();
//
//	//Renderer
//	SDL_Renderer *rendererFenetre;
//private:
//	//The actual hardware texture
//	SDL_Texture* mTexture;
//
//	//Image dimensions
//	int mWidth;
//	int mHeight;
//};
//
//LTexture::LTexture()
//{
//	//Initialize
//	mTexture = NULL;
//	mWidth = 0;
//	mHeight = 0;
//	rendererFenetre = NULL;
//}
//
//LTexture::LTexture(SDL_Renderer *renderer)
//{
//	//Initialize
//	mTexture = NULL;
//	mWidth = 0;
//	mHeight = 0;
//	rendererFenetre = renderer;
//}
//
//LTexture::~LTexture()
//{
//	//Deallocate
//	free();
//}
//
//bool LTexture::loadFromFile(std::string path)
//{
//	//Get rid of preexisting texture
//	free();
//
//	//The final texture
//	SDL_Texture* newTexture = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else
//	{
//		//Color key image
//		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
//
//		//Create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface(rendererFenetre, loadedSurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//		else
//		{
//			//Get image dimensions
//			mWidth = loadedSurface->w;
//			mHeight = loadedSurface->h;
//		}
//
//		//Get rid of old loaded surface
//		SDL_FreeSurface(loadedSurface);
//	}
//
//	//Return success
//	mTexture = newTexture;
//	return mTexture != NULL;
//}
//
//void LTexture::free()
//{
//	//Free texture if it exists
//	if (mTexture != NULL)
//	{
//		SDL_DestroyTexture(mTexture);
//		mTexture = NULL;
//		mWidth = 0;
//		mHeight = 0;
//	}
//}
//
//void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
//{
//	//Modulate texture rgb
//	SDL_SetTextureColorMod(mTexture, red, green, blue);
//}
//
//void LTexture::setBlendMode(SDL_BlendMode blending)
//{
//	//Set blending function
//	SDL_SetTextureBlendMode(mTexture, blending);
//}
//
//void LTexture::setAlpha(Uint8 alpha)
//{
//	//Modulate texture alpha
//	SDL_SetTextureAlphaMod(mTexture, alpha);
//}
//
//void LTexture::render(int x, int y, SDL_Rect* clip)
//{
//	//Set rendering space and render to screen
//	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
//
//	//Set clip rendering dimensions
//	if (clip != NULL)
//	{
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//
//	//Render to screen
//	SDL_RenderCopy(rendererFenetre, mTexture, clip, &renderQuad);
//}
//
//void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
//{
//	//Set rendering space and render to screen
//	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
//
//	//Set clip rendering dimensions
//	if (clip != NULL)
//	{
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//
//	//Render to screen
//	SDL_RenderCopyEx(rendererFenetre, mTexture, clip, &renderQuad, angle, center, flip);
//}
//
//
//int LTexture::getWidth()
//{
//	return mWidth;
//}
//
//int LTexture::getHeight()
//{
//	return mHeight;
//}







sprite::sprite()
{
	_position_x = 0;
	_position_y = 0;
	_type = 0;
	_direction = 0;
}


sprite::~sprite()
{
}


int sprite::get_x()
{
	return 0;
}


int sprite::get_y()
{
	return 0;
}


SDL_Rect sprite::get_rect()
{
	return SDL_Rect();
}


void sprite::set_x(int x)
{
}


void sprite::set_y(int y)
{
}


void sprite::set_renderer(renderer render)
{



}


void sprite::sauter()
{
}


void sprite::avancer()
{
}


bool sprite::collision()
{
	return false;
}
