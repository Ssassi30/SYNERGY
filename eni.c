#include <SDL/SDL.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "eni.h"
void initenigme1(enigme1 *e)
{
	int j;
	for(j=0;j<4;j++)
	{
		char nom[15]="enigme";
		char c[2];
		
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		e->base[j].img = IMG_Load(nom);
		e->base[j].pos_img_ecran.x=0;
		e->base[j].pos_img_ecran.y=0;
		e->base[j].pos_img_affiche.x=0;
		e->base[j].pos_img_affiche.y=0;
		e->base[j].pos_img_affiche.h=500;
		e->base[j].pos_img_affiche.w=500;
		
	}
	e->l[0].imge.img = IMG_Load("enigmeS.png");
	e->l[0].imge.pos_img_ecran.x=50;
	e->l[0].imge.pos_img_ecran.y=350;
	e->l[0].imge.pos_img_affiche.x=0;
	e->l[0].imge.pos_img_affiche.y=0;
	e->l[0].imge.pos_img_affiche.h=50;
	e->l[0].imge.pos_img_affiche.w=50;
	e->l[0].r=5;
	e->l[0].q=-1;

	e->l[1].imge.img = IMG_Load("enigmeB.png");
	e->l[1].imge.pos_img_ecran.x=150;
	e->l[1].imge.pos_img_ecran.y=350;
	e->l[1].imge.pos_img_affiche.x=0;
	e->l[1].imge.pos_img_affiche.y=0;
	e->l[1].imge.pos_img_affiche.h=50;
	e->l[1].imge.pos_img_affiche.w=50;
	e->l[1].r=-1;
	e->l[1].q=-1;

	e->l[2].imge.img = IMG_Load("enigmeI.png");
	e->l[2].imge.pos_img_ecran.x=250;
	e->l[2].imge.pos_img_ecran.y=350;
	e->l[2].imge.pos_img_affiche.x=0;
	e->l[2].imge.pos_img_affiche.y=0;
	e->l[2].imge.pos_img_affiche.h=50;
	e->l[2].imge.pos_img_affiche.w=50;
	e->l[2].r=1;
	e->l[2].q=-1;

	e->l[3].imge.img = IMG_Load("enigmeH.png");
	e->l[3].imge.pos_img_ecran.x=350;
	e->l[3].imge.pos_img_ecran.y=350;
	e->l[3].imge.pos_img_affiche.x=0;
	e->l[3].imge.pos_img_affiche.y=0;
	e->l[3].imge.pos_img_affiche.h=50;
	e->l[3].imge.pos_img_affiche.w=50;
	e->l[3].r=3;
	e->l[3].q=-1;

	e->l[4].imge.img = IMG_Load("enigmeF.png");
	e->l[4].imge.pos_img_ecran.x=450;
	e->l[4].imge.pos_img_ecran.y=350;
	e->l[4].imge.pos_img_affiche.x=0;
	e->l[4].imge.pos_img_affiche.y=0;
	e->l[4].imge.pos_img_affiche.h=50;
	e->l[4].imge.pos_img_affiche.w=50;
	e->l[4].r=-1;
	e->l[4].q=-1;

	e->l[5].imge.img = IMG_Load("enigmeR.png");
	e->l[5].imge.pos_img_ecran.x=50;
	e->l[5].imge.pos_img_ecran.y=450;
	e->l[5].imge.pos_img_affiche.x=0;
	e->l[5].imge.pos_img_affiche.y=0;
	e->l[5].imge.pos_img_affiche.h=50;
	e->l[5].imge.pos_img_affiche.w=50;
	e->l[5].r=0;
	e->l[5].q=-1;

	e->l[6].imge.img = IMG_Load("enigmegg.png");
	e->l[6].imge.pos_img_ecran.x=150;
	e->l[6].imge.pos_img_ecran.y=450;
	e->l[5].imge.pos_img_affiche.x=0;
	e->l[6].imge.pos_img_affiche.y=0;
	e->l[6].imge.pos_img_affiche.h=50;
	e->l[6].imge.pos_img_affiche.w=50;
	e->l[6].r=2;
	e->l[6].q=-1;

	e->l[7].imge.img = IMG_Load("enigmeE.png");
	e->l[7].imge.pos_img_ecran.x=250;
	e->l[7].imge.pos_img_ecran.y=450;
	e->l[7].imge.pos_img_affiche.x=0;
	e->l[7].imge.pos_img_affiche.y=0;
	e->l[7].imge.pos_img_affiche.h=50;
	e->l[7].imge.pos_img_affiche.w=50;
	e->l[7].r=-1;
	e->l[7].q=-1;

	e->l[8].imge.img = IMG_Load("enigmeU.png");
	e->l[8].imge.pos_img_ecran.x=350;
	e->l[8].imge.pos_img_ecran.y=450;
	e->l[8].imge.pos_img_affiche.x=0;
	e->l[8].imge.pos_img_affiche.y=0;
	e->l[8].imge.pos_img_affiche.h=50;
	e->l[8].imge.pos_img_affiche.w=50;
	e->l[8].r=-1;
	e->l[8].q=-1;

	e->l[9].imge.img = IMG_Load("enigmeT.png");
	e->l[9].imge.pos_img_ecran.x=450;
	e->l[9].imge.pos_img_ecran.y=450;
	e->l[9].imge.pos_img_affiche.x=0;
	e->l[9].imge.pos_img_affiche.y=0;
	e->l[9].imge.pos_img_affiche.h=50;
	e->l[9].imge.pos_img_affiche.w=50;
	e->l[9].r=4;
	e->l[9].q=-1;

	e->resolu=0;
	int s=75;
	for(j=0;j<10;j++)
	{
		
		e->pos[j].y=250;
		e->pos[j].x=s;
		s+=75;
		e->pos[j].w=50;
		e->pos[j].h=50;
	}
}
//temps
void initialiser_temps(temps *t)
{
	(t->secondesEcoulees)=0;
	time(&(t->t1));
}
void afficher_temps(temps *t,SDL_Surface *screen)
{
	time(&(t->t2));
	t->secondesEcoulees = t->t2 - t->t1;
	t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	
}


void animerenigme1(enigme1 e,SDL_Surface *screen,int time)
{
	
	SDL_BlitSurface(e.base[(time)% 4].img,&e.base[(time)% 4].pos_img_affiche,screen,&e.base[(time)% 4].pos_img_ecran);

}

void afficherenigme1(enigme1 e,SDL_Surface *screen,int time)
{
	animerenigme1(e,screen, time);
	int j;
	for(j=0;j<10;j++)
	{
		
		if(e.l[j].q>-1)
		{
			SDL_BlitSurface(e.l[j].imge.img,&e.l[j].imge.pos_img_affiche,screen,&e.pos[e.l[j].q]);
		}
		else
		{
			SDL_BlitSurface(e.l[j].imge.img,&e.l[j].imge.pos_img_affiche,screen,&e.l[j].imge.pos_img_ecran);
		}
			
	}
}

int gagne1(enigme1 e)
{
	int i=0,test=1;
	while(i<10 && test==1)
	{
		if(e.l[i].q!=e.l[i].r) test=0;
		else i++;
	}
	return test;
}
void generer(enigme2 *e,char *nomfich)
{
	srand(time(NULL));
	FILE *F=fopen(nomfich,"r");
	int n=-1;
	if(F!=NULL)
	{
		int random_num=rand()%3 ;
		while(n!=random_num)
		{
			n++;
			fscanf(F,"%s %s %s %s %d\n",e->question,e->rep1,e->rep2,e->rep3,&e->numbr);	
		}
		fclose(F);
		//initialisation
		e->imgq=IMG_Load(e->question);	
		e->imgrep1=IMG_Load(e->rep1);	
		e->imgrep2=IMG_Load(e->rep2);
		e->imgrep3=IMG_Load(e->rep3);
		e->pos_img_ecranq.x=250;
		e->pos_img_ecranq.y=150;
		e->pos_img_ecranrep1.x=150;
		e->pos_img_ecranrep1.y=250;
		e->pos_img_ecranrep2.x=250;
		e->pos_img_ecranrep2.y=350;
		e->pos_img_ecranrep3.x=350;
		e->pos_img_ecranrep3.y=250;
	}
	else
		printf("ERREUR D'OUVERTURE DU FICHIER");
}
void afficherEnigme2(enigme2 e,SDL_Surface *screen)
{
	
	SDL_BlitSurface(e.imgq,NULL,screen,&e.pos_img_ecranq);
	SDL_BlitSurface(e.imgrep1,NULL,screen,&e.pos_img_ecranrep1);
	SDL_BlitSurface(e.imgrep2,NULL,screen,&e.pos_img_ecranrep2);
	SDL_BlitSurface(e.imgrep3,NULL,screen,&e.pos_img_ecranrep3);
}





















