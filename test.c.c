#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "map.h"
#include "input.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
void main ()
{
SDL_Surface *screen = NULL,*map=NULL,*player=NULL;

    Map m;Input input; hero h;


    SDL_Rect positionmap,positionplayer;
SDL_Event event;
int continuer = 1;
    positionmap.x=0;
    positionmap.y=0;
    positionplayer.x=0;
    positionplayer.y=200;
    

    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

     //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    map =IMG_Load("map.png");
    player=IMG_Load("player1.png");
    SDL_BlitSurface(map,NULL,screen,&positionmap);
    SDL_BlitSurface(player,NULL,screen,&positionplayer);
SDL_SetColorKey(player, SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 255, 255,255));
SDL_EnableKeyRepeat(10,10);

   inithero(&h);

 while (continuer)
    {
        SDL_WaitEvent(&event);
   switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        positionplayer.y=positionplayer.y-15;
                        break;
                    case SDLK_DOWN:
			positionplayer.y=positionplayer.y+15;
			break;	
		    case SDLK_LEFT:
			positionplayer.x=positionplayer.x-15;
			break;
		    case SDLK_RIGHT:
			positionplayer.x=positionplayer.x+15;
			break;
case SDL_MOUSEBUTTONUP:
// On arrête le programme si on a fait un clic droit
if ( event.button.button == SDL_BUTTON_RIGHT )
continuer = 0;
else {
positionplayer.x = event.button.x;
positionplayer.y = event.button.y;
}
break;
case SDL_MOUSEMOTION:
positionplayer.x = event.motion.x;
positionplayer.y = event.motion.y;
break;
default: // on ne traite pas les autres événements
break;
 }}

/*switch (event.type) 
{ 
case SDL_QUIT:
  continuer =0;
   break; 
 case SDL_MOUSEBUTTONUP:
if (event.button.button==SDL_BUTTON_LEFT)
{ positionplayer.x=event.button.x;
positionplayer.y=event.button.y;
break;}
}}
*/



                   /* case SDLK_ESCP:
                        continuer = 0;
 		

	break;*/

                        
                
        
SDL_BlitSurface(map,NULL,screen,&positionmap);

 afficher_hero( h,screen);

SDL_BlitSurface(player,NULL,screen,&positionplayer);
SDL_SetColorKey(player, SDL_SRCCOLORKEY, SDL_MapRGB(player->format, 255, 255,255));
SDL_Flip(screen);

}   }

