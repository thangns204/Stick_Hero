#include "draw_game.h"
#include "application.h"

SDL_Surface** images = NULL;

int Init_draw_game(void){
	images = Load_imgs();
	
	if (NULL == images) return -1;
	return 0;
}

SDL_Surface* Get_image(size_t index){
	if (index < IMGS_TOTAL) return images[index];
	else 					return NULL;
}

int Draw_heroes(size_t type, int x, int y){
		return Draw_image(Get_screen(), Get_image(HEROES_NORMAL_IMG), x, y);
	
}

int Draw_pipes(size_t type, int x, int y, int val){
    if (val == 1)  return Draw_image(Get_screen(), Get_image(PIPE1_IMG), x, y);
    if (val == 2)  return Draw_image(Get_screen(), Get_image(PIPE2_IMG), x, y);
    if (val == 3)  return Draw_image(Get_screen(), Get_image(PIPE3_IMG), x, y);
    if (val == 4)  return Draw_image(Get_screen(), Get_image(PIPE4_IMG), x, y);
    if (val == 5)  return Draw_image(Get_screen(), Get_image(PIPE5_IMG), x, y);
    if (val == 6)  return Draw_image(Get_screen(), Get_image(PIPE6_IMG), x, y);
    if (val == 7)  return Draw_image(Get_screen(), Get_image(PIPE7_IMG), x, y);
    return 0;
}


int Draw_stick(size_t type, int x, int y){
    return Draw_image(Get_screen(), Get_image(STICK_IMG), x, y);
}


int Draw_line(size_t type,int x, int y, double angle, double zoomy, int k){
        return Draw_image1(Get_screen(),Get_image(STICK_IMG), x, y, angle, zoomy, k);
        
}

int Draw_score(int x, int y, int score){
    char result[50];
      sprintf(result, "%d", score);
    return Draw_score_(Get_screen(),   x,  y, result);
    
}

int Draw_Restart(int x, int y){
      return Draw_score_(Get_screen(),   x,  y, "Press Enter to start again!");
    
}

int Draw_background(void){
	return Draw_image_in_every_pixel(Get_screen(), Get_image(BACKGROUND_IMG));
}


int Draw_game_over(int x, int y){
    return Draw_image(Get_screen(), Get_Game_Over(), x, y);
}



void CleanUp_images(void){
	CleanUp_imgs(images);
}
