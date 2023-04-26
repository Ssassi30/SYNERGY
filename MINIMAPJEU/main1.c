#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction1.h"
int main ()
{
Mix_Music *music;
Mix_Chunk *mus;
SDL_Surface *screen;
image IMAGE,Masque;
texte txte,police;
minimap m,m1;
SDL_Event event;
char nom[100],temps1[100];
temps t,t3;
char c[1];
int R,i=0,boucle=1,temps,somme=0,s;
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)
{
printf("Could not initialize SDL : %s. \n", SDL_GetError());
return -1;
}
screen=SDL_SetVideoMode(1000,691, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
//initialisation texte
initialiser_texte(&txte);
//initialisation image 
initialiser_imageBACK(&IMAGE);
initmap(&m);
//initialisation animation enigme 
animerMinimap(&m);
initialiser_temps(&t);
initialiser_Masque(&Masque);
while(boucle)
{
//affichage des images
afficher_imageBACK(screen , IMAGE);
//afficher_imageBACK(screen , Masque);
afficherminimap(screen , m);
afficheranimationENIGME(screen , m.T[i]);
i++;
if (i==4) i=0;
//temps
afficher_temps(&t,screen);
SDL_Flip(screen);
while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
boucle=0;
break;
case (SDL_KEYDOWN):
switch(event.key.keysym.sym)
{
//mouvement 
case SDLK_RIGHT:
{
avancer(&m);
R=collisionPP(m,&Masque);
if (R==1)
somme++;
printf("%d \n", somme);
}
break;
case SDLK_LEFT:
{
reculer(&m);
R=collisionPP(m,&Masque);
if (R==1)
initialiser_audiobref(&music);
somme++;
printf("%d \n", somme);
}
break;
case SDLK_UP:
{
reculerY(&m);
R=collisionPP(m,&Masque);
if (R==1)
somme++;
printf("%d \n",somme);
}
break;
case SDLK_DOWN:
{
avancerY(&m);
R=collisionPP(m,&Masque);
if (R==1)
somme++;
printf("%d \n",somme);
}
break;
}
}
}
//SDL_Delay(250);
}
//liberation
liberer_image(IMAGE);
liberer_minimap(m); 
liberer_texte(txte);
SDL_Quit();
return 0;
}
