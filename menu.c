#include "menu.h"
void initialiser_audiobref(Mix_Chunk* mus)
{
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	mus = Mix_LoadWAV("Selection.wav");
	Mix_PlayChannel(-1,mus,0);
	if(mus == NULL) printf("%s",SDL_GetError());
}
void initialiser_audio(Mix_Music* music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",SDL_GetError());
	}
	music=Mix_LoadMUS("menu.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
}
void initialiser_texte(texte *txte)
{

	TTF_Init();

	txte->police=TTF_OpenFont("Rough Simple.ttf",50);
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=255;
}
void initialisermenu(menu *m,option *o, play *p, quit *q,score *s)
{
	int j;
	for(j=1;j<=5;j++)
	{
		char nom[10]="m";
		char c[2];
		sprintf(c,"%d",j);
		strcat(nom,c);
		strcat(nom,".png\0");
		m->anim[j-1].img = IMG_Load(nom);
		m->anim[j-1].pos_img_ecran.x=0;
		m->anim[j-1].pos_img_ecran.y=0;
		m->anim[j-1].pos_img_affiche.x=0;
		m->anim[j-1].pos_img_affiche.y=0;
		m->anim[j-1].pos_img_affiche.h=1000;
		m->anim[j-1].pos_img_affiche.w=1900;		
	}
	m->bm[0][0].img = IMG_Load("play1.png");
	m->bm[0][0].pos_img_ecran.x=900;
	m->bm[0][0].pos_img_ecran.y=200;
	m->bm[0][0].pos_img_affiche.x=0;
	m->bm[0][0].pos_img_affiche.y=0;
	m->bm[0][1].img = IMG_Load("play11.png");
	m->bm[0][1].pos_img_ecran.x=900;
	m->bm[0][1].pos_img_ecran.y=200;
	m->bm[0][1].pos_img_affiche.x=0;
	m->bm[0][1].pos_img_affiche.y=0;
	m->bm[1][0].img = IMG_Load("option1.png");
	m->bm[1][0].pos_img_ecran.x=900;
	m->bm[1][0].pos_img_ecran.y=300;
	m->bm[1][0].pos_img_affiche.x=0;
	m->bm[1][0].pos_img_affiche.y=0;
	m->bm[1][1].img = IMG_Load("option11.png");
	m->bm[1][1].pos_img_ecran.x=900;
	m->bm[1][1].pos_img_ecran.y=300;
	m->bm[1][1].pos_img_affiche.x=0;
	m->bm[1][1].pos_img_affiche.y=0;
	m->bm[2][0].img = IMG_Load("score1.png");
	m->bm[2][0].pos_img_ecran.x=900;
	m->bm[2][0].pos_img_ecran.y=400;
	m->bm[2][0].pos_img_affiche.x=0;
	m->bm[2][0].pos_img_affiche.y=0;
	m->bm[2][1].img = IMG_Load("score11.png");
	m->bm[2][1].pos_img_ecran.x=900;
	m->bm[2][1].pos_img_ecran.y=400;
	m->bm[2][1].pos_img_affiche.x=0;
	m->bm[2][1].pos_img_affiche.y=0;
	m->bm[3][0].img = IMG_Load("quit1.png");
	m->bm[3][0].pos_img_ecran.x=900;
	m->bm[3][0].pos_img_ecran.y=500;
	m->bm[3][0].pos_img_affiche.x=0;
	m->bm[3][0].pos_img_affiche.y=0;
	m->bm[3][1].img = IMG_Load("quit11.png");
	m->bm[3][1].pos_img_ecran.x=900;
	m->bm[3][1].pos_img_ecran.y=500;
	m->bm[3][1].pos_img_affiche.x=0;
	m->bm[3][1].pos_img_affiche.y=0;
	m->onm=-1;
	
	o->op.img = IMG_Load("option.png");
	o->op.pos_img_ecran.x=0;
	o->op.pos_img_ecran.y=0;
	o->op.pos_img_affiche.x=0;
	o->op.pos_img_affiche.y=0;
	initialiser_texte(&(o->txte[1]));
	o->txte[1].pos_txt.x=700;
	o->txte[1].pos_txt.y=50;
	o->bo[0][0].img = IMG_Load("full1.png");
	o->bo[0][0].pos_img_ecran.x=500;
	o->bo[0][0].pos_img_ecran.y=150;
	o->bo[0][0].pos_img_affiche.x=0;
	o->bo[0][0].pos_img_affiche.y=0;
	o->bo[0][1].img = IMG_Load("full11.png");
	o->bo[0][1].pos_img_ecran.x=500;
	o->bo[0][1].pos_img_ecran.y=150;
	o->bo[0][1].pos_img_affiche.x=0;
	o->bo[0][1].pos_img_affiche.y=0;
	o->bo[1][0].img = IMG_Load("normal1.png");
	o->bo[1][0].pos_img_ecran.x=850;
	o->bo[1][0].pos_img_ecran.y=150;
	o->bo[1][0].pos_img_affiche.x=0;
	o->bo[1][0].pos_img_affiche.y=0;
	o->bo[1][1].img = IMG_Load("normal11.png");
	o->bo[1][1].pos_img_ecran.x=850;
	o->bo[1][1].pos_img_ecran.y=150;
	o->bo[1][1].pos_img_affiche.x=0;
	o->bo[1][1].pos_img_affiche.y=0;
	initialiser_texte(&(o->txte[2]));
	o->txte[2].pos_txt.x=750;
	o->txte[2].pos_txt.y=350;
	o->bo[2][0].img = IMG_Load("manette0.png");
	o->bo[2][0].pos_img_ecran.x=500;
	o->bo[2][0].pos_img_ecran.y=400;
	o->bo[2][0].pos_img_affiche.x=0;
	o->bo[2][0].pos_img_affiche.y=0;
	o->bo[2][1].img = IMG_Load("manette1.png");
	o->bo[2][1].pos_img_ecran.x=500;
	o->bo[2][1].pos_img_ecran.y=400;
	o->bo[2][1].pos_img_affiche.x=0;
	o->bo[2][1].pos_img_affiche.y=0;
	o->bo[3][0].img = IMG_Load("clavier0.png");
	o->bo[3][0].pos_img_ecran.x=850;
	o->bo[3][0].pos_img_ecran.y=437;
	o->bo[3][0].pos_img_affiche.x=0;
	o->bo[3][0].pos_img_affiche.y=0;
	o->bo[3][1].img = IMG_Load("clavier1.png");
	o->bo[3][1].pos_img_ecran.x=850;
	o->bo[3][1].pos_img_ecran.y=437;
	o->bo[3][1].pos_img_affiche.x=0;
	o->bo[3][1].pos_img_affiche.y=0;
	o->v[0].img = IMG_Load("volume0.png");
	o->v[0].pos_img_ecran.x=50;
	o->v[0].pos_img_ecran.y=300;
	o->v[0].pos_img_affiche.x=0;
	o->v[0].pos_img_affiche.y=0;
	o->v[1].img = IMG_Load("volume25.png");
	o->v[1].pos_img_ecran.x=50;
	o->v[1].pos_img_ecran.y=300;
	o->v[1].pos_img_affiche.x=0;
	o->v[1].pos_img_affiche.y=0;	
	o->v[2].img = IMG_Load("volume50.png");
	o->v[2].pos_img_ecran.x=50;
	o->v[2].pos_img_ecran.y=300;
	o->v[2].pos_img_affiche.x=0;
	o->v[2].pos_img_affiche.y=0;
	o->v[3].img = IMG_Load("volume75.png");
	o->v[3].pos_img_ecran.x=50;
	o->v[3].pos_img_ecran.y=300;
	o->v[3].pos_img_affiche.x=0;
	o->v[3].pos_img_affiche.y=0;
	o->v[4].img = IMG_Load("volume100.png");
	o->v[4].pos_img_ecran.x=50;
	o->v[4].pos_img_ecran.y=300;
	o->v[4].pos_img_affiche.x=0;
	o->v[4].pos_img_affiche.y=0;
	initialiser_texte(&(o->txte[0]));
	o->txte[0].pos_txt.x=50;
	o->txte[0].pos_txt.y=270;
	o->re[0].img = IMG_Load("returnn1.png");
	o->re[0].pos_img_ecran.x=20;
	o->re[0].pos_img_ecran.y=20;
	o->re[0].pos_img_affiche.x=0;
	o->re[0].pos_img_affiche.y=0;
	o->re[1].img = IMG_Load("returnn11.png");
	o->re[1].pos_img_ecran.x=20;
	o->re[1].pos_img_ecran.y=20;
	o->re[1].pos_img_affiche.x=0;
	o->re[1].pos_img_affiche.y=0;
	o->ono=0;
	


	s->sc.img = IMG_Load("scores.jpg");
	s->sc.pos_img_ecran.x=0;
	s->sc.pos_img_ecran.y=0;
	s->sc.pos_img_affiche.x=0;
	s->sc.pos_img_affiche.y=0;
	s->re[0].img = IMG_Load("returnn1.png");
	s->re[0].pos_img_ecran.x=20;
	s->re[0].pos_img_ecran.y=20;
	s->re[0].pos_img_affiche.x=0;
	s->re[0].pos_img_affiche.y=0;
	s->re[1].img = IMG_Load("returnn11.png");
	s->re[1].pos_img_ecran.x=20;
	s->re[1].pos_img_ecran.y=20;
	s->re[1].pos_img_affiche.x=0;
	s->re[1].pos_img_affiche.y=0;

	p->pl.img = IMG_Load("play.png");
	p->pl.pos_img_ecran.x=0;
	p->pl.pos_img_ecran.y=0;
	p->pl.pos_img_affiche.x=0;
	p->pl.pos_img_affiche.y=0;	
	p->bp[0][0].img = IMG_Load("soloo1.png");
	p->bp[0][0].pos_img_ecran.x=700;
	p->bp[0][0].pos_img_ecran.y=80;
	p->bp[0][0].pos_img_affiche.x=0;
	p->bp[0][0].pos_img_affiche.y=0;
	p->bp[0][1].img = IMG_Load("soloo11.png");
	p->bp[0][1].pos_img_ecran.x=700;
	p->bp[0][1].pos_img_ecran.y=80;
	p->bp[0][1].pos_img_affiche.x=0;
	p->bp[0][1].pos_img_affiche.y=0;
	p->bp[1][0].img = IMG_Load("multii1.png");
	p->bp[1][0].pos_img_ecran.x=700;
	p->bp[1][0].pos_img_ecran.y=320;
	p->bp[1][0].pos_img_affiche.x=0;
	p->bp[1][0].pos_img_affiche.y=0;
	p->bp[1][1].img = IMG_Load("multii11.png");
	p->bp[1][1].pos_img_ecran.x=700;
	p->bp[1][1].pos_img_ecran.y=320;
	p->bp[1][1].pos_img_affiche.x=0;
	p->bp[1][1].pos_img_affiche.y=0;	
	p->re[0].img = IMG_Load("returnn1.png");
	p->re[0].pos_img_ecran.x=20;
	p->re[0].pos_img_ecran.y=20;
	p->re[0].pos_img_affiche.x=0;
	p->re[0].pos_img_affiche.y=0;
	p->re[1].img = IMG_Load("returnn11.png");
	p->re[1].pos_img_ecran.x=20;
	p->re[1].pos_img_ecran.y=20;
	p->re[1].pos_img_affiche.x=0;
	p->re[1].pos_img_affiche.y=0;
	p->onp=0;
	p->nb=0;

	q->qu.img = IMG_Load("quitquest.jpg");
	q->qu.pos_img_ecran.x=0;
	q->qu.pos_img_ecran.y=0;
	q->qu.pos_img_affiche.x=0;
	q->qu.pos_img_affiche.y=0;
	q->bq[0][0].img = IMG_Load("yes0.png");
	q->bq[0][0].pos_img_ecran.x=330;
	q->bq[0][0].pos_img_ecran.y=350;
	q->bq[0][0].pos_img_affiche.x=0;
	q->bq[0][0].pos_img_affiche.y=0;
	q->bq[0][1].img = IMG_Load("yes1.png");
	q->bq[0][1].pos_img_ecran.x=330;
	q->bq[0][1].pos_img_ecran.y=350;
	q->bq[0][1].pos_img_affiche.x=0;
	q->bq[0][1].pos_img_affiche.y=0;
	q->bq[1][0].img = IMG_Load("no0.png");
	q->bq[1][0].pos_img_ecran.x=600;
	q->bq[1][0].pos_img_ecran.y=350;
	q->bq[1][0].pos_img_affiche.x=0;
	q->bq[1][0].pos_img_affiche.y=0;
	q->bq[1][1].img = IMG_Load("no1.png");
	q->bq[1][1].pos_img_ecran.x=600;
	q->bq[1][1].pos_img_ecran.y=350;
	q->bq[1][1].pos_img_affiche.x=0;
	q->bq[1][1].pos_img_affiche.y=0;
	q->onq=0;
	Mix_Music* music;
	initialiser_audio(music);
}

void affichermenu(menu *m,option *o, play *p, quit *q,score *s,SDL_Surface *screen,temps *t,int *niveau,int key[],int *boucle,int *on)
{
	Mix_Chunk* mus;
	
	int i;
	
	int returnn = 0 ;
	switch(*niveau)
	{
		case 0: //menu
			SDL_BlitSurface(m->anim[(t->secondesEcoulees)% 5].img,&m->anim[(t->secondesEcoulees)% 5].pos_img_affiche,screen,&m->anim[(t->secondesEcoulees)% 5].pos_img_ecran);
			if(key[SDLK_p])
				{initialiser_audiobref(mus);m->onm=0;}
			else if(key[SDLK_o])
				{initialiser_audiobref(mus);m->onm=1;}
			else if(key[SDLK_s])
				{initialiser_audiobref(mus);m->onm=2;}
			else if(key[SDLK_q])
				{initialiser_audiobref(mus);m->onm=3;}
			
			for(i=0;i<4;i++)
			{
				if(m->onm!=i) 
					SDL_BlitSurface(m->bm[i][0].img,NULL,screen,&m->bm[i][0].pos_img_ecran);
				else 
					SDL_BlitSurface(m->bm[i][1].img,NULL,screen,&m->bm[i][1].pos_img_ecran);
			}
			if(key[SDLK_p])
				*niveau = 1;
			else if(key[SDLK_o])
				*niveau = 2;
			else if(key[SDLK_s])
				*niveau = 3;
			else if(key[SDLK_q])
				*niveau = 4;
			break;
		case 1://play
			SDL_BlitSurface(p->pl.img,NULL,screen,NULL);
			if(key[SDLK_DOWN]&& p->onp==0)
				p->onp=1;
			else if(key[SDLK_UP]&& p->onp==1)
				p->onp=0;
			else if(key[SDLK_ESCAPE])
				returnn=1;
			for(i=0;i<2;i++)
			{
				if(p->onp!=i) 
					SDL_BlitSurface(p->bp[i][0].img,NULL,screen,&p->bp[i][0].pos_img_ecran);
				else 
					SDL_BlitSurface(p->bp[i][1].img,NULL,screen,&p->bp[i][1].pos_img_ecran);
			}
			switch(returnn)
			{
				case 0: SDL_BlitSurface(p->re[0].img,NULL,screen,&p->re[0].pos_img_ecran);break;
				case 1: SDL_BlitSurface(p->re[1].img,NULL,screen,&p->re[1].pos_img_ecran);break;
			}
			if(key[SDLK_ESCAPE])
				*niveau=0;
			else if(key[SDLK_RETURN]&& p->onp==0)
				{initialiser_audiobref(mus);p->nb=1;*on=1;*niveau=-1;initialiser_temps(&(*t));}
			else if(key[SDLK_RETURN]&& p->onp==1)
				{initialiser_audiobref(mus);p->nb=2;*on=1;*niveau=-1;initialiser_temps(&(*t));}
			break;
		case 2://option
			SDL_BlitSurface(o->op.img,NULL,screen,NULL);
			if(key[SDLK_RIGHT]&& o->ono==0)
				o->ono=1;
			else if(key[SDLK_LEFT]&& o->ono==1)
				o->ono=0;
			else if(key[SDLK_DOWN]&& o->ono==0)
				o->ono=2;
			else if(key[SDLK_DOWN]&& o->ono==1)
				o->ono=3;
			else if(key[SDLK_RIGHT]&& o->ono==2)
				o->ono=3;
			else if(key[SDLK_LEFT]&& o->ono==3)
				o->ono=2;
			else if(key[SDLK_UP]&& o->ono==2)
				o->ono=0;
			else if(key[SDLK_UP]&& o->ono==3)
				o->ono=1;
			else if(key[SDLK_ESCAPE])
				returnn=1;
			switch(returnn)
			{
				case 0 : SDL_BlitSurface(o->re[0].img,NULL,screen,&o->re[0].pos_img_ecran);break;
				case 1 : SDL_BlitSurface(o->re[1].img,NULL,screen,&o->re[1].pos_img_ecran);break;
			}
			o->txte[1].txt=TTF_RenderText_Blended(o->txte[1].police,"Screen mode : ",o->txte[1].color_txt);
			SDL_BlitSurface(o->txte[1].txt,NULL,screen,&o->txte[1].pos_txt);
			o->txte[2].txt=TTF_RenderText_Blended(o->txte[2].police,"Using : ",o->txte[2].color_txt);
			SDL_BlitSurface(o->txte[2].txt,NULL,screen,&o->txte[2].pos_txt);
			for(i=0;i<4;i++)
			{
				if(o->ono!=i) 
					SDL_BlitSurface(o->bo[i][0].img,NULL,screen,&o->bo[i][0].pos_img_ecran);
				else 
					SDL_BlitSurface(o->bo[i][1].img,NULL,screen,&o->bo[i][1].pos_img_ecran);
			}
			//volume
			o->onv=Mix_VolumeMusic(-1);
			switch(o->onv)
			{
				case 0:SDL_BlitSurface(o->v[0].img,NULL,screen,&o->v[0].pos_img_ecran);break;
				case 32:SDL_BlitSurface(o->v[1].img,NULL,screen,&o->v[1].pos_img_ecran);break;	
				case 64:SDL_BlitSurface(o->v[2].img,NULL,screen,&o->v[2].pos_img_ecran);break;
				case 96:SDL_BlitSurface(o->v[3].img,NULL,screen,&o->v[3].pos_img_ecran);break;
				case 128:SDL_BlitSurface(o->v[4].img,NULL,screen,&o->v[4].pos_img_ecran);break;
			}
			o->txte[0].txt=TTF_RenderText_Blended(o->txte[0].police,"Volume : ",o->txte[0].color_txt);
			SDL_BlitSurface(o->txte[0].txt,NULL,screen,&o->txte[0].pos_txt);
			if((key[SDLK_KP_MINUS]&&(o->onv==MIX_MAX_VOLUME))
						||
					(key[SDLK_KP_PLUS]&&(o->onv==MIX_MAX_VOLUME*0.5)))
						{Mix_VolumeMusic(MIX_MAX_VOLUME*0.75);}
					else if((key[SDLK_KP_MINUS]&&(o->onv==MIX_MAX_VOLUME*0.75))
						||				
					((key[SDLK_KP_PLUS]&&(o->onv==MIX_MAX_VOLUME*0.25))))
						{Mix_VolumeMusic(MIX_MAX_VOLUME*0.5);}
					else if((key[SDLK_KP_MINUS]&&(o->onv==MIX_MAX_VOLUME*0.5))
						||
						((key[SDLK_KP_PLUS]&&(o->onv==0))))
						{Mix_VolumeMusic(MIX_MAX_VOLUME*0.25);}
					else if(key[SDLK_KP_MINUS]&&(o->onv==MIX_MAX_VOLUME*0.25))
						{Mix_VolumeMusic(0);}
					else if(key[SDLK_KP_PLUS]&&(o->onv==MIX_MAX_VOLUME*0.75))
						{Mix_VolumeMusic(MIX_MAX_VOLUME);}
			
			else if(key[SDLK_ESCAPE])
				*niveau=0;	
			break;
		case 3://score
			SDL_BlitSurface(s->sc.img,NULL,screen,NULL);
			if(key[SDLK_ESCAPE])
				returnn=1;
			switch(returnn)
			{
				case 0: SDL_BlitSurface(s->re[0].img,NULL,screen,&s->re[0].pos_img_ecran);break;
				case 1: SDL_BlitSurface(s->re[1].img,NULL,screen,&s->re[1].pos_img_ecran);break;
			}
			if(key[SDLK_ESCAPE])
				*niveau=0;
				
			break;
		case 4://quit
			SDL_BlitSurface(q->qu.img,NULL,screen,NULL);
			if(key[SDLK_RIGHT]&& q->onq==0)
				q->onq=1;
			else if(key[SDLK_LEFT]&& q->onq==1)
				q->onq=0;
			for(i=0;i<2;i++)
			{
				if(q->onq!=i) 
					SDL_BlitSurface(q->bq[i][0].img,NULL,screen,&q->bq[i][0].pos_img_ecran);
				else 
					SDL_BlitSurface(q->bq[i][1].img,NULL,screen,&q->bq[i][1].pos_img_ecran);
			}
			if(key[SDLK_RETURN]&& q->onq==0)
				*boucle=0;
			else if(key[SDLK_RETURN]&& q->onq==1)
				*niveau=0;
			break;
	}
}






