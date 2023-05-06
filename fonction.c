#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
void initialiserTic(tic *t)
{
//chargement BACKGROUND 
t->url="PLAN.png";
t->img1=IMG_Load(t->url);
if (t->img1==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
t->pos_img1_ecran.x=0;
t->pos_img1_ecran.y=0;
t->pos_img1_affiche.x=0;
t->pos_img1_affiche.y=0;
t->pos_img1_affiche.h=SCREEN_H;
t->pos_img1_affiche.w=SCREEN_W;
//chargement X
t->url="CROIX.png";
t->img2=IMG_Load(t->url);
if (t->img2==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
t->pos_img2_ecran.x=120;
t->pos_img2_ecran.y=100;
t->pos_img2_affiche.x=0;
t->pos_img2_affiche.y=0;
t->pos_img2_affiche.h=SCREEN_H;
t->pos_img2_affiche.w=SCREEN_W;
//chargement DRAP
t->url="DRAP.png";
t->img3=IMG_Load(t->url);
if (t->img3==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
t->pos_img3_ecran.x=117;
t->pos_img3_ecran.y=270;
t->pos_img3_affiche.x=0;
t->pos_img3_affiche.y=0;
t->pos_img3_affiche.h=SCREEN_H;
t->pos_img3_affiche.w=SCREEN_W;
//init case TAB 0;
for (int i=0;i<9;i++)
{
t->T[i]=0;
}
//init num JOUEUR ;
t->j1=1;
//init TOUR ;
t->Tour;
//init TEXTE;
TTF_Init();
t->police=TTF_OpenFont("Black Mustang.ttf",45);
t->color_txt.r=255;
t->color_txt.g=255;
t->color_txt.b=255;
t->pos_txt.x=180;
t->pos_txt.y=20;
}
void afficherTic(tic t ,SDL_Surface *screen)
{
//coller et afficher l'image du back dans screen
SDL_BlitSurface(t.img1, &t.pos_img1_affiche , screen, &t.pos_img1_ecran);
SDL_BlitSurface(t.img2, &t.pos_img2_affiche , screen, &t.pos_img2_ecran);
SDL_BlitSurface(t.img3, &t.pos_img3_affiche , screen, &t.pos_img3_ecran);
}
void init_image(image *Masque)
{
//chargement de l'image 
Masque->url="CROIX.png";
Masque->img=IMG_Load(Masque->url);
if (Masque->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
Masque->pos_img_ecran.x=0;
Masque->pos_img_ecran.y=0;
Masque->pos_img_affiche.x=0;
Masque->pos_img_affiche.y=0;
Masque->pos_img_affiche.h=SCREEN_H;
Masque->pos_img_affiche.w=SCREEN_W;
}
void init_image1(image *Masque2)
{
//chargement de l'image 
Masque2->url="DRAP.png";
Masque2->img=IMG_Load(Masque2->url);
if (Masque2->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
Masque2->pos_img_ecran.x=0;
Masque2->pos_img_ecran.y=0;
Masque2->pos_img_affiche.x=0;
Masque2->pos_img_affiche.y=0;
Masque2->pos_img_affiche.h=SCREEN_H;
Masque2->pos_img_affiche.w=SCREEN_W;
}
void afficher_image(SDL_Surface *screen, image imge)
{
//coller et afficher l'image du back dans screen
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}
void afficher_texte(tic t,SDL_Surface *screen)
{
t.txt = TTF_RenderText_Blended(t.police,"SECONDES RESTANTES ",t.color_txt);
SDL_BlitSurface(t.txt, NULL, screen, &t.pos_txt);
}
void initialiser_temps(temps *T)
{
 T->texte = NULL;
 T->position.x=520;
   T->position.y=22;
     T->police = NULL;
  T->police = TTF_OpenFont("Black Mustang.ttf", 40);
    strcpy( T->entree,"");
(T->secondesEcoulees)=0;
time(&(T->t1));
}
void afficher_temps(temps *T,SDL_Surface *screen)
{
SDL_Color couleur= {255, 255, 255};
time(&(T->t2));
T->secondesEcoulees = T->t2 - T->t1;
T->sec= ((T->secondesEcoulees)%60);
sprintf(T->entree,": %02d",30-T->sec);
T->texte = TTF_RenderUTF8_Solid(T->police, T->entree,couleur);
SDL_BlitSurface(T->texte, NULL, screen, &(T->position));
}
//fonctions 
int atilgagner(int tabSuivi[]){
int i;
    int tabG[8][3]={{0, 1, 2},{0, 4, 8}, {3, 4, 5},{6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {2, 4, 6}};
for (i=0;i<8;i++)
{
        if(tabSuivi[tabG[i][0]]==tabG[tabG[i][1]]&&tabSuivi[tabG[i][1]]==tabSuivi[tabG[i][2]]);
}
return tabSuivi[tabG[i][0]];
}
void Resultat(tic t,SDL_Surface * screen){
    char message[100];
    if(atilgagner(t.T)==1)
        strcpy(message,"Défaite");
    else if(atilgagner(t.T)==-1)
        strcpy(message,"victoire");
    else
        strcpy(message,"Nul");
t.txt = TTF_RenderText_Blended(t.police,message,t.color_txt);
SDL_BlitSurface(t.txt, NULL, screen, &t.pos_txt);
}
int minimax(int T[9] , int Joueur)
{
	int gagnant=atilgagner(T);
	if(gagnant!=0)
	return gagnant*Joueur;
	int coup=-1;
	int score=-2;
	int i;
	for(i=0;i<9;i++)
	{
	if(T[i]==0)
	{
	T[i]=Joueur;
	int mmscore=-minimax(T,Joueur*-1);
	if(mmscore>score)
	{
	score=mmscore;
	coup=i;
	}
	T[i]=0;
	}
	}
	if(coup==-1)
	return 0;
	return score;
}
void calcul_coup (int T[9])
{
	int coup=-1;
	int score=-2;
	int i;
	for(i=0;i<9;i++)
	{
	if (T[i]==0)
	{
	T[i]=1;
	int mmscore=-minimax(T,-1);
	T[i]=0;
	if (mmscore>score)
	{
	score=mmscore;
	coup=i;
	}
	T[i]=0;
	}
	}
	if(coup==-1)
	{
	return 0;
	}
	return score;
}
//liberation
void liberer (tic t)
{
SDL_FreeSurface(t.img1);
SDL_FreeSurface(t.img2);
SDL_FreeSurface(t.img3);
//texte
TTF_CloseFont(t.police); 
TTF_Quit ();
}
