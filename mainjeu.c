#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "bckg.h"
#include "perso.h"
#include "minimap.h"
#include "ES.h"
#include "bounding_box.h"


int main()
{	
	

	
	int colli;
	image IMAGE,imgbtn,masque[2];
	texte txte,txtee,police,txteee;
	minimap m,m1;
	char nom[100],temps1[100];
	temps timee;
	char c[1];
	SDL_Surface *screen;
	SDL_Rect perso,police1,police2;
	SDL_Event event;
	ScoreInfo s,t[5];
	Background b;
	initmap(&m);
	initBack(&b);
	Uint32 dt;
	Uint32 t_prev;
	int xx;
	int yy;
	personne p;
	init_perso(&p);
	initialiser_texte(&txte);//douaa
	initialiser_Masque(masque);
	initialiser_imageBTN(&imgbtn,"vie.png",0,0);
	initialiser_textee(&txtee);//slim
	initialiser_temps(&timee);
	int i=0;
	int on=1;
	char* filename="score.txt";
	int direction;
	int sss=0;
        ES es1,es2;
	objet obj[3];//,spoon[3],energy[3];
	initobj(obj);
	init_es(&es1);
        init_es(&es2);
	es2.pos.x=300;
	//init_key(key);
	//init_energy(energy);
	//init_spoon(spoon);
        SDL_Init(SDL_INIT_EVERYTHING);
        srand( time( NULL ) );
        
	initmap(&m);
	animerMinimap(&m);
        
        
	
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
		printf("Could not initialize SDL: %s\n",SDL_GetError());
		return 1;
	} 
	
	screen=SDL_SetVideoMode(900,400,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	TTF_Font* font=TTF_OpenFont("Base 02.ttf",24);
	SDL_Color color = {255,255,255};
	SDL_Surface* textSurface=TTF_RenderText_Blended(font,"Enter username",color);
	
	char username[256]="";
	int len;
	SDL_EnableUNICODE(1);
	int boucle=1;
	while(boucle)
	{ 
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
			{
				boucle=0;
			}
			else if(event.type==SDL_KEYDOWN)
			{
				if(event.key.keysym.sym==SDLK_RETURN){
					break;
				}
				else if(event.key.keysym.unicode <0x80 && len<255){
					username[len]=(char)event.key.keysym.unicode;
					len++;
				}
			}
		}
		SDL_Rect textRect={10,10,10};
		SDL_BlitSurface(textSurface,NULL,screen,&textRect);
		SDL_Surface* usernameSurface=TTF_RenderText_Blended(font,username,color);
		SDL_Rect usernameRect={10,50,0,0};
		SDL_BlitSurface(usernameSurface,NULL,screen,&usernameRect);
		SDL_FreeSurface(usernameSurface);
		SDL_Flip(screen);
		/*
		//saisienomjoueur(&s,screen);
		afficher_temps(&timee,screen);
		afficher_image(screen, imgbtn);
		SDL_Flip(screen);
		afficherBack(b,screen,timee.secondesEcoulees,on,p);
		afficherminimap(screen,m);
		afficherPerso(p,screen);
		afficheranimationENIGME(screen ,m.T[i]);
		if(sss==1)afficherBest(t,screen,txteee);//nour
		afficherobj(&b,obj,screen);
		
		
		i++;
		if(i==4) i=0;
		
		//printf("%d\n",collision(es1.pos,es2.pos));
		
		afficher_es(es1,screen);
				
		animer_es(&es1,timee.secondesEcoulees);
				
		afficher_es(es2,screen);
		animer_es(&es2,timee.secondesEcoulees);
		
		//afficher_objet(key,screen,b);
		/*switch(b.stage)
		{
			case 0:afficher_objet(key,screen);
				break;
			case 1:afficher_objet(spoon,screen);
				break;
			case 2:
				afficher_objet(energy,screen);
				break;
		}
		afficher_texte(screen , txte,p);//doua
		mouvement_aleatoire(&es1);
		mouvement_aleatoire2(&es2);
		SDL_PollEvent(&event);
		t_prev=SDL_GetTicks();
		//recherche collision
		int i=0,test=0;
		perso.x=p.screen_pos.x+b.camera_pos.x;
		perso.y=p.screen_pos.y+b.camera_pos.y;
		perso.w=p.screen_pos.w;
		perso.h=p.screen_pos.h;
		while(test==0 && i<3)
		{
//printf("px:%d py:%d pw:%d ph:%d ---------- ox:%d oy:%d ow:%d oh:%d\n",perso.x,perso.y,perso.w,perso.h,obj[i].pos_img_ecran.x,obj[i].pos_img_ecran.y,obj[i].pos_img_ecran.w,obj[i].pos_img_ecran.h);	
			if (box(perso,obj[i].o.pos_img_ecran)==1) test=1; 
			else i++;
		}
		if (test==1)
		{ 
			p.score ++; obj[i].off=1; 
		}
		police1.x=es1.pos.x+b.camera_pos.x;
		police2.x=es2.pos.x+b.camera_pos.x;
		police1.y=es1.pos.y+b.camera_pos.y;
		police2.y=es2.pos.y+b.camera_pos.y;
		if(box(perso,police1)==1||box(police2,perso)==1) p.score--;printf("px:%d es1x:%d es2x:%d\n",perso.x,es1.pos.x,es2.pos.x);
		direction=-1;
		p.espace=0;
		on=0;
		switch(event.type)
		{
			case (SDL_KEYDOWN):
				switch(event.key.keysym.sym)
				{
				case SDLK_RIGHT:						 	  	  		
					
					if(b.stage >0)
					{
						colli=collisionPP(perso,masque[b.stage-1].img);
						if(colli==0)	
						
							printf("0\n");
						else 
							printf("1\n");
						if(b.stage==0 || b.stage==1 || (b.stage==2 && b.camera_pos.x>2000 )) avancer(&m);
						else reculerY (&m);
						direction=0;
						SDL_Delay(80);
						dt =SDL_GetTicks()-t_prev;
						p.direction=0;
						
						if(box(b.camera_pos,perso))
						{	deplacerPerso(&p, dt,b,colli);
							animerPerso(&p);
							afficherPerso(p, screen);
							SDL_Flip(screen);
						}
						
					}
					break;
				case SDLK_LEFT:
					
					
					if(b.stage >0)
					{
						colli=collisionPP(perso,masque[b.stage-1].img);
						if(colli==0)	
							printf("0\n");
						else printf("1\n");
						direction=1;
						reculer (&m);
						SDL_Delay(80);
						dt =SDL_GetTicks()-t_prev;
						p.direction=1;
						if(box(b.camera_pos,perso))
						{deplacerPerso(&p, dt,b,colli);
						animerPerso(&p);
						afficherPerso(p, screen);
						SDL_Flip(screen);}
						
						
					}
					break;
				case SDLK_UP:
					
					if(b.stage >0)
					{
						colli=collisionPP(perso,masque[b.stage-1].img);
						if(colli==0)	
							printf("0\n");
						else printf("1\n");
							reculerY (&m);
							//bckg
							direction=2;
							//perso
							SDL_Delay(80);
							dt =SDL_GetTicks()-t_prev;
							p.direction=2;
							if(box(b.camera_pos,perso))
						{deplacerPerso(&p, dt,b,colli);
							animerPerso(&p);
							afficherPerso(p, screen);
							SDL_Flip(screen);}
						
						
					}
					break;
				case SDLK_DOWN:
					
					if(b.stage >0)
					{
						colli=collisionPP(perso,masque[b.stage-1].img);
						if(colli==0)	
							printf("0\n");
						else printf("1\n");
						direction=3;
						avancerY( &m);
						SDL_Delay(80);
						dt =SDL_GetTicks()-t_prev;
						p.direction=3;
						if(box(b.camera_pos,perso))
						{deplacerPerso(&p, dt,b,colli);
						animerPerso(&p);
						afficherPerso(p, screen);
						SDL_Flip(screen);}
						
						
					}
					break;
					//case SDLK_p:
						//saisienomjoueur(&s,screen);
						//break;
				case SDLK_s:
					initialiser_texteee(&txteee);//nour
					s.score=p.score;
					s.temps=timee.secondesEcoulees;
					strcpy(s.playerName,"p5");
					saveScore(s,filename);
					bestScore(filename,t);
					sss=1;
					break;
				case SDLK_l:
				//	afficherPerso(p,screen);
					b.stage=1;
					b.camera_pos.x=100;
					b.camera_pos.y=700;
					on=1;
					break;
				case SDLK_a:
				//	afficherPerso(p,screen);
					b.stage=2;
					b.camera_pos.x=00;
					b.camera_pos.y=120;
					on=1;
					break;
				}
				break;
			case (SDL_KEYUP):	
				switch (event.key.keysym.sym)
				{
					case SDLK_SPACE:
						if(b.stage >0)
						{
							colli=collisionPP(perso,masque[b.stage-1].img);
							//if(colli==0)
							//	printf("0\n");
						//	else printf("1\n");
							SDL_Delay(80);
							b.camera_pos.y-=(20);
							p.espace=1;
							saut(&p,p.screen_pos.x,p.screen_pos.y);
							animerPerso(&p);
							afficherPerso(p, screen);
							SDL_Flip(screen);
							if(p.screen_pos.y<=0)
								{p.screen_pos.y=150;event.key.keysym.sym=SDLK_F2;}
							
							
							
						}
					break;	
				}
				break;
				
			case SDL_QUIT:
				boucle=0;
			break;
		}
		
		scrolling(&b,direction , p,box(b.camera_pos,perso),colli);
		*/
	}
			
	//liberer_texte(txte);
	//libererBack(b,txteee);
	
	return 0;
}
