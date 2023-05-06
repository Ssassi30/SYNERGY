#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perso1.h"
typedef struct 
{
	char *url;
	SDL_Surface *img;
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran;
	SDL_Surface *img2;
	SDL_Rect pos_img2_affiche;
	SDL_Rect pos_img2_ecran;
	image T[4];
}minimap;
typedef struct 
{
	SDL_Surface *texte;
	SDL_Rect position; 
	TTF_Font *police ;
	char entree[100];
	int secondesEcoulees;
	SDL_Color couleurBlanche;
	time_t t1,t2;
	int min, sec;
}temps;
//animation
void initmap(minimap *m);
void animerMinimap (minimap *m);
//affichage de l'image
void afficherminimap(SDL_Surface *screen , minimap m);
void afficher_animation(SDL_Surface *screen , minimap m);
void afficheranimationENIGME(SDL_Surface *screen , image a);
//liberation d 'image
void liberer_minimap(minimap m);
void liberer_animation(minimap m);
//texte 
void initialiser_textee(texte *txte);
//void liberer_texte(texte txte);
//mouvement 
void avancer( minimap *m);
void reculer (minimap *m);
void avancerY( minimap *m);
void reculerY (minimap *m);
void obs(minimap *m);
//temps
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen,int nb);
void free_temps(temps *t,SDL_Surface *screen);
//collision
void initialiser_Masque(image Masque[]);
SDL_Color GetPixel(SDL_Surface *img, int x ,int y);
int collisionPP(SDL_Rect perso ,SDL_Surface *img);
/*int collisionPP2(personne  p ,SDL_Surface *img);
int collisionPP3(personne  p ,SDL_Surface *screen);
int collisionPP4(personne  p ,SDL_Surface *screen);*/
//audio 
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
#endif
