#include <SDL/SDL.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"
ennemi initializeEnnemi(int x, int y, int vie,SDL_Surface *sprite)
   {
//declaration
	ennemi e;
//debut
      e.sprite = sprite;


      //Coordonnées  de notre ennemi souhaite

    e.pos.y=y;
	e.pos.x=x;
	e.vie=vie;

return e;
   }
void afficher_ennemi(SDL_Surface *ecran,ennemi e,SDL_Surface *imagesp)
{

	SDL_BlitSurface(imagesp,NULL,ecran,&e.pos);
// imagesp est l'image coupé du sprite cette fonction est reglable a l'integration
	SDL_Flip(ecran);

}
