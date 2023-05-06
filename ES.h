#ifndef _ES_H_
#define _ES_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "perso1.h"
void init_es(ES *p);
/*void init_key(image o[]);
void init_energy(objet *o);
void init_spoon(objet *o);*/
void afficher_es(ES p,SDL_Surface *screen,int t,int stage);
//void afficher_objet(image o[], SDL_Surface * screen,Background b);
void mouvement_aleatoire(ES *p);
void mouvement_aleatoire2(ES *p);

#endif
