#ifndef _BOUNDING_BOX_H_
#define _BOUNDING_BOX_H_
#include <SDL/SDL.h>
#include "perso1.h"
void cadrage(cadre *c,Background b,personne p1,personne p2,ES es1,ES es2,int nb);
int box(SDL_Rect x1,SDL_Rect x2);

#endif
