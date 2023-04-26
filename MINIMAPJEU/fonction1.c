#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction1.h"
void initialiser_imageBACK(image *image)
{
//chargement de l'image 
image->url="M.png";
image->img=IMG_Load(image->url);
if (image->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
image->pos_img_ecran.x=0;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;
}
void initialiser_Masque(image *Masque)
{
//chargement de l'image 
Masque->url="mini.png";
Masque->img=IMG_Load(Masque->url);
if (Masque->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
Masque->pos_img_ecran.x=600;
Masque->pos_img_ecran.y=0;
Masque->pos_img_affiche.x=0;
Masque->pos_img_affiche.y=0;
Masque->pos_img_affiche.h=SCREEN_H;
Masque->pos_img_affiche.w=SCREEN_W;
}
void initmap(minimap *m)
{
//chargement de l'image 
m->url="mini.png";
m->img=IMG_Load(m->url);
if (m->img==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
m->pos_img_ecran.x=500;
m->pos_img_ecran.y=0;
m->pos_img_affiche.x=0;
m->pos_img_affiche.y=0;
m->pos_img_affiche.h=SCREEN_H;
m->pos_img_affiche.w=SCREEN_W;
//chargement de l'image de bonhomme 2 
m->url="tete.png";
m->img2=IMG_Load(m->url);
if (m->img2==NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}
m->pos_img2_ecran.x=700;
m->pos_img2_ecran.y=160;
m->pos_img2_affiche.x=0;
m->pos_img2_affiche.y=0;
m->pos_img2_affiche.h=SCREEN_H;
m->pos_img2_affiche.w=SCREEN_W;
}
/*void MAJMinimap(SDL_Rect posjoueur ,minimap *m , SDL_Rect camera , int redimensionnement)
{
redimensionnement=20;
posJoueurABS.x=posjoueur.x+camera.x;
posJoueurABS.y=posjoueur.y+camera.y;
posbonhomme.x=posJoueurABS.x*redimensionnement/100;
posbonhomme.y=posJoueurABS.y*redimensionnement/100;
}*/
void afficher_imageBACK(SDL_Surface *screen, image imge)
{
//coller et afficher l'image du back dans screen
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}
void afficherminimap(SDL_Surface *screen, minimap m)
{
//coller et afficher l'image du back dans screen
SDL_BlitSurface(m.img, &m.pos_img_affiche , screen, &m.pos_img_ecran);
SDL_BlitSurface(m.img2, &m.pos_img2_affiche , screen, &m.pos_img2_ecran);
}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}
void liberer_minimap(minimap m)
{
SDL_FreeSurface(m.img);
}
void avancer (minimap *m)
{
float s=0.5;
m->pos_img2_ecran.x=m->pos_img2_ecran.x+2;
}
void reculer (minimap *m)
{
float s=0.5;
m->pos_img2_ecran.x=m->pos_img2_ecran.x-2;
}
void avancerY (minimap *m)
{
float s=0.5;
m->pos_img2_ecran.y=m->pos_img2_ecran.y+2;
}
void reculerY (minimap *m)
{
float s=0.5;
m->pos_img2_ecran.y=m->pos_img2_ecran.y-2;
}
void obs(minimap *m)
{
float s=0.5;
m->pos_img2_ecran.x=m->pos_img2_ecran.x-2;
}
//Traitement texte
void initialiser_texte(texte *txte)
{
TTF_Init();
txte->police=TTF_OpenFont("Black Mustang.ttf",45);
txte->color_txt.r=255;
txte->color_txt.g=0;
txte->color_txt.b=0;
txte->pos_txt.x=0;
txte->pos_txt.y=20;
txte->s=0;
txte->m=0;
txte->h=0;
}
void afficher_texte(SDL_Surface *screen,char temps1[],texte txte)
{ 

txte.txt=TTF_RenderText_Blended(txte.police,temps1,txte.color_txt);
SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}
void liberer_texte(texte txte)
{
TTF_CloseFont(txte.police); 
TTF_Quit ();
}
//animation vid 
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
m->T[i].pos_img_ecran.x=807;
m->T[i].pos_img_ecran.y=165;
m->T[i].pos_img_affiche.x=0;
m->T[i].pos_img_affiche.y=0;
m->T[i].pos_img_affiche.h=SCREEN_H;
m->T[i].pos_img_affiche.w=SCREEN_W;
}
if(i==4) i=0;
}
void afficheranimationENIGME(SDL_Surface *screen, image a)
{
SDL_BlitSurface(a.img, &a.pos_img_affiche, screen, &a.pos_img_ecran);
}
void initialiser_temps(temps *t)
{
 t->texte = NULL;
 t->position.x=0;
   t->position.y=20;
     t->police = NULL;
  t->police = TTF_OpenFont("Black Mustang.ttf", 40);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1));
}
void afficher_temps(temps *t,SDL_Surface *screen)
{
SDL_Color couleur= {255, 255, 255};
time(&(t->t2));
t->secondesEcoulees = t->t2 - t->t1;
t->min=((t->secondesEcoulees/60)%60);
t->sec= ((t->secondesEcoulees)%60);
sprintf(t->entree,"%02d:%02d",t->min,t->sec);
t->texte = TTF_RenderUTF8_Solid(t->police, t->entree,couleur);
SDL_BlitSurface(t->texte, NULL, screen, &(t->position));
}
SDL_Color GetPixel(SDL_Surface *Masque, int x ,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*)Masque->pixels;
pPosition+=(Masque->pitch *y);
pPosition+=(Masque->format->BytesPerPixel*x);
memcpy(&col,pPosition,Masque->format->BytesPerPixel);
SDL_GetRGB(col,Masque->format,&color.r,&color.g,&color.b);
return color;
}
//collision
int collisionPP(minimap m ,SDL_Surface *Masque)
{
int collision, X,Y,W,H;
SDL_Color Pos1,Pos2,Pos3,Pos4,Pos5,Pos6,Pos7,Pos8;
X=m.pos_img2_ecran.x;
Y=m.pos_img2_ecran.y;
H=m.pos_img2_affiche.h;
W=m.pos_img2_affiche.w;
Pos1=GetPixel(m.img2,X,Y);
Pos2=GetPixel(m.img2,X+W/2,Y);
Pos3=GetPixel(m.img2,X+W,Y);
Pos4=GetPixel(m.img2,X,Y+H/2);
Pos5=GetPixel(m.img2,X,Y+H);
Pos6=GetPixel(m.img2,X+W/2,Y+H);
Pos7=GetPixel(m.img2,X+W,Y+H);
Pos8=GetPixel(m.img2,X+W,Y+H/2);
while ( Pos1.r!=0 && Pos1.g!=0 && Pos1.b!=0 
      ||Pos2.r!=0 && Pos2.g!=0 && Pos2.b!=0
      ||Pos3.r!=0 && Pos2.g!=0 && Pos3.b!=0
      ||Pos4.r!=0 && Pos2.g!=0 && Pos4.b!=0
      ||Pos5.r!=0 && Pos2.g!=0 && Pos5.b!=0
      ||Pos6.r!=0 && Pos2.g!=0 && Pos6.b!=0
      ||Pos7.r!=0 && Pos2.g!=0 && Pos7.b!=0
      ||Pos8.r!=0 && Pos2.g!=0 && Pos8.b!=0)
{
return 0;
}
return 1;
}
//musique et son bref
void initialiser_audiobref(Mix_Chunk *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music=Mix_LoadWAV("cri.wav");
Mix_PlayChannel(-1,music,0);
if(music==NULL) 
printf("%s",SDL_GetError());
}
void liberer_musiquebref(Mix_Chunk *music)
{
Mix_FreeChunk(music);
}
