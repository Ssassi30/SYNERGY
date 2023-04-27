#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "bckg.h"

void initBack(Background *b)
{
	int i,j;
	char c[3],c1[3];
	i=0;
	for(j=1;j<=3;j++)
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
		b->imagebckg[i][j-1].pos_img_ecran.x=0;
		b->imagebckg[i][j-1].pos_img_ecran.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.x=0;
		b->imagebckg[i][j-1].pos_img_affiche.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.h=750;
		b->imagebckg[i][j-1].pos_img_affiche.w=1920;
		
	}

	i=1;
	for(j=1;j<=4;j++)
	{
		char nom[10]="BA";
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		b->imagebckg[i][j-1].img = IMG_Load(nom);
		if(b->imagebckg[i][j-1].img == NULL)
		{
			printf("%s\n",SDL_GetError());
			return ;
		}
		b->imagebckg[i][j-1].pos_img_ecran.x=0;
		b->imagebckg[i][j-1].pos_img_ecran.y=0;	
	}
	i=2;
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
		b->imagebckg[i][j-1].pos_img_ecran.x=0;
		b->imagebckg[i][j-1].pos_img_ecran.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.x=0;
		b->imagebckg[i][j-1].pos_img_affiche.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.h=540;
		b->imagebckg[i][j-1].pos_img_affiche.w=4848;
		
	}
	/*
	//chargement des sons brefs
	for(i=1;i<=4;i++)
	{
		nom[8]="";
		sprintf(c,"%d",i);
		strcat(nom,c);
		strcat(nom,".wav\0");
		Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
		b->musbckg[i] = Mix_LoadWAV(nom);
		Mix_PlayChannel(-1,musbckg[i],0);
		if(b->musbckg[i] == NULL) printf("%s",SDL_GetError());
	}*/
	b->stage=0;
	//camera
		
	b->camera_pos.x=450;
	b->camera_pos.y=250;

	b->camera_pos.w=900;
	b->camera_pos.h=400;
	
	
}

void animerBack(Background *b,SDL_Surface *screen,int time)
{
	int max;
	switch(b->stage)
	{
		case 0: 
			max=3;
			SDL_BlitSurface(b->imagebckg[b->stage][(time)% max].img,&(b->camera_pos),screen,NULL);
			break;
		case 1:max =4;
			SDL_BlitSurface(b->imagebckg[b->stage][(time/10)% max].img,&(b->camera_pos),screen,NULL);
			break;
		case 2: 
			max=7;
			SDL_BlitSurface(b->imagebckg[b->stage][(time)% max].img,&(b->camera_pos),screen,NULL);
			break;
	}
}
void afficherBack(Background b,SDL_Surface *screen,int time,int on,personne p)
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
	if(p.espace ==1)
	{
		Mix_Chunk* mus;
		
		Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
		mus = Mix_LoadWAV("Saut.wav");
		Mix_PlayChannel(-1,mus,0);
		if(mus == NULL) printf("%s",SDL_GetError());
	}

	animerBack(&b,screen,time);
}


void scrolling(Background *b,int direction , personne p ,int c,int col)
{
	
	if(c== 1){
		if(col==0)	
		{
			switch(direction)
			{
			case 0 :
					b->camera_pos.x+=p.pas*2;break;
				
			case 1:
					b->camera_pos.x-=p.pas*2;break;
				
			case 3:
				
					b->camera_pos.y+=p.pas*2;break;
				
			case 2:
				
					b->camera_pos.y-=p.pas*2;break;
			}
		}
		else 

		{
			switch(direction)
			{
			case 0 :
					b->camera_pos.x-=(p.pas*2);break;
				
			case 1:
					b->camera_pos.x+=(p.pas*2);break;
				
			case 3:
					b->camera_pos.y-=(p.pas*2);break;
				
			case 2:
				b->camera_pos.y+=(p.pas*2);break;
			}
		}
	}
	if(p.espace==1)
	{
			
			if (p.direction == 0)	
			b->camera_pos.x+=(40);
			else 
				b->camera_pos.x-=(40);
			b->camera_pos.y+=(20);
				
		
	}	
	printf("x: %d\n",b->camera_pos.x);
		
}
//objet
void initobj(objet obj[])
{
	int i,j;
	char c[3],c1[3];
	/*i=0;
	for(j=1;j<=3;j++)
	{
		char nom[10]="k";
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
		b->imagebckg[i][j-1].pos_img_ecran.x=0;
		b->imagebckg[i][j-1].pos_img_ecran.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.x=0;
		b->imagebckg[i][j-1].pos_img_affiche.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.h=750;
		b->imagebckg[i][j-1].pos_img_affiche.w=1920;
		
	}

	i=1;
	for(j=1;j<=9;j++)
	{
		char nom[10]="s";
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
		b->imagebckg[i][j-1].pos_img_ecran.x=0;
		b->imagebckg[i][j-1].pos_img_ecran.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.x=0;
		b->imagebckg[i][j-1].pos_img_affiche.y=0;
		b->imagebckg[i][j-1].pos_img_affiche.h=883;
		b->imagebckg[i][j-1].pos_img_affiche.w=1483;
		
	}*/
	//i=2;
	for(j=1;j<=3;j++)
	{
		char nom[10]="e";
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		obj[j-1].o.img = IMG_Load(nom);
		obj[j-1].o.pos_img_ecran.h=20;
		obj[j-1].o.pos_img_ecran.w=20;
		obj[j-1].off=0;
	}
	obj[0].o.pos_img_ecran.x=300;
	obj[0].o.pos_img_ecran.y=300;
	obj[1].o.pos_img_ecran.x=450;
	obj[1].o.pos_img_ecran.y=300;
	obj[2].o.pos_img_ecran.x=600;
	obj[2].o.pos_img_ecran.y=350;
}
void afficherobj(Background *b,objet obj[],SDL_Surface *screen)
{
	int max;
	switch(b->stage)
	{
		case 0: 
			max=3;
			break;
		case 1:max =9;
			break;
		case 2: 
			max=3;
			break;
	}
	int j;
	for(j=0;j<max;j++)
	{
		if(obj[j].off==0) 
		SDL_BlitSurface(obj[j].o.img,&(b->camera_pos),screen,NULL);
	}
}
int box(SDL_Rect x1,SDL_Rect x2) //x2 wst x1
{
	int t=0;
	if((x1.x<=x2.x)&&(x1.y<=x2.y)&&(x1.x + x1.w >= x2.x + x2.w) &&(x1.y + x1.h >= x2.y + x2.h))
		t=1;
	return t;
}
//scores

void saisienomjoueur(ScoreInfo *s,SDL_Surface *screen)
{
	texte txte1,txte2;
	initialiser_texteee(&txte1);
	txte1.txt=TTF_RenderText_Blended(txte1.police,"Enter username",txte1.color_txt);
	char username[256]="";
	int len=0;
	SDL_Event event;
	SDL_EnableUNICODE(1);
	while(SDL_PollEvent(&event))
	{
		 if(event.type==SDL_KEYDOWN)
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
	txte1.pos_txt.x=10;
	txte1.pos_txt.y=10;
	txte1.pos_txt.h=0;
	txte1.pos_txt.w=0;
	SDL_BlitSurface(txte1.txt,NULL,screen,&txte1.pos_txt);
	txte2.txt=TTF_RenderText_Blended(txte1.police,username,txte1.color_txt);
	txte2.pos_txt.x=10;
	txte2.pos_txt.y=50;
	txte2.pos_txt.h=0;
	txte2.pos_txt.w=0;
	SDL_BlitSurface(txte2.txt,NULL,screen,&txte2.pos_txt);
	SDL_FreeSurface(txte2.txt);
	strcat(s->playerName,username);
	SDL_Flip(screen);
}


void saveScore(ScoreInfo s,char *fileName)
{
	
	FILE *F=fopen(fileName,"a");
	if(F!=NULL)
	{
		fprintf(F,"%d %d %s\n",s.score,s.temps,s.playerName);
		fclose(F);
	}
	else
		printf("ERREUR D'OUVERTURE DU FICHIER");
}
void bestScore(char *filename,ScoreInfo t[])
{
	FILE *F=fopen(filename,"r");
	int i,n=0,j,max;
	ScoreInfo aux,a[100];

	if(F!=NULL)
	{
		while(fscanf(F,"%d %d %s\n",&a[n].score,&a[n].temps,a[n].playerName))
		{
			
			n++;
		}
		fclose(F);	
	}
	else
		printf("ERREUR D'OUVERTURE DU FICHIER");
	//tri	
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if((a[j].score>a[max].score)||(a[j].score==a[max].score && a[j].temps<a[max].temps))
				max=j;
		}
		aux=a[i];
		a[i]=a[max];
		a[max]=aux;
	}
	//remplissage t
	for(i=0;i<3;i++)
	{
		t[i]=a[i];
	}
}
void initialiser_texteee(texte *txte)
{

	
	//TTF_Init();
	txte->police=TTF_OpenFont("Base 02.ttf",30);
	txte->color_txt.r=252;
	txte->color_txt.g=210;
	txte->color_txt.b=28;
	txte->pos_txt.x=30;
	txte->pos_txt.y=100;

}

void afficherBest(ScoreInfo t[],SDL_Surface *screen,texte txte)
{
	int i;
	char ch[20]="";
	for(i=0;i<3;i++)
	{
		char c[10]="";
		printf("%s %d %d\n",t[i].playerName,t[i].score,t[i]. temps);
		sprintf(c,"%d",t[i].score);
		strcat(ch,c);
		strcat(ch,"\n");
	}
	
	txte.txt=TTF_RenderText_Blended(txte.police,ch,txte.color_txt);
	SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
	SDL_Flip(screen);	
}

//liberation

void liberer_musique(Mix_Music* music)
{
	Mix_FreeMusic(music);
}
void liberer_musiquebref(Mix_Chunk* mus)
{
	Mix_FreeChunk(mus);
}

void libererBack(Background b,texte txte)
{
	int j;
	//lib image
	int i=0;
	for(j=0;j<3;j++)
	{
		SDL_FreeSurface(b.imagebckg[i][j].img);
	}
	i=1;
	for(j=0;j<9;j++)
	{
		SDL_FreeSurface(b.imagebckg[i][j].img);
	}
	i=2;
	for(j=0;j<7;j++)
	{
		SDL_FreeSurface(b.imagebckg[i][j].img);
	}
	//liberer_musique(b.musicbckg[b.stage]);
	TTF_CloseFont(txte.police); 
	TTF_Quit ();
	
}





















