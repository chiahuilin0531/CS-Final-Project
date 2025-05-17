//
//  main.cpp
//  My First Allegro
//
//  Created by 林珈卉 on 2018/12/12.
//  Copyright © 2018 ChiaHui. All rights reserved.
//
/*
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define GAME_TERMINATE 666
#define AL_INIT_FAILED -1
#define DESPLAY_INIT_FAILED -2
#define MOV 1

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT* font = NULL;
ALLEGRO_BITMAP* img = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT * que;
ALLEGRO_EVENT event;

const int width = 800;
const int height = 600;

const int img_width = 640;
const int img_height = 480;

int posl = width/2-10;
int posr = width/2+10;
int posu = height/2-10;
int posd = height/2+10;

void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();


int main(int argc, char *argv[]) {
    int msg = 0;
    
    game_init();
    game_begin();
    printf("Hello world!!!\nClose window to terminate.\n");
    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("See you, world\n");
    }
    game_destroy();

    return 0;
}


void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(9);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(AL_INIT_FAILED);
    }
    
    display = al_create_display(width, height);
    event_queue = al_create_event_queue();
    
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-1);
    }
    
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    
    font = al_load_ttf_font( "pirulen.ttf", 72, 0);
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_install_keyboard();
    al_get_keyboard_event_source();
    
}

void game_begin() {
    al_clear_to_color(al_map_rgb(255,200,0));
    
    al_draw_text(font, al_map_rgb(255,255,255), img_width - 80, img_height + 20, ALLEGRO_ALIGN_CENTRE, " text ");
    al_draw_rectangle(posl, posr, posu, posd, al_map_rgb(50, 5, 5), 3);
 
    img = al_load_bitmap("image.jpeg");
    if (img == NULL)
        show_err_msg(-1);
    al_draw_bitmap(img, 0, 0, 0);
 
    al_flip_display();
}

int game_run() {
    int error = 0;
    al_draw_rectangle(posl, posr, posu, posd, al_map_rgb(50, 5, 5), 3);
    if (!al_is_event_queue_empty(event_queue)) error = process_event();
    return error;
}

int process_event() {
    al_wait_for_event(event_queue, que);
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        printf("Game clased!\n");
        return GAME_TERMINATE;
    } else {
        if (event.keyboard.keycode == ALLEGRO_KEY_PGUP) {
            posu-=5;
            posd-=5;
            return MOV;
        } else if (event.keyboard.keycode == ALLEGRO_KEY_PGDN) {
            posu+=5;
            posd+=5;
            return MOV;
        } else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
            posl-=5;
            posr-=5;
            return MOV;
        } else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
            posl+=5;
            posr+=5;
            return MOV;
        }
        return 0;
    }
    
    //else show_err_msg(-1);
}


void game_destroy() {
    al_destroy_display(display);
    al_destroy_bitmap( img );
    al_destroy_event_queue(event_queue);
}
*/


/*
int main(int argc, char **argv){
    
    al_init();
    
    al_create_display(640, 480);
    
    al_clear_to_color(al_map_rgb(255, 0, 255));
    
    al_flip_display();
    
    al_rest(5.0f);
    
    return 0;
}
*/


#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>              //Our primitive header file

#define GAME_TERMINATE 666
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT event;




const int width = 800;
const int height = 600;

int pos_x, pos_y; // The position of rectangle's left-up corner.
bool *keys;
bool draw;

void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();



int main(int argc, char *argv[]) {
    int msg = 0;
    
    game_init();
    game_begin();
    printf("Hello world!!!\n");
    
    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("See you, world\n");
    }
    game_destroy();
    return 0;
}


void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(9);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(-1);
    }
    keys = (bool*) malloc(4 * sizeof(bool));
    memset(keys, false, 4 * sizeof(bool));
    
    draw = true;
    
    pos_x = width / 2;
    pos_y = height / 2;
    
    display = al_create_display(width, height);
    event_queue = al_create_event_queue();
    
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-1);
    }
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    
}

void game_begin() {
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255,0,255));
    al_flip_display();
}

int process_event() {
    al_wait_for_event(event_queue, &event);
    
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        return GAME_TERMINATE;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        if(event.mouse.button == 1)
            draw = !draw;
        else if (event.mouse.button == 2)
            return GAME_TERMINATE;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        pos_x = event.mouse.x;
        pos_y = event.mouse.y;
    }
    else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_KEY_UP) {
        switch(event.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                keys[UP] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                return GAME_TERMINATE;
                break;
        }
    }
    
    
    
    pos_y -= keys[UP] * 10;
    pos_y += keys[DOWN] * 10;
    pos_x -= keys[LEFT] * 10;
    pos_x += keys[RIGHT] * 10;
    if (draw) {
        al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255,0,255));
    }
    
 
    
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    return 0;
}

int game_run() {
    int error = 0;
    if (!al_is_event_queue_empty(event_queue)) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}

