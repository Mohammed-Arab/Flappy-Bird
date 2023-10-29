/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: menu.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 8
    Recent Update: April 4thth, 2023
*/

#include "menu.h"

/* Function name: proccess_menu
   Inputs: UINT32 base
    Outputs: menu_option
    Function details: the function plots out the splash screen with the three options
    PLAYER_ONE, PLAYER_TWO and QUIT. it returns which option has been slected.
*/
int proccess_menu(UINT32 *base)
{
    UINT32 input;
    Arrow arrow;
    Arrow *arrow_pointer = &arrow;

    updated_bitmap(base, splash_screen, 0, 0, 640, 400); /*plot splash screen*/
    init_arrow(arrow_pointer);
    render_arrow(base, arrow_pointer);                        /*plot arrow on the screen*/
    updated_bitmap(base, PLAYER_ONE, 9, 200, 128, LONG_WORD); /*plot PLayer one on the screen*/
    updated_bitmap(base, PLAYER_TWO, 9, 240, 128, LONG_WORD); /*plot PLayer two on the screen*/
    updated_bitmap(base, QUIT, 9, 280, 128, LONG_WORD);       /*plot Quit on the screen*/

    /*if Enter is pressed then option is procceeded else if Esc then it returns*/
    while (input != ESC_KEY && input != ENTER_KEY)
    {

        input = Cnecin();

        if (input == DOWN_KEY)
        {
            update_arrow_down(arrow_pointer);
            render_arrow(base, arrow_pointer);
        }
        else if (input == UP_KEY)
        {
            update_arrow_up(arrow_pointer);
            render_arrow(base, arrow_pointer);
        }
    }
    if (input == ESC_KEY)

        return 3;
    else
        return menu_option(arrow_pointer);
}

/* Function name: init_arrow
   Inputs: Arrow *arrow
    Outputs: None
    Function details: initiliazes the slecetion arrow in the screen. 
*/
void init_arrow(Arrow *arrow)
{
    arrow->old_y = 200;
    arrow->new_y = 200;
}

/* Function name: update_arrow_down
   Inputs: Arrow *arrow
    Outputs: None
    Function details: the function updates the arrow if DOWN_KEY is being entered
*/
void update_arrow_down(Arrow *arrow)
{
    if (arrow->old_y == 200)
    {
        arrow->new_y = 240;
    }
    else if (arrow->old_y == 240)
    {
        arrow->new_y = 280;
    }
    else
    {
        arrow->new_y = 200;
    }
}

/* Function name: update_arrow_up
   Inputs: Arrow *arrow
    Outputs: None
    Function details: the function updates the arrow if UP_KEY is being entered
*/
void update_arrow_up(Arrow *arrow)
{
    if (arrow->old_y == 200)
    {
        arrow->new_y = 280;
    }
    else if (arrow->old_y == 240)
    {
        arrow->new_y = 200;
    }
    else
    {
        arrow->new_y = 240;
    }
}

/* Function name: render_arrow
   Inputs: UINT32 base
           Arrow *arrow
    Outputs: None
    Function details: the function renders the position of the arrow
*/
void render_arrow(UINT32 *base, Arrow *arrow)
{
    clear_long_word(base, 8, arrow->old_y);
    arrow->old_y = arrow->new_y;
    updated_bitmap(base, ARROW, 8, arrow->new_y, LONG_WORD, LONG_WORD);
}

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
int menu_option(Arrow *arrow)
{
    if (arrow->new_y == 200)
    {
        return 1;
    }
    else if (arrow->new_y == 240)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}