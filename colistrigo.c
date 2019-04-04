#include <SDL/SDL.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int collision_trigo( objet e1,objet e2 )
  {

  int ra,rb,xb,xa,ya,yb,distance;
  ra=(e1.surface->w)/2;
  xa=(e1.position.x+(e1.surface->w/2));
  ya=(e1.position.y+(e1.surface->h/2));
  rb=(e2.surface->w)/2;
  xb=(e2.position.x+(e2.surface->w/2));
  yb=(e2.position.y+(e2.surface->h/2));
  distance=/*sqrt*/((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
  if(distance<=ra+rb)
  {
  return 1 ;
  }
  else
  {
  return 0;
  }
  }
