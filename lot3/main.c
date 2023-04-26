#include "ES.h"
#include "bounding_box.h"

void quit(int *q)
{
Uint8 *keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_ESCAPE] ) (*q)=1;
}

int main()
{
ES es1,es2,es3;
SDL_Init(SDL_INIT_EVERYTHING);
srand( time( NULL ) );
SDL_Surface *screen =SDL_SetVideoMode(1483,859,32,SDL_SWSURFACE);
SDL_Surface *bg;
SDL_Rect pos;
pos.y=0;
bg=IMG_Load("bg.png");
init_es(&es1);
init_es(&es2);
init_es(&es3);
es2.pos.y=400;
es2.pos.x=1120;
es3.pos.y=500;
es3.pos.x=830;
int q=0;
while(q==0)
{

SDL_PumpEvents();
quit(&q);
SDL_Delay(50);
printf("%d\n",collision(es1.pos,es2.pos));
SDL_BlitSurface(bg,NULL,screen,&pos);
afficher_es(es1,screen);
animer_es(&es1);
afficher_es(es2,screen);
animer_es(&es2);
afficher_es(es3,screen);
animer_es(&es3);
mouvement_aleatoire(&es1);
mouvement_aleatoire2(&es2);
mouvement_aleatoire3(&es3);
SDL_Flip(screen);
}
}
