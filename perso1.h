#ifndef PERSO1_H
#define PERSO1_H
#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Surface *url;
	SDL_Rect pos_img_affiche;//partie de l'image qui doit etre affichee
	SDL_Rect pos_img_ecran;//position de l'image par rapport l'ecran
	SDL_Surface *img;
}image;

typedef struct 
{ 
	SDL_Surface *mat[4][4],*stop;
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
	Mix_Chunk* musbckg[5];
	SDL_Rect camera_pos1;
	SDL_Rect camera_pos2;
	SDL_Rect posEcran1;
	SDL_Rect posEcran2;
	int direction1,direction2;
}Background;
enum state_es{move,run,attack,dying,dead};
typedef struct
{
	enum state_es state;
	SDL_Rect pos;
	SDL_Rect sprite;
	int vie;
	SDL_Surface *image;
	int sprite_count[4];
	int sprite_n;//current sprite
	int d;//direction
	int speed;
	image entite[2][4];
}ES;
typedef struct
{
	SDL_Rect perso1,perso2,police1,police2,cam2;
}cadre;
void init_perso(personne *p );
void init_perso2(personne *p );
void afficherPerso(personne p, SDL_Surface *screen);
void deplacerPerso(personne *p);
void animerPerso(personne *p);
void saut(personne* p, int posx_absolu, int posy_absolu,int key[]) ;
#endif
