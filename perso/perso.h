#ifndef PERSO_H
#define PERSO_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#define SCREEN_H 410
#define SCREEN_W 640
		typedef struct 
	{ 
		SDL_Rect pos_img_ecran,pos_img_affiche;
		SDL_Surface *img_url;
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
		
	}personne;
typedef struct 
	{
		SDL_Surface *txt;
		SDL_Rect pos_txt;
		SDL_Colour color_txt;
		TTF_Font *police;
	}texte;
/***********************************bgk********************************************/
void initialiser_imageBACK(image *imge);
void initialiser_imageBTN(image *imgbtn,char *name,int x,int y); //vie score
void afficher_image(SDL_Surface *screen, image imge);
void liberer_image(image imge);
/*******************************************************************************/
void init_perso(personne *p , int xi , int yi);
void afficherPerso(personne p, SDL_Surface *screen);
void deplacerPerso(personne *p, Uint32 dt);
void animerPerso(personne *p);
void saut(personne* p, int posx_absolu, int posy_absolu);
/********************************************TEXTE***********************************/

void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen , texte txte,personne p);
void liberer_texte(texte txte);
#endif
