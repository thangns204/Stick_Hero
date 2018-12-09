#ifndef _EVENT_H_
#define _EVENT_H_

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

#include <stdbool.h>

enum{
    HEROES_PERS,
    PIPES_1_PERS,
    PIPES_2_PERS,
    PIPES_3_PERS,
    PERS_TOTAL
};

extern bool okHero, okPipe1, okPipe2, okPipe3, okstick, okScore, okHeroBack, okHeroFall, okGameOver, doneMov;
extern int sc, tempOld, score, backStick, Countdraw, Width2;

typedef struct Coord_t{
    short type;
    short x;
    short y;
    short w;
    short h;
} Coord_t;

void Set_heads_imgs(void);
Coord_t* Get_head_img(size_t index);

void MoveHeros(int moveCl_1);
void MoveFallHeros(int moveCl_1);
void MoveHeroBack(int moveCl_1);
int Init_phisics();

void MovePipes1(int moveCl_1);
void MovePipes2(int moveCl_1);
void MovePipes3(int moveCl_1);

void Update_screen(void);

void CleanUp_heads(void);
#endif
