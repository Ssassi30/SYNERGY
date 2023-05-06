#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
int main ()
{
SDL_Surface *screen;
SDL_Event event;
tic t;
temps T;
image Masque,Masque2;
int boucle=1,x,y,coup;
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)
{
printf("Could not initialize SDL : %s. \n", SDL_GetError());
return -1;
}
screen=SDL_SetVideoMode(631,627, 32, SDL_SWSURFACE|SDL_DOUBLEBUF);
//initialisation
init_image(&Masque);
init_image1(&Masque2);
initialiserTic(&t);
initialiser_temps(&T);
while(boucle)
{
//affichage
afficherTic(t,screen);
afficher_texte(t,screen);
afficher_temps(&T,screen);
while(SDL_PollEvent(&event))
{
switch(event.type)
{
case (SDL_MOUSEMOTION):
{
SDL_GetMouseState(&x,&y);
printf("x=%d \n",x);
printf("y=%d \n",y);
}
break;
case SDL_MOUSEBUTTONDOWN:
{
//carreau 1
if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=231&& event.motion.x>=102 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[0]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=231&& event.motion.x>=102 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[0]=-1;
}
//carreau 2
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=398&& event.motion.x>=231 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[1]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=398&& event.motion.x>=231 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=-1;
t.T[1]=-1;
}
//carreau 3
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=549&& event.motion.x>=398 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[2]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=226&& event.motion.y>=94)&&(event.motion.x<=549&& event.motion.x>=398 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[2]=-1;
}
//carreau 4
else
if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=226&& event.motion.x>=102 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[3]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=226&& event.motion.x>=102 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[3]=-1;
}
//carreau 5
else
if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=401&& event.motion.x>=226 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[4]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=401&& event.motion.x>=226 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[4]=-1;
}
//carreau 6
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=549&& event.motion.x>=401 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[5]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=394&& event.motion.y>=226)&&(event.motion.x<=549&& event.motion.x>=401 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[5]=-1;
}
//carreau 7
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=226&& event.motion.x>=102 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[6]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=226&& event.motion.x>=102 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[6]=-1;
}
//carreau 8
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=401&& event.motion.x>=226 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[7]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=401&& event.motion.x>=226 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[7]=-1;
}
//carreau 9
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=549&& event.motion.x>=401 && t.j1==1))
{
afficher_image(screen,Masque);
t.j1=2;
t.T[8]=1;
}
else if ((event.button.button==SDL_BUTTON_RIGHT)&&(event.motion.y<=536&& event.motion.y>=398)&&(event.motion.x<=549&& event.motion.x>=401 && t.j1==2))
{
afficher_image(screen,Masque2);
t.j1=1;
t.T[8]=-1;
}
}//mouse buttondown
break;
}//event type
}//SDL_POLLevent
SDL_Flip(screen);

}//boucle
//liberation
liberer(t); 
SDL_Quit();
return 0;
}
