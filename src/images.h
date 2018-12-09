#ifndef _LOAD_IMG_H_
	#define _LOAD_IMG_H_
	
	#include "SDL2/SDL.h"

	enum SurfacesItems
	{
		HEROES_NORMAL_IMG,
		BACKGROUND_IMG,
        STICK_IMG,
        PIPE1_IMG,
        PIPE2_IMG,
        PIPE3_IMG,
        PIPE4_IMG,
        PIPE5_IMG,
        PIPE6_IMG,
        PIPE7_IMG,
        
		IMGS_TOTAL
	};

	SDL_Surface* 	Load_img(const char* filename );
	
	void 			Load_heroes_imgs(SDL_Surface** images);
    void            Load_pipes1(SDL_Surface** images);
    void            Load_pipes2(SDL_Surface** images);
    void            Load_pipes3(SDL_Surface** images);
    void            Load_pipes4(SDL_Surface** images);
    void            Load_pipes5(SDL_Surface** images);
    void            Load_pipes6(SDL_Surface** images);
    void            Load_pipes7(SDL_Surface** images);
    void 			Load_backgr_imgs(SDL_Surface** images);
    void            Load_stick_imgs(SDL_Surface** images);

    SDL_Surface** 	Load_imgs(void);
    SDL_Surface*     Get_Game_Over(void);

	void 			CleanUp_imgs(SDL_Surface** images);
#endif
