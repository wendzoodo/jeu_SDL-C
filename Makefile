prog:fonction.o main1.o 
	gcc fonction.o main1.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main1.o:main1.c 
	gcc -c main1.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
fonction.o:fonction.c 
	gcc -c fonction.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
