//
//  Costume Definition.h
//  Final Project
//
//  Created by 林珈卉 on 2019/1/12.
//  Copyright © 2019 ChiaHui. All rights reserved.
//

#ifndef Costume_Definition_h
#define Costume_Definition_h

//Custom Definition
const char *title = "Final Project 107000115";
const float FPS = 60;
const int WIDTH = 1920;
const int HEIGHT = 1080;
const int player_width = 125;
const int player_height = 160;
const int bullet_radius = 32;
const int boss_width = 160;
const int boss_height = 160;

typedef struct character
{
    int x;
    int y;
    int movement_s;
    float hp=100.0;
    bool dir;
    char character;
    ALLEGRO_BITMAP *image_path=NULL;
    
}Character;
typedef struct bullet
{
    int x;
    int y;
    int movement_s;
    bool dir_x;
    bool dir_y;
    ALLEGRO_BITMAP *image_path=NULL;
}Bullet;

Character player1;
Character boss;
Bullet *bullets_p[10] = {NULL};
Bullet *bullets_b[11] = {NULL};

int bullets_amount_p = 0;
int draw = 0;
int done = 0;
int window = menu;
int round = 1;
bool judge_game_window = false;
bool judge_selection_window = false;
bool judge_menu_window = true;
bool judge_quit = false;
bool judge_win = false;
bool judge_lose = false;
bool gaming_method = false; //true:mouse, false:keyboard
bool appearance = true; //true: appear, false: disappear
bool next = false; //true: trigger
//bool dir_boss = true; //true: R, false: L
bool *keys = 0;

void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();

#endif /* Costume_Definition_h */
