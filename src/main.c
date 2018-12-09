#include "application.h"
#include "draw_game.h"
#include "main.h"
#include "images.h"
#include "event.h"

static int game_status;

int main(int argc, char *argv[]) {
    
    Game_init();
    Main_loop();
   // Clean_up();
    
    return 0;
}


static void Game_init(void) {
    Init_window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    Init_draw_game();
    
    Draw_background();
    
    Draw_score(195, 50, 0);
    
    Draw_pipes(0, 0, 610, 1 );
    
    Draw_pipes(0, 300, 610, 2);
    
    Countdraw = 52;
    
    Draw_heroes(0, 19, 576);
    
    Draw_stick(0, 54, 606);
    
    
    Init_phisics();
    sc = 0;
    score = 0;
    doneMov = true;
    game_status = GAME_RUNNING;
}

static void Process_events(void) {
    SDL_Event event;        /* Event handler */
    SDL_Keycode keycode;
    Uint32 curTime = SDL_GetTicks();
    const Uint8* curKey = SDL_GetKeyboardState( NULL );
    
    
    while( SDL_PollEvent( &event ) != 0 ) {
        keycode = event.key.keysym.sym;
        
        if(event.type == SDL_QUIT) {
            game_status = GAME_QUITTING;
            return;
        }
        
        if (!okGameOver && doneMov) {
        
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        sc += 4;
                         Draw_line(0, Countdraw + 2, 606 - 4*sc, 0, sc, 0);
                        okstick = false;
                        break;
                }
                
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        okstick =true;
                        okScore = false;
                        tempOld = 0;
                        Countdraw = 0;
                        okHeroFall = false;
                        okGameOver = false;
                        doneMov = false;
                        backStick = 0;
                        break;
                }
            }
            
        } else {

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RETURN: //enter to restart
                        okGameOver = false;
                        okstick = false;
                        okHero = false;
                        okScore = false;
                        Clean_up();
                        Game_init();
                         //  Main_loop();
                        
                        break;
                }
                
            }
        }
        
        if (game_status == GAME_OVER) {
            
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RETURN: //enter to restart
                        Clean_up();
                        Game_init();
                      //  Main_loop();
                        
                        break;
                }
                
            }
        }
        
    }
    
    if (GAME_RUNNING == game_status){
       // printf(game_status,"\n");
        if (okstick) {
            MoveHeros(!0);
            
            if (okHero){
                if (okScore) {
                    backStick += 20;
                    MoveHeroBack(!0);
                    MovePipes2(!0);
                    MovePipes3(!0);
                    MovePipes1(!0);
                 } else {
                    MoveFallHeros(!0);
                    //sprintf("LOL");
                    if (okHeroFall) {
                        okGameOver = true;
                      //  game_status = GAME_OVER;
                       // Update_screen();
                    }
                }
            }
             Update_screen();
        }
    }
    
}

static void Main_loop(void) {
    sc = 0;
    score = 0;
    while(GAME_QUITTING != game_status) {
        Process_events();
        
        if (GAME_RUNNING == game_status)
            Render();
    }
}

static void Clean_up(void) {
    CleanUp_images();
    CleanUp_screen();
    CleanUp_window();
  
    SDL_Quit();
}


static void Render(void){     
    Update_window_rect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
}



