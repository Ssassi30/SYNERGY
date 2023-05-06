#include "ES.h"

#include "bounding_box.h"

void init_es(ES * p) 
{
  ( * p).d = 0;
  ( * p).vie = 100;
  ( * p).pos.x = 50;
  ( * p).pos.y = 20;
  ( * p).sprite.x = 0;
  ( * p).sprite.y = 0;
  ( * p).state = 0;
  ( * p).speed = 10;
  /*( * p).image = IMG_Load("spritesheet1.png");
  ( * p).pos.w = ( * p).image -> w/6;
  ( * p).pos.h = ( * p).image -> h/2;*/
	p->entite[0][0].img = IMG_Load("drone1.png");
	p->entite[0][1].img = IMG_Load("drone2.png");
	p->entite[0][2].img = IMG_Load("drone3.png");
	p->entite[0][3].img = IMG_Load("drone4.png");
	p->entite[1][0].img = IMG_Load("snake1.png");
	p->entite[1][1].img = IMG_Load("snake2.png");
	p->entite[1][2].img = IMG_Load("snake3.png");
	p->entite[1][3].img = IMG_Load("snake4.png");

}
/*
void init_key(image o[])
{
	
	int i;
	for(i=0;i<6;i++)
	{
		(o+i)->img=IMG_Load("key.png");	
		(o+i)->pos_img_affiche.x=0;
		(o+i)->pos_img_affiche.y=0;
		(o+i)->pos_img_affiche.h=340;
		(o+i)->pos_img_affiche.w=500;
	}
	(o)->pos_img_ecran.x=0;
	(o)->pos_img_ecran.y=200;
	(o+1)->pos_img_ecran.x=150;
	(o+1)->pos_img_ecran.y=150;
	(o+2)->pos_img_ecran.x=300;
	(o+2)->pos_img_ecran.y=150;
	(o+3)->pos_img_ecran.x=450;
	(o+3)->pos_img_ecran.y=180;
	(o+4)->pos_img_ecran.x=500;
	(o+4)->pos_img_ecran.y=50;
	(o+5)->pos_img_ecran.x=650;
	(o+5)->pos_img_ecran.y=150;
	
}

void init_energy(image o[])
{	
	int i;
	for(i=0;i<3;i++)
	{
		strcpy(o[i].type,"energy");
		o[i].image = IMG_Load("energy.png");
		o[i].pos.w =o[i].image->w;
		o[i].pos.h = o[i].image->h;
	}
}

void init_spoon(objet o[]){
	
	int i;
	for(i=0;i<3;i++)
	{
		strcpy(o[i].type,"spoon");
		o[i].image = IMG_Load("spoon.png");
		o[i].pos.w =o[i].image->w;
		o[i].pos.h = o[i].image->h;
	}
}
*/
void afficher_es(ES p, SDL_Surface * screen,int t,int stage) 
{
    SDL_BlitSurface(p.entite[stage][t%4].img,NULL, screen, & p.pos);
}
/*
void afficher_objet(image o[], SDL_Surface * screen,Background b) 
{
	int i;
	for(i=0;i<6;i++)
	{
		SDL_BlitSurface(o[i].img, &(b.camera_pos), screen,NULL);
	}
}
*/

void mouvement_aleatoire(ES *p)
{
if (( * p).pos.x % 500==0) ( * p).d=rand()%2;
if(( * p).pos.x<-200) ( * p).d=0;
if(( * p).pos.x>1200) ( * p).d=1;
if (( * p).d==1) ( * p).pos.x-=1;
else ( * p).pos.x+=1;
}
void mouvement_aleatoire2(ES *p)
{
if (( * p).pos.x % 500==0) ( * p).d=rand()%2;
if(( * p).pos.x<300) ( * p).d=0;
if(( * p).pos.x>900) ( * p).d=1;
if (( * p).d==1) ( * p).pos.x-=1;
else ( * p).pos.x+=1;
}


