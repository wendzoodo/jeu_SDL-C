
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "map.h"



//charger la map


void init_map(Map *m){

m->post.x=-3300;
m->post.y=-4000;

m->post1.x=110+3300;
m->post1.y=300+4000;
m->fond=IMG_Load("map.png");

}
void AffichMap(Map m,SDL_Surface *screen)
{

SDL_BlitSurface(m.fond,NULL,screen,&m.post);

}

