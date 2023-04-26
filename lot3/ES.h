#ifndef _ES_H_
#define _ES_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <time.h>


enum state_es{move,run,attack,dead};
typedef struct
{
enum state_es state;
SDL_Rect pos;
SDL_Rect sprite;
int vie;
SDL_Surface *image;
int sprite_count[4];
int sprite_n;
int d;
int speed;
}ES;

typedef struct
{
SDL_Surface *image;
SDL_Rect pos;
int afficher;
char type[10];
}objet;

void init_es(ES *p);
void init_key(objet *o);
void init_energy(objet *o);
void init_spoon(objet *o);
void afficher_es(ES p,SDL_Surface *screen);
void afficher_objet(objet o, SDL_Surface * screen);
void animer_es(ES *p);
void mouvement_aleatoire(ES *p);
void mouvement_aleatoire2(ES *p);
void mouvement_aleatoire3(ES *p);

#endif
