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
//les images
SDL_Rect pos_img1_affiche;
SDL_Rect pos_img1_ecran;
SDL_Surface *img1;
SDL_Rect pos_img2_affiche;
SDL_Rect pos_img2_ecran;
SDL_Surface *img2;
SDL_Rect pos_img3_affiche;
SDL_Rect pos_img3_ecran;
SDL_Surface *img3;
//entier
int T[9],j1,Tour;
//texte
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}tic;
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
typedef struct {
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;
//affichage image
void init_image(image *Masque);
void init_image1(image *Masque2);
void afficher_image(SDL_Surface *screen, image imge);
//tic 
void initialiserTic(tic *t);
void afficherTic (tic t , SDL_Surface *screen);
void afficher_texte(tic t,SDL_Surface *screen);
//temps
void initialiser_temps(temps *T);
void afficher_temps(temps *T,SDL_Surface *screen);
//liberation 
void liberer (tic t);
#endif
