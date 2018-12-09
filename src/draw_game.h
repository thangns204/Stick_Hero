#ifndef _DRAW_GAME_H_
	#define _DRAW_GAME_H_
	
	#include "SDL2/SDL.h"
	#include "stdio.h"
	#include "draw.h"
	#include "images.h"

	int 			Init_draw_game	(void);

	SDL_Surface* 	Get_image		(size_t index);

	int 			Draw_background	(void);
	int 			Draw_heroes		(size_t type, int x, int y);

    int             Draw_pipes        (size_t type, int x, int y, int val);

    int             Draw_stick        (size_t type, int x, int y);
    int Draw_line(size_t type,  int x, int y, double angle, double zoomy, int k);
	int Draw_game_over(int x, int y);
    int Draw_scrore(int x, int y, int score);

	void 			CleanUp_images	(void);
#endif
