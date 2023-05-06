#ifndef BCKG1_H_
#define BCKG1_H_
#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "perso1.h"

typedef struct 
{
	image o;
	int off;
}objet;

typedef struct
{
	int score;
	int temps;
	char playerName[20];
}ScoreInfo;
void initBack(Background *b);
void animerBack(Background *b,SDL_Surface *screen,int time,int nb);
void afficherBack(Background b,SDL_Surface *screen,int time,int on,personne p1,personne p2,int nb);
void scrolling(Background *b, personne p1,personne p2 ) ;
#endif
