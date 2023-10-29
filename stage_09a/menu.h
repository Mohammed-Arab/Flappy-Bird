/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: menu.h
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 8
    Recent Update: April 4thth, 2023
*/

#ifndef menu_h
#define menu_h

#include "model.h"
#include "BITMAP.H"
#include "render.h"
#include "font.h"

/*
Aroow struct contains UINT16 old_y, and UINT16 new_y.
old_y is where it will get cleared and new_y is where it will be plotted..
*/
typedef struct
{
	UINT16 old_y;
	UINT16 new_y;

} Arrow;


/* Function name: proccess_menu
   Inputs: UINT32 base
    Outputs: menu_option
    Function details: the function plots out the splash screen with the three options
    PLAYER_ONE, PLAYER_TWO and QUIT. it returns which option has been slected.
*/
int proccess_menu(UINT32 *base);

/* Function name: init_arrow
   Inputs: Arrow *arrow
    Outputs: None
    Function details: initiliazes the slecetion arrow in the screen. 
*/
void init_arrow(Arrow *arrow);

/* Function name: update_arrow_down
   Inputs: Arrow *arrow
    Outputs: None
    Function details: the function updates the arrow if DOWN_KEY is being entered
*/
void update_arrow_down(Arrow *arrow);

/* Function name: update_arrow_up
   Inputs: Arrow *arrow
    Outputs: None
    Function details: the function updates the arrow if UP_KEY is being entered
*/
void update_arrow_up(Arrow *arrow);

/* Function name: render_arrow
   Inputs: UINT32 base
           Arrow *arrow
    Outputs: None
    Function details: the function renders the position of the arrow
*/
void render_arrow(UINT32 *base, Arrow *arrow);

/* Function name: render_game
   Inputs: UINT32 base
           UINT16base_word
           Bird * bird
           Pipe pipe 
           Scorescore_ptr
    Outputs: menu option
    Function details: the function menu option returns 1 if 1-playe is being slected, 2 if 2-player mode is slected
            and 3 if quit or esc key is being entereds 
*/
int menu_option(Arrow *arrow);
#endif