#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"

void initmap(minimap *m)
{
	//chargement de l'image 
	m->url="minimap.png";
	m->img=IMG_Load(m->url);
	if (m->img==NULL)
	{
	printf("unable to load background image %s \n",SDL_GetError());
	return;
	}
	m->pos_img_ecran.x=680;
	m->pos_img_ecran.y=30;
	m->pos_img_affiche.x=0;
	m->pos_img_affiche.y=0;
	m->pos_img_affiche.h=690;
	m->pos_img_affiche.w=474;
	//chargement de l'image de bonhomme 2 
	m->url="ras.png";
	m->img2=IMG_Load(m->url);
	if (m->img2==NULL)
	{
	printf("unable to load background image %s \n",SDL_GetError());
	return;
	}
	m->pos_img2_ecran.x=680;
	m->pos_img2_ecran.y=130;
	m->pos_img2_affiche.x=0;
	m->pos_img2_affiche.y=0;
	m->pos_img2_affiche.h=50;
	m->pos_img2_affiche.w=50;
}
/*void MAJMinimap(SDL_Rect posjoueur ,minimap *m , SDL_Rect camera , int redimensionnement)
{
redimensionnement=20;
posJoueurABS.x=posjoueur.x+camera.x;
posJoueurABS.y=posjoueur.y+camera.y;
posbonhomme.x=posJoueurABS.x*redimensionnement/100;
posbonhomme.y=posJoueurABS.y*redimensionnement/100;
}*/

void afficherminimap(SDL_Surface *screen, minimap m)
{
	SDL_BlitSurface(m.img, &m.pos_img_affiche , screen, &m.pos_img_ecran);
	SDL_BlitSurface(m.img2, &m.pos_img2_affiche , screen, &m.pos_img2_ecran);
}

void liberer_minimap(minimap m)
{
	SDL_FreeSurface(m.img);
}
void avancer (minimap *m)
{
	float s=0.5;
	m->pos_img2_ecran.x=m->pos_img2_ecran.x+1;
}
void reculer (minimap *m)
{
	float s=0.5;
	m->pos_img2_ecran.x=m->pos_img2_ecran.x-1;
}
void avancerY (minimap *m)
{
	float s=0.5;
	m->pos_img2_ecran.y=m->pos_img2_ecran.y+1;
}
void reculerY (minimap *m)
{
	float s=0.5;
	m->pos_img2_ecran.y=m->pos_img2_ecran.y-1;
}
void obs(minimap *m)
{
	float s=0.5;
	m->pos_img2_ecran.x=m->pos_img2_ecran.x-s;
}
//Traitement texte
void initialiser_textee(texte *txte)
{
	TTF_Init();
	txte->police=TTF_OpenFont("Black Mustang.ttf",25);
	txte->color_txt.r=255;
	txte->color_txt.g=0;
	txte->color_txt.b=0;
	txte->pos_txt.x=50;
	txte->pos_txt.y=50;
	txte->s=0;
	txte->m=0;
	txte->h=0;
}

void animerMinimap  (minimap *m)
{
	int i;
	char nom[50];
	char num[2];
	for(i=0;i<4;i++)
	{
		sprintf(num,"%d",i);
		strcpy(nom,num);
		strcat(nom,".png");
		m->T[i].img=IMG_Load(nom);
		m->T[i].pos_img_ecran.x=700;
		m->T[i].pos_img_ecran.y=80;
		m->T[i].pos_img_affiche.x=0;
		m->T[i].pos_img_affiche.y=0;
		m->T[i].pos_img_affiche.h=20;
		m->T[i].pos_img_affiche.w=21;
	}
	if(i==4) i=0;
}
void afficheranimationENIGME(SDL_Surface *screen, image a)
{
	SDL_BlitSurface(a.img, &a.pos_img_affiche, screen, &a.pos_img_ecran);
}
//temps
void initialiser_temps(temps *t)
{
	 t->texte = NULL;
	 t->position.x=20;
	   t->position.y=20;
	     t->police = NULL;
	  t->police = TTF_OpenFont("Rough Simple.ttf", 60);
	    strcpy( t->entree,"");
	(t->secondesEcoulees)=0;
	time(&(t->t1));
}
void afficher_temps(temps *t,SDL_Surface *screen,int nb)
{
	SDL_Color couleur= {255, 255, 255};
	time(&(t->t2));
	t->secondesEcoulees = t->t2 - t->t1;
	t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	if (nb>0)
	{
		sprintf(t->entree,"%02d:%02d",t->min,t->sec);
		t->texte = TTF_RenderUTF8_Solid(t->police, t->entree,couleur);
		SDL_BlitSurface(t->texte, NULL, screen, &(t->position));
	}
}
void free_temps(temps *t,SDL_Surface *screen)
{
	SDL_FreeSurface(t->texte);
	 TTF_CloseFont(t->police);
}

void initialiser_Masque(image Masque[])
{
	(Masque+0)->img=SDL_LoadBMP("masque1.bmp");//colli1 solo stage0
	(Masque+1)->img=SDL_LoadBMP("masque2.bmp");//colli1 solo stage1

	(Masque+2)->img=SDL_LoadBMP("masque12.bmp");//multi stage0
	(Masque+3)->img=SDL_LoadBMP("masque2.bmp");//multi stage1
}
SDL_Color GetPixel(SDL_Surface *img, int x ,int y)
{
	SDL_Color color;
	Uint32 col=0;
	//det pos
	char* pPosition=(char*)img->pixels;
	pPosition+=(img->pitch *y);
	pPosition+=(img->format->BytesPerPixel*x);
	memcpy(&col,pPosition,img->format->BytesPerPixel);
	SDL_GetRGB(col,img->format,&color.r,&color.g,&color.b);
	return color;
}
//collision
int collisionPP(SDL_Rect perso ,SDL_Surface *img)
{
	int i=0;
	SDL_Rect pos[8];
	int collision=0, X,Y,W,H;
	SDL_Color couleur_obstacle;
	X=perso.x;
	Y=perso.y;
	H=perso.h;
	W=perso.w;
	pos[0].x=X;
	pos[0].y=Y;
	pos[1].x=X+W/2;
	pos[1].y=Y;
	pos[2].x=X+W;
	pos[2].y=Y;
	pos[3].x=X;
	pos[3].y=Y+H/2;
	pos[4].x=X;
	pos[4].y=Y+H;
	pos[5].x=X+W/2;
	pos[5].y=Y+H;
	pos[6].x=X+W;
	pos[6].y=Y+H;
	pos[7].x=X+W;
	pos[7].y=Y+H/2;
	couleur_obstacle.r=0;
	couleur_obstacle.g=0;
	couleur_obstacle.b=0;
	while(i<8 && collision ==0)
	{
		if(couleur_obstacle.r==GetPixel(img,pos[i].x,pos[i].y).r && couleur_obstacle.g==GetPixel(img,pos[i].x,pos[i].y).g && couleur_obstacle.b==GetPixel(img,pos[i].x,pos[i].y).b) collision =1;
		else i++;
	}

	return collision;
}

