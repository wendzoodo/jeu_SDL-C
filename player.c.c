#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "player.h"
#include "map.h"
#include "input.h"



#define SERIAL_PORT "/dev/ttyACM0"
#define SERIAL_PORT_BUFFER_LENGTH   20
#define PLANE_STEPS   5


int strStartsWith(const char *pre, const char *str);
//initialiser personnage
void inithero(hero *h)
{
   h->pos.x=110;//coordonnees de demarrage du hero
   h->pos.y=300;
   h->direction=0;
   h->j=0,h->c=0;// j et c compteurs bech yabdew yzidou

   h->image[0]=IMG_Load("player1.png");
   h->image[1]=IMG_Load("player2.png");
   h->image[2]=IMG_Load("player3.png");
   h->image[4]=IMG_Load("player4.png");
   h->image[3]=IMG_Load("player5.png");
   h->image[5]=IMG_Load("player6.png");
   h->image[6]=IMG_Load("player7.png");
   h->image[7]=IMG_Load("player8.png");
   h->image[8]=IMG_Load("player9.png");
   h->image[9]=IMG_Load("player10.png");
   h->image[10]=IMG_Load("player11.png");
   h->image[11]=IMG_Load("player12.png");
   h->image[12]=IMG_Load("player13.png");
   h->image[13]=IMG_Load("player14.png");
   h->image[14]=IMG_Load("player15.png");
   h->image[15]=IMG_Load("player16.png");
   h->image[16]=IMG_Load("player17.png");
   h->image[17]=IMG_Load("player18.png");
}
//afficher premier et unique personnage du jeu

void afficher_hero(hero h,SDL_Surface *screen){

SDL_BlitSurface(h.image[h.j],NULL,screen,&h.pos);

}


void deplacer_per(hero *h,Input input,Map *m,int c)
{
 // Les variables de la troisieme methode
    
   // printf(" %d %d \n",m->post.x,m->post.y);
   if(input.right==1 && input.right!=0 ){
  
          h->direction=0;
          m->post.x=m->post.x-30;
          m->post1.x=m->post1.x+30;
          if (c==1){ m->post.x=m->post.x+30;
          m->post1.x=m->post1.x-30;}
}
   if(input.up==1 && input.up!=0  ){
  
          h->direction=1;
          m->post.y=m->post.y+20;
          m->post1.y=m->post1.y-20;
          if (c==1){ m->post.y=m->post.y-20;
          m->post1.y=m->post1.y+20;}
}
   if(input.left==1 && input.left!=0  ){
  
          h->direction=2;
          m->post.x=m->post.x+20;
          m->post1.x=m->post1.x-20;
          if (c==1){ m->post.x=m->post.x-20;
          m->post1.x=m->post1.x+20;}
}
   if(input.down==1 && input.down!=0  ){
  
          h->direction=3;
          m->post.y=m->post.y-20;
          m->post1.y=m->post1.y+20;
          if (c==1){ m->post.y=m->post.y+20;
          m->post1.y=m->post1.y-20;}}
 
if(input.right==1 && input.right!=0 && input.left==1 && input.left!=0  && input.run==1  ){
    h->direction=0;
          m->post.x=m->post.x-60;
          m->post1.x=m->post1.x+60;
          if (c==1){ m->post.x=m->post.x+60;
          m->post1.x=m->post1.x-60;
         
         
}}
}


