#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED



typedef struct  objet
{
	SDL_Surface *objet1,*objet2,*objet3;//trois objets coeurs ,coins ,pommes juste pour les tests
	int x1,y1,w1,h1,x2,y2,w2,h2,y3,x3,w3,h3;//positions de chaque objet x pour abscisse y ordonnees,w largeur, h hauteur
}objet;

typedef struct player
{
	SDL_Surface *mario;
	SDL_Rect pos_mario;
	int mario_vies;
	int mario_bonus;
	
}player;

void initialiser_objet(objet *coins,SDL_Surface *ecran);//je prend lexemple du coins et je passe en parametres l'image choisie
void afficher_objet(objet coins,SDL_Surface *ecran);
int bounding_box(objet coins,player mario);//type de retour entier 
void score_vies(objet *coins,player *mario);

#endif // FILE_H_INCLUDED

