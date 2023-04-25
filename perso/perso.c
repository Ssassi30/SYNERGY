#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include "perso.h"
void initialiser_imageBACK(image *background)
{

	background->img_url=IMG_Load("plan1.jpg");
	if (background->img_url== NULL)
		{
    			printf("unable to load background image %s \n",SDL_GetError());
    			return;
		}
	background->pos_img_ecran.x=0;
	background->pos_img_ecran.y=0;
	background->pos_img_affiche.x=0;
	background->pos_img_affiche.y=0;
	background->pos_img_affiche.h=background->img_url->h;
	background->pos_img_affiche.w=background->img_url->w;
	
}
void initialiser_imageBTN(image *imgbtn,char *name,int x,int y)
{

	imgbtn->img_url=IMG_Load(name);
	if (imgbtn->img_url == NULL)
		{
    			printf("unable to load btn image %s \n",SDL_GetError());
    			return ;
		}
	imgbtn->pos_img_ecran.x=0;
	imgbtn->pos_img_ecran.y=0;
	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->pos_img_affiche.h=340;
	imgbtn->pos_img_affiche.w=120;

	
}
void afficher_image(SDL_Surface *screen, image imge)
{
	SDL_BlitSurface(imge.img_url, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
	SDL_FreeSurface(imge.img_url);
}
/* -------------------------------------------perso--------------------------------------------------*/
void init_perso(personne *p , int xi , int yi)
{
	p->mat[0][0]=IMG_Load("WALKING_RIGHT/1.png");
	p->mat[0][1]=IMG_Load("WALKING_RIGHT/standing.png");
	p->mat[0][2]=IMG_Load("WALKING_RIGHT/2.png");

	p->mat[1][0]=IMG_Load("WALKING_LEFT/standing.png");
	p->mat[1][1]=IMG_Load("WALKING_LEFT/1.png");
	p->mat[1][2]=IMG_Load("WALKING_LEFT/2.png");
	p->mat[1][3]=IMG_Load("WALKING_LEFT/3.png");
	

	p->mat[2][0]=IMG_Load("WALKING_UP/1.png");
	p->mat[2][1]=IMG_Load("WALKING_UP/2.png");
	p->mat[2][2]=IMG_Load("WALKING_UP/3.png");
	p->mat[2][3]=IMG_Load("WALKING_UP/4.png");
	p->mat[2][4]=IMG_Load("WALKING_UP/5.png");
	p->mat[2][5]=IMG_Load("WALKING_UP/6.png");

	p->mat[3][0]=IMG_Load("WALKING_DOWN/wd1.png");
	p->mat[3][1]=IMG_Load("WALKING_DOWN/wd2.png");
	p->mat[3][2]=IMG_Load("WALKING_DOWN/wd3.png");

	p->mat[4][0]=IMG_Load("JUMP_RIGHT/jr1.png");
	p->mat[4][1]=IMG_Load("JUMP_RIGHT/jr2.png");
	p->mat[4][2]=IMG_Load("JUMP_RIGHT/jr3.png");
	p->mat[4][3]=IMG_Load("JUMP_RIGHT/jr4.png");
	p->mat[4][4]=IMG_Load("JUMP_RIGHT/jr5.png");



p->screen_pos.x=xi;
p->screen_pos.y=yi;
p->size.w=p->mat[0][0]->w; 
p->size.h=p->mat[0][0]->h;
p->size.x=0;
p->size.y=0;
p->direction=0; 
p->num=0;
p->vie=100;
p->vitesse=5;
p->score=0;
p->acceleration=0;
p->detection_acceleration=0;
p->espace=0;
p->saut.x=-50;
p->saut.y=0;
}

void afficherPerso(personne p, SDL_Surface *screen)
{
	SDL_BlitSurface(p.mat[p.direction][p.num], &p.size, screen, &p.screen_pos);
}



void deplacerPerso(personne *p, Uint32 dt)
{
   double dx;
	dx=((0.5*p->acceleration)*(dt*dt))+(p->vitesse*dt);
	
	dx=dx-365; 
	
		
	
	if (p->direction==0 )
		{
			p->screen_pos.x+=dx;
		}
	else if(p->direction==1)
		{
			p->screen_pos.x-=dx;
			
		}
	else if(p->direction==4)
		{
			p->screen_pos.y+=dx;
printf("4");
		}
	else if(p->direction==3)
		{
			p->screen_pos.y+=dx;
		}
	else if(p->direction==2)
		{
			p->screen_pos.y-=dx;
		}
		
}
void animerPerso(personne *p) 
{
	if(p->direction==0 || p->direction==1 || p->direction==4 ) 
		{
			if(p->num==2) 
				{
					p->num=0;
			
				}
			else               
				{
					p->num++;
			
				}
		}
	else
		{
			if(p->num==3)
				{
					p->num=0;
			
				}
			else
				{
					p->num++;
			
				}	
	
		}
}

void saut(personne* p, int posx_absolu, int posy_absolu) 
{
		
	if(p->espace==1)
		{
			p->saut.x+=2;  
			p->screen_pos.x=posx_absolu;
			p->screen_pos.y=posy_absolu;
			p->saut.y=(-0.05*(p->saut.x*p->saut.x)+100); 
			//printf("saut = %d",p->saut.y);
			p->screen_pos.x=p->screen_pos.x+p->saut.x+50;
			p->screen_pos.y=p->screen_pos.y-p->saut.y;
			
			if(p->saut.x>=50) 
				{
					
					p->saut.x=-50; 
					p->espace=0; 
				}
				
		}
}

 /*-----------------------------------------------------------------------------------------------------------------*/
//fonctions de texte
void initialiser_texte(texte *txte)
{
	TTF_Init();
	txte->police = TTF_OpenFont("times.ttf", 30);
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=255;
	txte->pos_txt.x=120;
	txte->pos_txt.y=20;

}
void afficher_texte(SDL_Surface *screen , texte txte,personne p)
{
	char c[6];
	sprintf(c,"%d",p.score);
	txte.txt=TTF_RenderText_Blended(txte.police,c,txte.color_txt);
	SDL_BlitSurface (txte.txt, NULL, screen,&txte.pos_txt);
}
void liberer_texte(texte txte)
{
	TTF_CloseFont(txte.police);
	TTF_Quit();
}





