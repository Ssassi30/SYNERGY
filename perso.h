#ifndef PERSO_H
#define PERSO_H
#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 410
#define SCREEN_W 640

typedef struct
{
	SDL_Surface *url;
	SDL_Rect pos_img_affiche;//partie de l'image qui doit etre affichee
	SDL_Rect pos_img_ecran;//position de l'image par rapport l'ecran
	SDL_Surface *img;
}image;

		typedef struct 
	{ 
		SDL_Surface *mat[4][4];
		SDL_Rect screen_pos;
		SDL_Rect saut;
		SDL_Rect size;
		int espace;
		int direction;
		int num;
		int vie;
		int score;
		double vitesse;
		double acceleration;
		int detection_acceleration;
		int pas;
		
	}personne;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
	int s,m,h;
}texte;
typedef struct 
{
	int stage;
	image imagebckg[3][20];
	Mix_Music* musicbckg[4];
	SDL_Rect camera_pos;
	int direction;
}Background;
void initialiser_imageBTN(image *imgbtn,char *name,int x,int y); //vie score
void afficher_image(SDL_Surface *screen, image imge);
void liberer_image(image imge);
/*******************************************************************************/
void init_perso(personne *p);
void afficherPerso(personne p, SDL_Surface *screen);
//void deplacer_perso(personne* p, int dx, int dy);
void deplacerPerso(personne *p, Uint32 dt,Background b,int c);
void animerPerso(personne *p);
//void jump(personne* p, int dt, int posinit);
void saut(personne* p, int posx_absolu, int posy_absolu);
/********************************************TEXTE***********************************/

void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen , texte txte,personne p);
void liberer_texte(texte txte);
#endif
