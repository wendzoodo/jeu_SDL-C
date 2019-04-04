#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
 /* Structure pour gérer notre ennemi */

   typedef struct ennemi
   {
       //Sprite du ennemi
       SDL_Surface *sprite;

       /* Coordonnées du ennemi */
       	SDL_Rect pos;
	int vie;

   } ennemi;
ennemi initializeEnnemi(int x, int y, int vie,SDL_Surface *sprite);
void afficher_ennemi(SDL_Surface *ecran,ennemi e,SDL_Surface *image);
#endif // HEADER_H_INCLUDED
