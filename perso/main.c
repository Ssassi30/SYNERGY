#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include "perso.h"
int main ()
{
SDL_Surface *screen;
image IMAGE_bkg;
Uint32 dt;
image vie_score;
texte txte;
int xx;
int yy;
Uint32 t_prev;
SDL_Event event;
personne p;
int boucle=1;

if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
	printf("could not initialize SDL: %s. \n", SDL_GetError());
	return -1;
	}
screen=SDL_SetVideoMode(600 , 340, 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
initialiser_imageBACK(&IMAGE_bkg);
initialiser_imageBTN(&vie_score,"viescore.png",0,0);
initialiser_texte(&txte);
int xi=0; // besh yet7at fl coin mta3 l ecran alisar
int yi=150;
init_perso(&p ,xi,yi);
while(boucle)
{
	afficher_image(screen,IMAGE_bkg);
	afficherPerso(p, screen);
	//SDL_Flip(screen);
	afficher_image(screen,vie_score);
	afficher_texte(screen , txte,p);
	p.score++;
	SDL_Flip(screen);
		SDL_PollEvent(&event); // takra l event mnghyt matebloki l boocle
	
		t_prev=SDL_GetTicks();//ykhou lwaket bl milliseconde mli nty amalt l act 
//khdhina lwaket mta3 awl mt7alet jeu yani awl madkhal fl boocle  
		switch(event.type)
		{
		 case SDL_QUIT:
		 boucle=0;
		break;
		
		case SDL_KEYDOWN: //bsh yakra nazla mta l button 
 
		switch (event.key.keysym.sym) //tout depend anehy l buuton lmanzoula 
		{
                    case SDLK_UP:
                        
			SDL_Delay(80); //nwakher fl acte
			dt =SDL_GetTicks()-t_prev;//shadit l wakt li hoa nezl fyh na7it menou lwaket mta3 awel l bocle bsh net7aslou ala lwaket dt li bsh tmshi bih 
			p.direction=2; //ki yabda meshy lfouk 
			deplacerPerso(&p, dt);
			animerPerso(&p);
			afficherPerso(p, screen);
			SDL_Flip(screen);
                        break;
                    case SDLK_DOWN:
                        
			SDL_Delay(80);
			dt =SDL_GetTicks()-t_prev;
			p.direction=3;
			deplacerPerso(&p, dt);
			animerPerso(&p);
			afficherPerso(p, screen);
			SDL_Flip(screen);
                        break;
                    case SDLK_LEFT:
                       
			SDL_Delay(80);
			dt =SDL_GetTicks()-t_prev;
			p.direction=1;
			deplacerPerso(&p, dt);
			animerPerso(&p);
			afficherPerso(p, screen);
			SDL_Flip(screen);
                        break;
                    case SDLK_RIGHT:
                        //deplacer_perso(&p, 5, 0);
			SDL_Delay(80);
			dt =SDL_GetTicks()-t_prev;
			p.direction=0;
			deplacerPerso(&p, dt);
			animerPerso(&p);
			afficherPerso(p, screen);
			SDL_Flip(screen);
                        break;
			
                }

break; 
	case SDL_KEYUP: //bsh yakra baed manzelt o sayebt
		switch (event.key.keysym.sym) 
		{
			case SDLK_SPACE:
				SDL_Delay(100);
				p.espace=1;
				saut(&p,p.screen_pos.x,p.screen_pos.y); //pos mta perso kbal maynaGes f screen
				animerPerso(&p);
				afficherPerso(p,screen);
				SDL_Flip(screen);

		               

				if(p.screen_pos.y<=0)//ki yakhlet l 0 toali button okhra , yani l event affectit feha button okhra khtr hoa bsh yoked yakrali l buuton li sayebtha bsh yoked ynagez yani tala3 lfouk mayahbetsh 
					{p.screen_pos.y=150;event.key.keysym.sym=SDLK_F2;}//y yraja3ha 150 ouin kn mawjoud 
					
			break;
				xi=p.screen_pos.x;
			       	yi=p.screen_pos.y;
				init_perso(&p ,xi,yi);
				afficherPerso(p,screen);
				SDL_Flip(screen);
		}
}	
}

liberer_image(IMAGE_bkg);
//liberer_texte(txte);
SDL_Quit();
return 0;
}
