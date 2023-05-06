#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h> 
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 
#include "menu.h"
#include "minimap.h"
#include "serie.h"
#include "bckg1.h"
#include "bounding_box.h"
#include "ES.h"
int main()
{
	char buffer[100]; // un buffer
	int i;
	int x;
	//int fd = serialport_init("/dev/ttyUSB0", 115200);
//	if (fd==-1) return -1;
	menu m;
	option o;
	play p;
	quit q;
	score s;
	image masque[4];
	initialiser_Masque(masque);
	int u; //manette ou clavier
	int jump1=0;int jump2=0;
	SDL_Surface *screen;
	SDL_Event event;
	SDL_Joystick *joystick;
	SDL_Init(SDL_INIT_EVERYTHING);
	initialisermenu(&m,&o,&p,&q,&s);
	personne p1,p2;
	init_perso(&p1);
	init_perso2(&p2);
	Background b;
	initBack(&b);
	ES es1,es2;
	init_es(&es1);
        init_es(&es2);
	screen=SDL_SetVideoMode(1200,630,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	int boucle=1;
	int niveau=0;
	int on;//tohkm fl musique
	cadre c;
	
	int colli1,colli2;
	temps time;
	initialiser_temps(&time);
	int key[323]={0};
	key[ SDLK_SPACE]=-1;
	while(boucle)
	{	
		
		on=0;p1.espace=0;
		affichermenu(&m,&o,&p,&q,&s,screen,&time,&niveau,key,&boucle,&on);
		if(p.nb>0) //dkhalna f jeu
		{
			printf("time.secondesEcoulees %d\n",time.secondesEcoulees);
			if(time.secondesEcoulees==5) b.stage=1; //test stage 2 taa tunnel
			cadrage(&c,b,p1,p2,es1,es2,p.nb);
			afficherBack(b,screen,time.secondesEcoulees,on,p1,p2,p.nb);
			afficherPerso(p1, screen);
			if(p.nb==2) 
				afficherPerso(p2, screen);
			if(b.stage==1)
			{	es1.pos.y = 350;
				es2.pos.y = 350;
			}
			afficher_es(es1,screen,time.secondesEcoulees,b.stage);			
			afficher_es(es2,screen,time.secondesEcoulees,b.stage);
			
			mouvement_aleatoire(&es1);
			mouvement_aleatoire2(&es2);
		}
		afficher_temps(&time,screen,p.nb);
		SDL_Flip(screen);
		SDL_PollEvent(&event);
		SDL_JoystickEventState;
		switch(event.type)
		{
			case (SDL_KEYDOWN):
					key[event.key.keysym.sym]=1;
					break;
			case (SDL_KEYUP):
					//jump joueur 1
					if(event.key.keysym.sym==SDLK_SPACE)
					{
						if(key[ SDLK_SPACE]==1) //init jump
							{key[ SDLK_SPACE]=0;jump1++;}
						else if(jump1<4) //encore jumping
							key[ SDLK_SPACE]=0;
						else
							key[ SDLK_SPACE]=-1;
					}
					//jump joueur 2
					else if(event.key.keysym.sym==SDLK_r)
						{
							if(key[ SDLK_r]==1) //init jump
								{key[ SDLK_r]=0;jump2++;}
							else if(jump2<4) //encore jumping
								key[ SDLK_r]=0;
							else
								key[ SDLK_r]=-1;
						}
					//casual
					else		
						key[event.key.keysym.sym]=0;
					break;	
				
			case SDL_QUIT:
					boucle=0;
					break;
		}
		
		if(p.nb>0) //MAJ f jeu mch menu
		{
			b.direction1=-1;
			b.direction2=-1;
			//p1.direction=-1;
			//p2.direction=-1;
			if(box(b.camera_pos1,c.perso1))
			{
				colli1=0;
				//colli1=collisionPP(c.perso1,masque[b.stage].img);
				if(key[SDLK_RIGHT])
				{
					switch(colli1)
					{
						case 0:p1.direction=0;b.direction1=0;break;
						case 1:p1.direction=1;b.direction1=1;break;
					}
					deplacerPerso(&p1);
					animerPerso(&p1);		
				}
				else if(key[SDLK_LEFT])
					{
						switch(colli1)
						{
							case 0:p1.direction=1;b.direction1=1;break;
							case 1:p1.direction=0;b.direction1=0;break;
						}
						deplacerPerso(&p1);
						animerPerso(&p1);		
					}
				//saut
				if(key[ SDLK_SPACE]==0&&jump1>0)
				{
					b.direction1=2;
					jump1++;
					saut(&p1,p1.screen_pos.x,p1.screen_pos.y,key);
					SDL_Delay(80);
					animerPerso(&p1);					
					b.camera_pos1.y-=(10);		
					if(p1.screen_pos.y<=5)
						{p1.screen_pos.y=260;}
					
				}	
				if(jump1==4)
					jump1=0;
			}
			if(p.nb==2)//multi
			{
				b.camera_pos1.w=600;
				colli2=0;
				//colli2=collisionPP(c.perso2,masque[b.stage+2].img);
				if(box(c.cam2,c.perso2))
				{
					if(key[SDLK_d])
					{
						switch(colli2)
						{
							case 0:p2.direction=0;b.direction2=0;break;
							case 1:p2.direction=1;b.direction2=1;break;	
						}	
						deplacerPerso(&p2);
						animerPerso(&p2);			
					}
					else if(key[SDLK_g])
					{
						switch(colli2)
						{
							case 0:p2.direction=1;b.direction2=1;break;
							case 1:p2.direction=0;b.direction2=0;break;
						}		
						deplacerPerso(&p2);
						animerPerso(&p2);		
					}		
					
							
					if(key[ SDLK_r]==0&&jump2>0)
					{
						b.direction2=2;
						jump2++;
						saut(&p2,p2.screen_pos.x,p2.screen_pos.y,key);SDL_Delay(80);
						animerPerso(&p2);
						b.camera_pos2.y-=(10);
						if(p2.screen_pos.y<=5)
							{p2.screen_pos.y=260;}
					}	
					if(jump2==4)
						jump2=0;
				}
			}	
			scrolling(&b,p1,p2);
			printf("colli1 = %d\n",colli1);
			printf("box1 = %d\n",box(b.camera_pos1,c.perso1));
			printf("b.camera_pos1 x = %d		perso1 x = %d\n",b.camera_pos1.x,c.perso1.x);
			printf("b.camera_pos1 y = %d		perso1 y = %d\n",b.camera_pos1.y,c.perso1.y);
			printf("b.camera_pos1 w = %d		perso1 w = %d\n",b.camera_pos1.w,c.perso1.w);
			printf("b.camera_pos1 h = %d		perso1 h = %d\n",b.camera_pos1.h,c.perso1.h);
			printf("colli2 = %d\n",colli2);
			printf("box2 = %d\n",box(c.cam2,c.perso2));
			printf("b.camera_pos2 x = %d		perso2 x = %d\n",c.cam2.x,c.perso2.x);
			printf("b.camera_pos2 y = %d		perso2 y = %d\n",c.cam2.y,c.perso2.y);
			printf("b.camera_pos2 w = %d		perso2 w = %d\n",c.cam2.w,c.perso2.w);
			printf("b.camera_pos2 h = %d		perso2 h = %d\n",c.cam2.h,c.perso2.h);
		}
	}
	return 0;
}
