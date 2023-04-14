#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCREEN_H 1000
#define SCREEN_W 1000
typedef struct {
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;
typedef struct {
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
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
int s,m,h;
}texte;
typedef struct temps
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
//initialisation image 
void initialiser_imageBACK(image *image);
void initmap(minimap *m);
void animerMinimap (minimap *m);
//affichage de l'image
void afficher_imageBACK(SDL_Surface *screen , image imge);
void afficherminimap(SDL_Surface *screen , minimap m);
void afficher_animation(SDL_Surface *screen , minimap m);
void afficheranimationENIGME(SDL_Surface *screen , image a);
//liberation d 'image
void liberer_image(image imge);
void liberer_minimap(minimap m);
void liberer_animation(minimap m);
//texte 
void initialiser_texte(texte *txte);
void liberer_texte(texte txte);
//mouvement 
void avancer( minimap *m);
void reculer (minimap *m);
void avancerY( minimap *m);
void reculerY (minimap *m);
void obs(minimap *m);
//temps
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen);
void free_temps(temps *t,SDL_Surface *screen);
//collision
void initialiser_Masque(image *Masque);
SDL_Color GetPixel(SDL_Surface *Masque, int x ,int y);
int collisionPP(minimap m ,SDL_Surface *Masque);
//audio 
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
#endif
