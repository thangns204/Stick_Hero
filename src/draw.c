#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <SDL2_ttf/SDL_ttf.h>
#include "draw.h"
#include "SDL2_rotozoom.h"
#include <math.h>
#include <float.h>



int Draw_image(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y){
    SDL_Rect dest_rect;

    if(dest_surface == NULL || src_surface == NULL) return -1;

	dest_rect.w = 0;
	dest_rect.h = 0;
    dest_rect.x = x;
    dest_rect.y = y;
 
    //copy ban sao
    SDL_BlitSurface(src_surface, NULL, dest_surface, &dest_rect);

    return 0;
}

int Draw_score_(SDL_Surface* dest_surface,  size_t x, size_t y, const char* text){
    if (TTF_Init() == -1) {
        printf("TTF_SDL could not initialize: TTF_Error: %s\n", TTF_GetError());
        return 0;
    }
    SDL_Surface* src_surface;
    SDL_Rect dest_rect;
    
    if(dest_surface == NULL || src_surface == NULL) return -1;
    
    dest_rect.w = 0;
    dest_rect.h = 0;
    dest_rect.x = x;
    dest_rect.y = y;
    
    SDL_Color color={0,0,0};
    TTF_Font* font = TTF_OpenFont("img/fBirdFont.TTF", 24);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }
    if(!(src_surface=TTF_RenderText_Solid(font,text,color))) {
        //handle error here, perhaps print TTF_GetError at least
        printf("TTF Get Error\n");
        return 0;
    } else {
        SDL_BlitSurface(src_surface,NULL,dest_surface, &dest_rect);
        //perhaps we can reuse it, but I assume not for simplicity.
        SDL_FreeSurface(src_surface);
    }
   

    return 0;
}


int Draw_image1(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y, double angle, int zoomy, int k){
    SDL_Rect dest_rect;
    
    
    if(dest_surface == NULL || src_surface == NULL) return -1;
    
    dest_rect.w = 0;
    dest_rect.h = 0;
    dest_rect.x = x;
    dest_rect.y = y;
    
   // SDL_Surface* temp;
    
   
    if(k == 1) {
        src_surface =     rotozoomSurfaceXY(src_surface, angle, 1.0, 1.0, 0);
        src_surface =     rotozoomSurfaceXY(src_surface, 0, zoomy, 1.0, 0);
    }
     else
            src_surface =     rotozoomSurfaceXY(src_surface, angle, 1.0, zoomy, 0);
            
    //copy ban sao
    SDL_BlitSurface(src_surface, NULL, dest_surface, &dest_rect);
    
    return 0;
}

int Scale_image(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y, size_t h){
    SDL_Rect dest_rect;
    
   // printf("%d",src_surface->h);
    if(dest_surface == NULL || src_surface == NULL) return -1;
    
    dest_rect.w = src_surface->w *2 ;
    dest_rect.h = src_surface->h + h;
    dest_rect.x = x;
    dest_rect.y = y;
    
    
    printf("%d", dest_rect.h);
    //copy ban sao
    SDL_BlitSurface(src_surface, NULL, dest_surface, &dest_rect);
    
    return 0;
}


int Draw_image_in_every_pixel(SDL_Surface* dest_surface, SDL_Surface*	src_surface){
	int 			x;
	int 			screen_width;
	SDL_Rect 		dest_rect;

	if (dest_surface == NULL || src_surface == NULL) return -1;

	screen_width = dest_surface->w;
    
  
    dest_rect.x = 0;
	dest_rect.y = 0;
	dest_rect.w = 0;
	dest_rect.h = 0;

    SDL_BlitSurface(src_surface, NULL, dest_surface, &dest_rect);
 	dest_surface = NULL;
 	src_surface  = NULL;
    return 0;
}
