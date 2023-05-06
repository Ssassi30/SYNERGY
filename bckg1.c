#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "bckg1.h"

void initBack(Background *b)
{
	int i,j;
	char c[3],c1[3];
	i=0;
	for(j=1;j<=2;j++)
	{
		char nom[10]="bg";
		sprintf(c1,"%d",i+1);
		strcat(nom,c1);
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		b->imagebckg[i][j-1].img = IMG_Load(nom);
		if(b->imagebckg[i][j-1].img == NULL)
		{
			printf("%s\n",SDL_GetError());
			return ;
		}
		
	}
	i=1;
	for(j=1;j<=7;j++)
	{
		char nom[10]="l";
		sprintf(c1,"%d",i+1);
		strcat(nom,c1);
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		b->imagebckg[i][j-1].img = IMG_Load(nom);
		if(b->imagebckg[i][j-1].img == NULL)
		{
			printf("%s\n",SDL_GetError());
			return ;
		}
	}
	
	b->stage=0;
	b->direction1=-1;
	b->direction2=-1;
	//camera
		
	b->camera_pos1.x=0;
	b->camera_pos1.y=0;
	b->camera_pos1.w=1200;
	b->camera_pos1.h=630;

	b->posEcran1.x=0;
	b->posEcran1.y=0;
	b->posEcran1.h=630;
	b->posEcran1.w=600;

	b->camera_pos2.x=0;
	b->camera_pos2.y=0;
	b->camera_pos2.w=1200;
	b->camera_pos2.h=630;

	b->posEcran2.x=600;
	b->posEcran2.y=0;
	b->posEcran2.h=630;
	b->posEcran2.w=600;		
}
void animerBack(Background *b,SDL_Surface *screen,int time,int nb)
{
	int max;
	switch(b->stage)
	{
		case 0: 
			max=2;
			switch(nb)
			{	
				case 1:
				SDL_BlitSurface(b->imagebckg[b->stage][(time)% max].img,&(b->camera_pos1),screen,NULL);
				break;
				case 2:
				SDL_BlitSurface(b->imagebckg[b->stage][(time)% max].img,&(b->camera_pos1),screen,&b->posEcran1);
				SDL_BlitSurface(b->imagebckg[b->stage][(time)% max].img,&(b->camera_pos2),screen,&b->posEcran2);
				break;
			}
			break;
		case 1:max =7;
			switch(nb)
			{	
				case 1:
				SDL_BlitSurface(b->imagebckg[b->stage][(time/10)% max].img,&(b->camera_pos1),screen,NULL);
				break;
				case 2:
				SDL_BlitSurface(b->imagebckg[b->stage][(time/10)% max].img,&(b->camera_pos1),screen,&b->posEcran1);
				SDL_BlitSurface(b->imagebckg[b->stage][(time/10)% max].img,&(b->camera_pos2),screen,&b->posEcran2);
				break;
			}
			break;
	}
}
void afficherBack(Background b,SDL_Surface *screen,int time,int on,personne p1,personne p2,int nb)
{
	if(on==1) 
	{
		char ch[3];
		char nom[8]="";
		sprintf(ch,"%d",b.stage);
		strcat(nom,ch);
		strcat(nom,".mp3\0");
		if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		{
			printf("%s",SDL_GetError());
		}
		b.musicbckg[b.stage]=Mix_LoadMUS(nom);
		Mix_PlayMusic(b.musicbckg[b.stage],-1);
		Mix_VolumeMusic(MIX_MAX_VOLUME);
	}
	/*if(p1.espace ==1 || p2.espace ==1)
	{
		Mix_Chunk* mus;
		Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
		mus = Mix_LoadWAV("Saut.wav");
		Mix_PlayChannel(-1,mus,0);
		if(mus == NULL) printf("%s",SDL_GetError());
	}*/
	animerBack(&b,screen,time,nb);
}
void scrolling(Background *b, personne p1,personne p2) 
{
	switch(b->direction1)
	{
		case 0:(b->camera_pos1.x)+=(p1.pas*5);break;
		case 1:(b->camera_pos1.x)-=(p1.pas);break;	
		case 2:if (p1.direction == 0)	
				b->camera_pos1.x+=(40);
			else 
				b->camera_pos1.x-=(40);
				b->camera_pos1.y+=(10);
			break;					
	}
	switch(b->direction2)
	{
		case 0:(b->camera_pos2.x)+=(p2.pas*3);break;
		case 1:(b->camera_pos2.x)-=(p2.pas*3);break;
		case 2:if (p2.direction == 0)	
			b->camera_pos2.x+=(40);
			else 
				b->camera_pos2.x-=(40);
				b->camera_pos2.y+=(10);			
	}	
}
