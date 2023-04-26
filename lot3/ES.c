#include "ES.h"

#include "bounding_box.h"

void init_es(ES * p) 
{
  ( * p).d = 2;
  ( * p).vie = 100;
  ( * p).pos.x = 500;
  ( * p).pos.y = 245;
  ( * p).sprite.x = 0;
  ( * p).sprite.y = 0;
  ( * p).state = 0;
  ( * p).sprite_n = 0;
  ( * p).speed = 10;
  ( * p).image = IMG_Load("sprite.png");
  ( * p).pos.w = ( * p).image -> w/6;
  ( * p).pos.h = ( * p).image -> h/4;
}
void init_key(objet *o){
strcpy((*o).type,"key");
(*o).image = IMG_Load("key.png");
(*o).pos.x = 500;
(*o).pos.y = 250;
(*o).pos.w = (*o).image->w;
(*o).pos.h = (*o).image->h;
}

void init_energy(objet *o){
strcpy((*o).type,"energy");
(*o).image = IMG_Load("energy.png");
(*o).pos.x = 100;
(*o).pos.y = 200;
(*o).pos.w = (*o).image->w;
(*o).pos.h = (*o).image->h;
}

void init_spoon(objet *o){
strcpy((*o).type,"spoon");
(*o).image = IMG_Load("spoon.png");
(*o).pos.x = 300;
(*o).pos.y = 300;
(*o).pos.w = (*o).image->w;
(*o).pos.h = (*o).image->h;
}
void afficher_es(ES p, SDL_Surface * screen) {
    SDL_BlitSurface(p.image, & p.sprite, screen, & p.pos);
}

void afficher_objet(objet o, SDL_Surface * screen) {
    SDL_BlitSurface(o.image, NULL, screen, & o.pos);
}

void animer_es(ES * p) 
{
	( * p).sprite.w = ( * p).image-> w/6;
    ( * p).sprite.h = ( * p).image-> h/4;
    ( * p).sprite_n++;
    if (( * p).sprite_n >= 5) {
      ( * p).sprite_n = 0;}
    ( * p).sprite.x = ( * p).sprite.w * ( * p).sprite_n;
    ( * p).sprite.y = ( * p).sprite.h * ( * p).d;
}
void mouvement_aleatoire(ES *p)
{
if (( * p).pos.x % 50==0) ( * p).d=2+rand()%2;
if(( * p).pos.x<330) ( * p).d=2;
if(( * p).pos.x>800) ( * p).d=3;
if (( * p).d==0) ( * p).pos.y-=5;
if (( * p).d==1) ( * p).pos.y+=5;
if (( * p).d==2) ( * p).pos.x+=5;
if (( * p).d==3) ( * p).pos.x-=5;
}
void mouvement_aleatoire2(ES *p)
{
if (( * p).pos.x % 50==0) ( * p).d=2+rand()%2;
if(( * p).pos.x<900) ( * p).d=2;
if(( * p).pos.x>1370) ( * p).d=3;
if (( * p).d==0) ( * p).pos.y-=5;
if (( * p).d==1) ( * p).pos.y+=5;
if (( * p).d==2) ( * p).pos.x+=5;
if (( * p).d==3) ( * p).pos.x-=5;
}
void mouvement_aleatoire3(ES *p)
{
if (( * p).pos.y % 50==0) ( * p).d=rand()%2;
if(( * p).pos.y<520) ( * p).d=1;
if(( * p).pos.y>740) ( * p).d=0;
if (( * p).d==1) ( * p).pos.y+=5;
else ( * p).pos.y-=5;
}
