#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "file.h"


int main(int argc, char const *argv[])
{
    SDL_Surface *ecran=NULL, *background=NULL;
    SDL_Rect pos_ecran;
    player mario;
    SDL_Event event;
    objet coins;
    
    int continuer =1;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("TEST Objet",NULL);
    ecran = SDL_SetVideoMode(960, 497, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   


    background = IMG_Load("back2.jpg");
    pos_ecran.x =0;
    pos_ecran.y=0;
    mario.mario=IMG_Load("mario_bas.gif");
    mario.pos_mario.x=89;
    mario.pos_mario.y=79;
    mario.pos_mario.h=32;
    mario.pos_mario.w=32;
	mario.mario_vies=5;


    initialiser_objet(&coins,ecran);


    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
             continuer=0;
        break;
        case SDL_KEYDOWN:
	score_vies(&coins,&mario);
                switch(event.key.keysym.sym)
                {
                    case SDLK_0: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_UP: // Demande à jouer
                        mario.pos_mario.y--;
                        break;
                    case SDLK_DOWN: // Demande l'éditeur de niveaux
                        mario.pos_mario.y++;
                        break;
                    case SDLK_RIGHT:
                        mario.pos_mario.x++;
                        break;
                    case SDLK_LEFT:
                        mario.pos_mario.x--;
                        break;
                }
                break;

        }
    printf("%d",mario.mario_vies);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &pos_ecran);
        afficher_objet(coins,ecran);
         SDL_BlitSurface(mario.mario,NULL,ecran,&mario.pos_mario);
        SDL_Flip(ecran);
    }
 SDL_FreeSurface(background);
SDL_FreeSurface(mario.mario);
 SDL_Quit();
    return EXIT_SUCCESS;
}
