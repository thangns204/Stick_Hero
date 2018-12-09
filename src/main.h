#ifndef _MAIN_H_
#define _MAIN_H_

#define SCREEN_TITLE     "Stick_Hero"
#define SCREEN_WIDTH     432
#define SCREEN_HEIGHT     792

enum {
    GAME_STOPPING,
    GAME_RUNNING,
    GAME_QUITTING,
    GAME_OVER
};

/* Initializes all resources*/
static void Resource_init    (char* levels_file_path);
/* Initializes all internal entities needed for the game at startup*/
static void Game_init        (void);
/* Perfoms a loop, updating and rendering*/
static void Main_loop        (void);
/* Frees all resources*/
static void Clean_up        (void);


static void Render(void);
#endif   
