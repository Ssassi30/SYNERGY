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
#include "perso.h"

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
//bck
void initBack(Background *b);
void animerBack(Background *b,SDL_Surface *screen, int time);
void afficherBack(Background b,SDL_Surface *screen,int time,int on,personne p);
void scrolling(Background *b,int direction , personne p,int c,int col);
//obj
void initobj(objet obj[]);
void afficherobj(Background *b,objet obj[],SDL_Surface *screen);
int box(SDL_Rect x1,SDL_Rect x2);
//score
void initialiser_textep(texte *txte);
void initialiser_texteee(texte *txte);
void saisienomjoueur(ScoreInfo *s,SDL_Surface * screen);
//void tryy(ScoreInfo *s);
void saveScore(ScoreInfo s,char *fileName);
void bestScore(char *filename,ScoreInfo t[]);
void afficherBest(ScoreInfo t[],SDL_Surface *screen,texte txte);

void liberer_musiquebref(Mix_Chunk* mus);
void libererBack(Background b,texte txte);
#endif
