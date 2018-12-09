#include "stdio.h"
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <time.h>
#include <stdlib.h>

#include "images.h"


SDL_Surface* Load_img( const char* filename ) {
	/*The img that's loaded*/
	SDL_Surface* loadedImage	= NULL;
	
	/*Initialize PNG loading*/
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return NULL;
	}	

	/*Load the img using SDL_image*/
	loadedImage = IMG_Load(filename);

	/*If the image loaded*/
	if( loadedImage == NULL )
		printf("Error opening image %s\n", filename);

	/*Return the optimized image*/
	return loadedImage;
}

void Load_heroes_imgs(SDL_Surface** images){
	images[HEROES_NORMAL_IMG] 	= Load_img("img/hero1.png");
}


void Load_backgr_imgs(SDL_Surface** images){
	images[BACKGROUND_IMG] 		= Load_img("img/bg1.jpg");
}

void Load_stick_imgs(SDL_Surface** images){
    images[STICK_IMG]         = Load_img("img/main.png");
}

void Load_pipes1(SDL_Surface** images){
   images[PIPE1_IMG]        = Load_img("img/den1.png");
}

void Load_pipes2(SDL_Surface** images){
    images[PIPE2_IMG]        = Load_img("img/den2.png");
}
void Load_pipes3(SDL_Surface** images){
    images[PIPE3_IMG]        = Load_img("img/den3.png");
}
void Load_pipes4(SDL_Surface** images){
    images[PIPE4_IMG]        = Load_img("img/den4.png");
}
void Load_pipes5(SDL_Surface** images){
    images[PIPE5_IMG]        = Load_img("img/den5.png");
}
void Load_pipes6(SDL_Surface** images){
    images[PIPE6_IMG]        = Load_img("img/den6.png");
}
void Load_pipes7(SDL_Surface** images){
    images[PIPE7_IMG]        = Load_img("img/den7.png");
}

SDL_Surface* Get_Game_Over(void){
    return Load_img("img/gameover.png");
}

SDL_Surface** Load_imgs(void){
	SDL_Surface** images = (SDL_Surface**)calloc(sizeof(SDL_Surface*), IMGS_TOTAL);
	if (NULL == images) return NULL;

	Load_heroes_imgs(images);
	Load_backgr_imgs(images);
    Load_stick_imgs(images);
    Load_pipes1(images);
    Load_pipes2(images);
    Load_pipes3(images);
    Load_pipes4(images);
    Load_pipes5(images);
    Load_pipes6(images);
    Load_pipes7(images);
    

	return images;
}

void CleanUp_imgs(SDL_Surface** images){
	int i;
	for(i = 0; i < IMGS_TOTAL; ++i) {
		if (NULL != images[i]) SDL_FreeSurface(images[i]);
	}
	free(images);
}

