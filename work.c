
/**
*@file map.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "work.h"
/** 
*@brief to init position 
*@param e the screen  ,p the hero 
*@return Nothing

*/

void init_positions(ecran *e,perso *p)
{
e->positionFond.x=0;
e->positionFond.y=0;

p->posPer.x=20;
p->posPer.y=350;

e->posmini.x=480;
e->posmini.y=20;


e->posnokta.x=485;
e->posnokta.y=100;

}
/** 
*@brief to display
*@param e ,p 
*@return Nothing

*/
void init_affich(ecran *e,perso *p)
{
e->e=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
e->imageFond = IMG_Load("forst.jpg");
p->personnage= IMG_Load("hero.png");
e->imagemini=IMG_Load("mini.png");
e->imagenokta=IMG_Load("curseur.png");



SDL_BlitSurface(e->imageFond, NULL, e->e , &e->positionFond);
SDL_BlitSurface(p->personnage, NULL, e->e, &p->posPer);
SDL_BlitSurface(e->imagemini,NULL,e->e,&e->posmini);
SDL_BlitSurface(e->imagenokta,NULL,e->e,&e->posnokta);

}

/** 
*@brief to move
*@param e the screen  ,p the hero 
*@return Nothing

*/
void key_event ( perso *p,ecran *e)
{


    while(p->continuer)
  {
        SDL_PollEvent(&p->event);
        switch(p->event.type){
        case SDL_QUIT:
        p->continuer=0;
        break;
        case SDL_KEYDOWN:
            switch(p->event.key.keysym.sym){
        case SDLK_RIGHT:
            if (p->posPer.x<1200-p->personnage->w){ //kil l perso yakhlet l 1200 longeur  de l bg l hero maadech ykqdem
          p->posPer.x+=7;
          e->posnokta.x+=2;
            }
            SDL_WaitEvent(&p->event);
            break;
        case SDLK_LEFT:
            if (p->posPer.x>0){
           p->posPer.x-=7;
           e->posnokta.x-=2;
            }
            SDL_WaitEvent(&p->event);
            break;
            }
           break;
       }

 SDL_BlitSurface(e->imageFond,NULL,e->e,&e->positionFond);
 SDL_BlitSurface(p->personnage,NULL,e->e,&p->posPer);
 SDL_BlitSurface(e->imagemini,NULL,e->e,&e->posmini);
 SDL_BlitSurface(e->imagenokta,NULL,e->e,&e->posnokta);
 SDL_Flip(e->e);
    }
}

/** 
*@brief to init ennemy
*@param 
*@return struct ennemy

*/
ennemy initennemy ()
{
	ennemy en;
	en.enimg = IMG_Load("monster.png");
        en.enpos.x=500;
        en.enpos.y=350;
	en.enpos.w=113;
	en.enpos.h=127;
	return en;
}

void affennemy(ennemy en,SDL_Surface *screen)
{
	SDL_BlitSurface(en.enimg,NULL,screen,&en.enpos);
	SDL_Flip(screen);
}


/** 
*@brief AI 
*@param en the ennemy ,h the hero 
*@return Nothing

*/

void AI (ennemy *en , hero h){


	if (en->enpos.x>h.posPer.x && en->enpos.x-h.posPer.x<150)//pos le l'ennemi a droite de la pos l hero et la disatance <150 
		en->enpos.x-=4; // lennemi bech yemchi aala lisar
	else if (en->enpos.x<h.posPer.x && en->enpos.x-h.PosPer.x<-150)
		en->enpos.x+=4;
}








