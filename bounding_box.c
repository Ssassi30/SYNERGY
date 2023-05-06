#include "bounding_box.h"

void cadrage(cadre *c,Background b,personne p1,personne p2,ES es1,ES es2,int nb)
{
	c->perso1.x=p1.screen_pos.x+b.camera_pos1.x;
	c->perso1.y=p1.screen_pos.y+b.camera_pos1.y;
	c->perso1.w=p1.size.w;
	c->perso1.h=p1.size.h;
	c->police1.x=es1.pos.x+b.camera_pos1.x;
	c->police2.x=es2.pos.x+b.camera_pos1.x;
	c->police1.y=es1.pos.y+b.camera_pos1.y;
	c->police2.y=es2.pos.y+b.camera_pos1.y;
	if(nb==2)
	{
		c->perso2.x=p2.screen_pos.x+b.camera_pos2.x;
		c->perso2.y=p2.screen_pos.y+b.camera_pos2.y;
		c->perso2.w=p2.size.w;
		c->perso2.h=p2.size.h;	
		c->cam2.x=b.camera_pos2.x+600;
		c->cam2.y=b.camera_pos2.y;
		c->cam2.w=b.camera_pos2.w;
		c->cam2.h=b.camera_pos2.h;
	}
}
int box(SDL_Rect x1,SDL_Rect x2) //x2 wst x1
{
	int t=0;
	if((x1.x<=x2.x)&&(x1.y<=x2.y)&&(x1.x + x1.w >= x2.x + x2.w) &&(x1.y + x1.h >= x2.y + x2.h))
		t=1;
	return t;
}
