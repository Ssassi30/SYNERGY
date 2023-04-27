#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "eni.h"

int main()
{	
	SDL_Surface *screen;
	enigme1 e1;
	enigme2 e2;
	temps time;
	SDL_Event event;
	int boucle = 1;
	int i=-1,g;
	char nomfich[20]="enigme.txt";
	initenigme1(&e1);
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
		printf("Could not initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	screen=SDL_SetVideoMode(500,500,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	initialiser_temps(&time);
	generer(&e2,nomfich);
	while(boucle)
	{
		afficher_temps(&time,screen);
		//afficherenigme1(e1,screen, time.secondesEcoulees);
		afficherEnigme2(e2,screen);
		SDL_Flip(screen);
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case (SDL_KEYDOWN):
				switch(event.key.keysym.sym)
				{
					case SDLK_s:
							if(i<5){i++;
							e1.l[0].q=i;}
						break;
					case SDLK_b:
							if(i<5){i++;
							e1.l[1].q=i;}
						break;
					case SDLK_i:
							if(i<5){i++;
							e1.l[2].q=i;}
						break;
					case SDLK_h:
							if(i<5){i++;
							e1.l[3].q=i;}
						break;
					case SDLK_f:
							if(i<5){i++;
							e1.l[4].q=i;}
							
						break;
					case SDLK_r:
							if(i<5){i++;
							e1.l[5].q=i;}
					
						break;
					case SDLK_g:
							if(i<5){i++;
							e1.l[6].q=i;}
						
						break;
					case SDLK_e:
							if(i<5){i++;
							e1.l[7].q=i;}
						
						break;
					case SDLK_u:
							if(i<5){i++;
							e1.l[8].q=i;}
						
						break;
					case SDLK_t:
							if(i<5){i++;
							e1.l[9].q=i;}
						break;
					case SDLK_1:
							printf("1");if(e2.numbr==1) printf("gagnant"); else boucle =0; 
						break;
					case SDLK_2:
							printf("2");if(e2.numbr==2) printf("gagnant");else boucle =0;
						break;
					case SDLK_3:
							printf("3");if(e2.numbr==3) printf("gagnant");else boucle =0;
						break;
				}
				break;
			case SDL_QUIT:
				boucle=0;
				break;
			case SDL_MOUSEBUTTONDOWN: //click
				if((event.button.button==SDL_BUTTON_LEFT)&&
				((event.motion.y<=330&&event.motion.y>=250)&&(event.motion.x<=300&&event.motion.x>=150)))
					{
					printf("1");if(e2.numbr==1) printf("gagnant"); else boucle =0; 
					}
				if((event.button.button==SDL_BUTTON_LEFT)&&
				((event.motion.y<=430&&event.motion.y>=350)&&(event.motion.x<=400&&event.motion.x>=250)))
					{
					printf("2");if(e2.numbr==2) printf("gagnant"); else boucle =0; 
					}
				if((event.button.button==SDL_BUTTON_LEFT)&&
				((event.motion.y<=330&&event.motion.y>=250)&&(event.motion.x<=500&&event.motion.x>=350)))
					{
					printf("3");if(e2.numbr==3) printf("gagnant"); else boucle =0; 
					}
				break;
			break;	
			}
			
		}
		if(gagne1( e1)==1) printf("gagnant\n");
		
	
	}
	
	

	SDL_Quit();
	
	return 0;
}

