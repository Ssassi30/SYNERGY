#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	SDL_Surface *url;
	SDL_Rect pos_img_affiche;//partie de l'image qui doit etre affichee
	SDL_Rect pos_img_ecran;//position de l'image par rapport l'ecran
	SDL_Surface *img;
}image;
typedef struct
{
	SDL_Surface *txt ;
	SDL_Rect pos_txt;
	SDL_Color color_txt;
	TTF_Font *police;
}texte;
typedef struct 
{
	image imge;
	int q,r;
}lettre;
typedef struct
{
	SDL_Surface *texte;
	SDL_Rect position;
	TTF_Font *police ;
	char entree[100];
	int secondesEcoulees;
	SDL_Color couleur;
	time_t t1,t2;
	int min, sec;
}temps;
typedef struct 
{
	image base[4];
	lettre l[10];
	int resolu;
	SDL_Rect pos[10];
}enigme1;
typedef struct 
{
	char question[20];
	char rep1[20],rep2[20],rep3[20];
	int numbr;
	SDL_Surface *imgq, *imgrep1 , *imgrep2 , *imgrep3;
	SDL_Rect pos_img_ecranq,pos_img_ecranrep1,pos_img_ecranrep2,pos_img_ecranrep3;
	int etat;
}enigme2;
void initenigme1(enigme1 *e);
void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *screen);
void animerenigme1(enigme1 e,SDL_Surface *screen,int time);
void afficherenigme1(enigme1 e,SDL_Surface *screen,int time);
int gagne1(enigme1 e);
void generer(enigme2 *e,char *nomfich);
void afficherEnigme2(enigme2 e,SDL_Surface *screen);








#endif
