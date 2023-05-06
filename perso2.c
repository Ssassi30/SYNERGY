#include "perso2.h"
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
	p->screen_pos.x=0;
	p->screen_pos.y=260;
	p->size.w=p->mat[0][0]->w; 
	p->size.h=p->mat[0][0]->h;
	p->size.x=0;
	p->size.y=150;
	p->direction=-1; 
	p->num=0;
	p->vie=100;
	p->vitesse=0.2;
	p->score=0;
	p->acceleration=0;
	p->detection_acceleration=0;
	p->espace=0;
	p->saut.x=-50;
	p->saut.y=0;
	p->pas=30;
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
	p->saut.x=-50;
	p->saut.y=0;
	p->pas=30;
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
	if(p->espace!=1 ) 
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
void deplacerPerso(personne *p1,personne *p2,int nb,int key[],Uint32 t_prev,int colli1,int colli2,int box1,int box2)
{	
	if(key[SDLK_RIGHT])
	{
		SDL_Delay(80);
		switch(colli1)
		{
			case 0:p1->direction=0;break;
			case 1:p1->direction=1;break;
		}
		animerPerso(&(*p1));
	}
	else if(key[SDLK_LEFT])
	{
		SDL_Delay(80);
		switch(colli1)
		{
			case 0:p1->direction=1;break;
			case 1:p1->direction=0;break;
		}
		animerPerso(&(*p1));
	}
	if(box1==1)
	{
		switch(p1->direction)
		{
			case 0:p1->screen_pos.x+=p1->pas;break;
			case 1:p1->screen_pos.x-=p1->pas;break;
		}
	}
	if(nb==2)
	{
		if(key[SDLK_d])
		{
			SDL_Delay(80);
			switch(colli2)
			{
				case 0:p2->direction=0;break;
				case 1:p2->direction=1;break;
			}
			animerPerso(&(*p2));
		}
		else if(key[SDLK_g])
		{
			SDL_Delay(80);
			switch(colli2)
			{
				case 0:p2->direction=1;break;
				case 1:p2->direction=0;break;
			}
			animerPerso(&(*p2));
		}
		if(box2==1)
		{
			switch(p2->direction)
			{
				case 0:p2->screen_pos.x+=p2->pas;break;
				case 1:p2->screen_pos.x-=p2->pas;break;
			}
		}
	}
}

void saut(personne* p1,personne *p2,int nb,int key[]) 
{
	
	switch(nb)
	{
		case 1: 
			if(key[SDLK_UP]==0)
			{
				SDL_Delay(50);
				p1->espace=1;
				p1->direction=2;
				
			}
			break;
		case 2:			if(key[SDLK_SPACE])
			{
				
				p2->espace=1;
			}
			break;
	}
	if(p1->espace==1)
	{
		p1->saut.x+=2; 
		p1->saut.y=(-0.05*(p1->saut.x*p1->saut.x)+120);
		p1->screen_pos.x=p1->screen_pos.x+p1->saut.x+60;
		p1->screen_pos.y=p1->screen_pos.y-p1->saut.y;
		animerPerso(&(*p1));
		if(p1->saut.x>=50)
		{
			
			p1->saut.x=-50;
		}
		if(p1->direction ==1)
		{
			p1->saut.x-=2; 
			p1->saut.y=(-0.05*(p1->saut.x*p1->saut.x)+120);
			p1->screen_pos.x=-(p1->screen_pos.x+p1->saut.x+60);
			p1->screen_pos.y=p1->screen_pos.y-p1->saut.y;
			if(p1->saut.x>=50)
			{
				
				p1->saut.x=-50;
			}
		}
				
	}
	
}
