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
#include "perso1.h"
#include "minimap.h"
typedef struct 
{
	image anim[5];
	image bm[4][2];
	int onm;
}menu;
typedef struct 
{
	texte txte[3];
	image op;
	image bo[4][2];
	image v[5];
	image re[2];
	int ono,onv;
}option;
typedef struct 
{
	image sc;
	image re[2];
	texte txte;
	int m,c;	
}score;
typedef struct 
{
	image pl;
	image re[2];
	image bp[2][2];
	int onp;
	int nb;
}play;
typedef struct 
{
	image qu;
	image bq[2][2];
	int onq;
}quit;
void initialiser_texte(texte *txte);
void initialisermenu(menu *m,option *o, play *p, quit *q,score *s);
void affichermenu(menu *m,option *o, play *p, quit *q,score *s,SDL_Surface *screen,temps *t,int *niveau,int key[],int *boucle,int *on);
void initialiser_audiobref(Mix_Chunk* mus);
void initialiser_audio(Mix_Music* music);



#endif
