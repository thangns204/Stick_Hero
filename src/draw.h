#ifndef _DRAW_H_
	#define _DRAW_H_

#include "draw.h"
#include "images.h"


int Draw_image1(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y, double angle, int zoomy, int k);
int Draw_image_in_every_pixel	(SDL_Surface* dest_surface, SDL_Surface* src_surface);
int Draw_image 					(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y);
int Draw_score_(SDL_Surface* dest_surface,  size_t x, size_t y, const char* text);

#endif
