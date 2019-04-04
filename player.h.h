#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



#define Hero_WIDTH 154
#define Hero_HEIGHT 232
#include "input.h"
#include "map.h"

typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING,ATTACKING };


typedef struct hero 
{
SDL_Surface * image[18];
SDL_Rect pos;
int vie,c;
int score,j;
SDL_Rect position;
int direction;
}hero;

void inithero(hero *h);
void afficher_hero(hero h,SDL_Surface *screen);
void deplacer_per(hero *h,Input input,Map *m,int c);


#endif //INPUT_H_INCLUDED
