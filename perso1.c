#include "perso1.h"
void init_perso(personne *p )
{
	p->stop=IMG_Load("WALKING_RIGHT/standing.png");

	p->mat[0][0]=IMG_Load("WALKING_RIGHT/1.png");
	p->mat[0][1]=IMG_Load("WALKING_RIGHT/standing.png");
	p->mat[0][2]=IMG_Load("WALKING_RIGHT/2.png");

	p->mat[1][0]=IMG_Load("WALKING_LEFT/standing.png");
	p->mat[1][1]=IMG_Load("WALKING_LEFT/1.png");
	p->mat[1][2]=IMG_Load("WALKING_LEFT/2.png");
	p->mat[1][3]=IMG_Load("WALKING_LEFT/3.png");

	p->mat[2][0]=IMG_Load("JUMP_RIGHT/jr1.png");
	p->mat[2][1]=IMG_Load("JUMP_RIGHT/jr2.png");
	p->mat[2][2]=IMG_Load("JUMP_RIGHT/jr3.png");
	p->mat[2][3]=IMG_Load("JUMP_RIGHT/jr4.png");
	p->mat[2][4]=IMG_Load("JUMP_RIGHT/jr5.png");
	p->screen_pos.x=20;
	p->screen_pos.y=260;
	p->size.w=p->mat[0][0]->w; 
	p->size.h=p->mat[0][0]->h;
	p->size.x=0;
	p->size.y=150;
	p->direction=-1; 
	p->num=0;
	p->vie=100;
	p->vitesse=5;
	p->score=0;
	p->acceleration=0;
	p->detection_acceleration=0;
	p->espace=0;
	p->saut.x=-20;
	p->saut.y=p->screen_pos.x;
	p->pas=20;
}
void init_perso2(personne *p )
{
	p->stop=IMG_Load("WALK_RIGHT2/standing.png");
	p->mat[0][0]=IMG_Load("WALK_RIGHT2/1.png");
	p->mat[0][1]=IMG_Load("WALK_RIGHT2/standing.png");
	p->mat[0][2]=IMG_Load("WALK_RIGHT2/2.png");

	p->mat[1][0]=IMG_Load("WALK_LEFT2/standing.png");
	p->mat[1][1]=IMG_Load("WALK_LEFT2/1.png");
	p->mat[1][2]=IMG_Load("WALK_LEFT2/2.png");
	p->mat[1][3]=IMG_Load("WALK_LEFT2/3.png");
	p->mat[2][0]=IMG_Load("JUMP_RIGHT2/jr1.png");
	p->mat[2][1]=IMG_Load("JUMP_RIGHT2/jr2.png");
	p->mat[2][2]=IMG_Load("JUMP_RIGHT2/jr3.png");
	p->mat[2][3]=IMG_Load("JUMP_RIGHT2/jr4.png");
	//p->mat[4][4]=IMG_Load("JUMP_RIGHT/p2jr5.png");

	p->screen_pos.x=630;
	p->screen_pos.y=280;
	p->size.w=p->mat[0][0]->w; 
	p->size.h=p->mat[0][0]->h;
	p->size.x=0;
	p->size.y=0;
	p->direction=-1; 
	p->num=0;
	p->vie=100;
	p->vitesse=5;
	p->score=0;
	p->acceleration=0;
	p->detection_acceleration=0;
	p->espace=0;
	p->saut.x=-20;
	p->saut.y=0;
	p->pas=20;
}
void afficherPerso(personne p, SDL_Surface *screen)
{
	if(p.direction!=-1)
		SDL_BlitSurface(p.mat[p.direction][p.num], NULL, screen, &p.screen_pos);
	else
		SDL_BlitSurface(p.stop, NULL, screen, &p.screen_pos);
}
void animerPerso(personne *p) 
{
	if(p->direction==1||p->direction==2 ) 
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
	else
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
}
void deplacerPerso(personne *p)
{	
	SDL_Delay(80);
	switch(p->direction)
	{
		case 0:p->screen_pos.x+=p->pas;break;
		case 1:p->screen_pos.x-=p->pas;break;
	}
}

void saut(personne* p, int posx_absolu, int posy_absolu,int key[]) 
{
	p->saut.x+=5; 
	p->screen_pos.x=posx_absolu;
	p->screen_pos.y=posy_absolu;
	p->saut.y=(-0.03*(p->saut.x*p->saut.x)+120);
	p->screen_pos.x=p->screen_pos.x+p->saut.x+60;
	p->screen_pos.y=p->screen_pos.y-p->saut.y;
	printf("p->saut.x : %d\n",p->saut.x);
	if(p->saut.x>=20)
		{
			
			p->saut.x=-20;
		}
	if(p->direction ==1)
	{
		p->saut.x-=2; 
		p->screen_pos.x=-posx_absolu;
		p->screen_pos.y=posy_absolu;
		p->saut.y=(-0.05*(p->saut.x*p->saut.x)+120);
		p->screen_pos.x=-(p->screen_pos.x+p->saut.x+60);
		p->screen_pos.y=p->screen_pos.y-p->saut.y;
		if(p->saut.x>=50)
			{
				
				p->saut.x=-50;
			}
	}
			
	
}

