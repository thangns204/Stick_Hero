#include "stdio.h"


#include "event.h"
#include "draw_game.h"
#include <time.h>
#include <stdlib.h>

Coord_t* head_imgs[PERS_TOTAL];
Coord_t* head_blocks;

short heroes_pos;
short finish_pos;


bool okHero = false, okPipe1 = false, okPipe2 = false, okPipe3 = false, okstick = false, okScore = false;
bool okHeroBack = false, okHeroFall = false, okGameOver = false, doneMov = false;
int sc = 0, tempOld = 0, score = 0, backStick = 0, Countdraw = 0, Width2 = 0;
int pipe1 , pipe2 , pipe3, r, dis;
time_t t;

Coord_t* Get_head_img(size_t index){
    if (index < PERS_TOTAL) return head_imgs[index];
    else                     return NULL;
}

int Init_phisics(){
    /* Setting head_img values */
    pipe1 = 1; pipe2 = 2; pipe3 =3;
    head_imgs[HEROES_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
    head_imgs[HEROES_PERS]->x    = 19;
    head_imgs[HEROES_PERS]->y    = 576;
    head_imgs[HEROES_PERS]->w    = Get_image(HEROES_NORMAL_IMG)->w;
    head_imgs[HEROES_PERS]->h    = Get_image(HEROES_NORMAL_IMG)->h;
    
    head_imgs[PIPES_1_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
    head_imgs[PIPES_1_PERS]->x    = 0;
    head_imgs[PIPES_1_PERS]->y    = 610;
    head_imgs[PIPES_1_PERS]->w    = Get_image(PIPE1_IMG)->w;
    head_imgs[PIPES_1_PERS]->h    = Get_image(PIPE1_IMG)->h;
    
    head_imgs[PIPES_2_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
    head_imgs[PIPES_2_PERS]->x    = 300;
    head_imgs[PIPES_2_PERS]->y    = 610;
    head_imgs[PIPES_2_PERS]->w    = Get_image(PIPE2_IMG)->w;
    head_imgs[PIPES_2_PERS]->h    = Get_image(PIPE2_IMG)->h;
    
    
    head_imgs[PIPES_3_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
    head_imgs[PIPES_3_PERS]->x    = 794;
    head_imgs[PIPES_3_PERS]->y    = 610;
    head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE3_IMG)->w;
    head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE3_IMG)->h;
    
    return 0;
    // head_imgs[HEROES_PERS]->type = NOR_TYPE;
}

void Move_heroes_on_ox(int step){
    while (head_imgs[HEROES_PERS]->x < step) {
        head_imgs[HEROES_PERS]->x += 10;
        Update_screen();
        // SDL_Delay(20);
        
    }
    head_imgs[HEROES_PERS]->x += step - head_imgs[HEROES_PERS]->x;
    Update_screen();
}




void MoveHeros(int moveCl_1){
    if (tempOld == 0){
        Countdraw = head_imgs[PIPES_2_PERS]->w;
        Width2 = head_imgs[PIPES_1_PERS]->w;
        dis = 41 + 4*(sc + 1);
        if (head_imgs[PIPES_2_PERS]->x <= dis && dis <= head_imgs[PIPES_2_PERS]->x + head_imgs[PIPES_2_PERS]->w){
            dis = head_imgs[PIPES_2_PERS]->x + head_imgs[PIPES_2_PERS]->w;
            //okHero = true;
            score++;
            // printf("%d\n", score);
            okScore = true;
        }
        // printf("%d/n", head_imgs[PIPES_2_PERS]->x + head_imgs[PIPES_2_PERS]->w);
        //printf("%d/n", dis);
        dis -= head_imgs[HEROES_PERS]->w;
    }
    
    tempOld++;
    
    
    /* Moving clouds */
    if (moveCl_1){
        if (head_imgs[HEROES_PERS]->x < (dis)) {
            head_imgs[HEROES_PERS]->x = head_imgs[HEROES_PERS]->x + 1;
        }
        else{
            head_imgs[HEROES_PERS]->x = dis;
            okHero = true;
        }
        //   okHero = f    alse;
    }
    
}

void MoveFallHeros(int moveCl_1){
    /* Moving clouds */
    if (moveCl_1){
        if (head_imgs[HEROES_PERS]->y < 800){
            head_imgs[HEROES_PERS]->y = head_imgs[HEROES_PERS]->y + 1;
            if (head_imgs[HEROES_PERS]->x >= 800)  { head_imgs[HEROES_PERS]->x = 800; okHeroFall = true; }
            
            
            // okHero = true;
        }
        else{
            head_imgs[HEROES_PERS]->y = 800;
            okHeroFall = true;
            
        }
    }
    
    
}



void MovePipes1(int moveCl_1){
    
    /* Moving clouds */
    if (moveCl_1){
        
        if (head_imgs[PIPES_1_PERS]->x < -20) {
            head_imgs[PIPES_1_PERS]->x = head_imgs[PIPES_1_PERS]->x - 5;
            if (head_imgs[PIPES_1_PERS]->x <= -20)  { head_imgs[PIPES_1_PERS]->x = -20; okPipe1 = true; }
            
            //  okHero = true;
        }
        else{
            // printf("LOL");
            head_imgs[PIPES_1_PERS]->x = -20;
            okPipe1 = true;
        }
        //   okHero = false;
    }
    
    
}



void MovePipes2(int moveCl_1){
    
    /* Moving clouds */
    if (moveCl_1){
        
        if (head_imgs[PIPES_2_PERS]->x > 0) {
            head_imgs[PIPES_2_PERS]->x = head_imgs[PIPES_2_PERS]->x - 2;
            if (head_imgs[PIPES_2_PERS]->x <= 0)  { head_imgs[PIPES_2_PERS]->x = 0; okPipe2 = true; }
            //  okHero = true;
        }
        else
            // printf("LOL");
        {
            head_imgs[PIPES_2_PERS]->x = 0;
            okPipe2 = true;
        }
        
        //   okHero = false;
    }
    
    // printf("%d\n", head_imgs[PIPES_2_PERS]->x);
}

void MoveHeroBack(int moveCl_1){
    
    /* Moving clouds */
    if (moveCl_1){
        
        if (head_imgs[HEROES_PERS]->x > Countdraw - 41) {
            head_imgs[HEROES_PERS]->x = head_imgs[HEROES_PERS]->x - 3;
            //      printf("%d\n", head_imgs[HEROES_PERS]->x);
            
            if (head_imgs[HEROES_PERS]->x <= Countdraw - 41) { head_imgs[HEROES_PERS]->x = Countdraw - 41; okHeroBack = true;}
            // okHero = true;
        }
        else{
            // printf("LOL");
            head_imgs[HEROES_PERS]->x = Countdraw - 41;
            // okHero = true;
        }
        //   okHero = false;
    }
    
    
}


void MovePipes3(int moveCl_1){
    
    /* Moving clouds */
    int dis = rand() % (432 - Countdraw - head_imgs[PIPES_3_PERS]->w) + 1;
    
    
    if (moveCl_1){
        
        if (head_imgs[PIPES_3_PERS]->x > dis) {
            head_imgs[PIPES_3_PERS]->x = head_imgs[PIPES_3_PERS]->x - 2;
            // printf("%d\n", head_imgs[PIPES_3_PERS]->x);
            //if (head_imgs[PIPES_3_PERS]->x <= dis) { head_imgs[PIPES_3_PERS]->x = dis; okPipe3 = true;}
            
            //      okHero = true;
        }
        else {
            //     printf("LOL\n");
            //
            //printf("%d\n", dis);
            
            head_imgs[PIPES_3_PERS]->x = dis;
            okPipe3 = true;
        }
        //   okHero = false;
    }
    
    
}



void Update_screen(void){
    // doneMov = false;
    Coord_t* cur = NULL;
    /* Drawing background */
    Draw_background();
    
    // printf("%d\n",okScore);
    if (!okScore && okHero) {
        // printf("LOL");
        Draw_line(0, Width2 + 2, 606, 0, sc, 0);
    } else {
        
        if ( head_imgs[HEROES_PERS]->x != Countdraw - 41 ) {
            Draw_line(0, 54 - backStick, 606, -90, sc, 1);
        }
        else
            Draw_stick(0, Countdraw + 1 , 606);
    }
    
    
    Draw_score(195, 50, score);
    
    
    Draw_heroes(HEROES_NORMAL_IMG,
                head_imgs[HEROES_PERS]->x,
                head_imgs[HEROES_PERS]->y);
    
    
    
    Draw_pipes(0,
               head_imgs[PIPES_1_PERS]->x,
               head_imgs[PIPES_1_PERS]->y, pipe1);
    
    Draw_pipes(0,
               head_imgs[PIPES_2_PERS]->x,
               head_imgs[PIPES_2_PERS]->y, pipe2);
    
    
    Draw_pipes(0,
               head_imgs[PIPES_3_PERS]->x,
               head_imgs[PIPES_3_PERS]->y, pipe3);
    
    
    if (okGameOver){
        // printf("LOL");
        //Countdraw++;
        Draw_game_over(143,125);
        Draw_Restart(57, 175);
    }
    
    
    if (okPipe1 && okPipe2 && okPipe3 && okHeroBack){
        head_imgs[PIPES_1_PERS] = head_imgs[PIPES_2_PERS];
        pipe1 = pipe2;
        head_imgs[PIPES_2_PERS] = head_imgs[PIPES_3_PERS];
        pipe2 = pipe3;
        
        
        /* Intializes random number generator */
        srand ( time(NULL) );  r = rand() % 7 + 1;
        pipe3 = r;
        //   printf("%d\n", r);
        
        head_imgs[HEROES_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
        head_imgs[HEROES_PERS]->x    = head_imgs[PIPES_2_PERS]->w - 41;
        head_imgs[HEROES_PERS]->y    = 576;
        head_imgs[HEROES_PERS]->w    = Get_image(HEROES_NORMAL_IMG)->w;
        head_imgs[HEROES_PERS]->h    = Get_image(HEROES_NORMAL_IMG)->h;
        
        
        head_imgs[PIPES_3_PERS] = (Coord_t*)malloc(sizeof(Coord_t));
        head_imgs[PIPES_3_PERS]->x    = 794;
        head_imgs[PIPES_3_PERS]->y    = 610;
        
        if (r == 1) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE1_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE1_IMG)->h;
        }
        if (r == 2) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE2_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE2_IMG)->h;
        }
        if (r == 3) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE3_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE3_IMG)->h;
        }
        if (r == 4) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE4_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE4_IMG)->h;
        }
        if (r == 5) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE5_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE5_IMG)->h;
        }
        if (r == 6) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE6_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE6_IMG)->h;
        }
        if (r == 7) {
            head_imgs[PIPES_3_PERS]->w    = Get_image(PIPE7_IMG)->w;
            head_imgs[PIPES_3_PERS]->h    = Get_image(PIPE7_IMG)->h;
        }
        
        okHero = false;
        okPipe3 =false;
        okPipe2 = false;
        okPipe1 = false;
        okHeroBack = false;
        okstick = false;
        okHeroFall = false;
        doneMov = true;
        sc = 0;
        
    }
    
    
    
    
}

