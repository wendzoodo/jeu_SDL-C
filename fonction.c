#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "file.h"






void initialiser_objet(objet *coins,SDL_Surface *ecran)//je prend lexemple du coins et je passe en parametres l'image choisie
{

	
	coins->objet1 = IMG_Load("caisse.jpg");
	coins->objet2= IMG_Load("caisse.jpg");
	coins->objet3= IMG_Load("caisse_ok.jpg");

/* Coordonnées de démarrage de nos objets */
	coins->x1 = 200 ;
	coins->y1 = 67;
	coins->x2 = 60 ;
	coins->y2 = 45 ;
	coins->x3 = 102 ;
	coins->y3 = 90 ;


}


void afficher_objet(objet coins,SDL_Surface *ecran)
{
	/* Rectangle de destination à blitter */
SDL_Rect dest1,dest2,dest3;
dest1.x = coins.x1 ;
dest1.y = coins.y1 ;
dest1.w=32;
dest1.h=32;

SDL_Rect frame1,frame2,frame3;
frame1.x = 0;
frame1.y = 0;
frame1.w = 32;
frame1.h = 32;


dest2.x = coins.x2 ;
dest2.y = coins.y2 ;
dest2.w=32;
dest2.h=32;


frame2.x = 0;
frame2.y = 0;
frame2.w = 32;
frame2.h = 32;



dest3.x = coins.x3 ;
dest3.y = coins.y3 ;
dest3.w=32;
dest3.h=32;


frame3.x = 0;
frame3.y = 0;
frame3.w = 32;
frame3.h = 32;
/* Blitte notre objet sur l'écran aux coordonnées x et y */

SDL_BlitSurface(coins.objet1 , &frame1 , ecran , &dest1) ;
SDL_BlitSurface(coins.objet2 , &frame2 , ecran , &dest2) ;
SDL_BlitSurface(coins.objet3 , &frame3 , ecran , &dest3) ;
SDL_Delay(15);
}


int bounding_box(objet coins, player mario)
{
	//1ere condition
	/*if(pos_player.y >= coins.y1 + coins.h1)
                return 0;
        if(pos_player.x >= coins.x1 + coins.w1)
                return 0;
        if(pos_player.y + pos_player.h <= coins.h1)
                return 0;
        if(pos_player.x+ pos_player.w <= coins.x1)
                return 0;
        return 1;*/

if ((mario.pos_mario.x >= coins.x1 + coins.w1)|| (mario.pos_mario.x+ mario.pos_mario.w <= coins.x1)|| (mario.pos_mario.y >= coins.y1 + coins.h1)|| (mario.pos_mario.y + mario.pos_mario.h <= coins.y1))
        return 0;
else 
return 1;
}


