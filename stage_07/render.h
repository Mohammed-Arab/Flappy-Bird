/*	Group Student Name: Khanh Le, Mohammed Arab
       Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
       File Name: Render.h
       Instructor: Paul Pospisil
       Assignment: Flappy Bird - Stage 4
       Recent Update: March 17th, 2023
*/
#ifndef render_h
#define render_h

#include <stdio.h>
#include "types.h"
#include "model.h"
#include "raster.h"
#include "font.h"

#define SCORE_Y_POS 378
#define PIPE_SPEED 17

/* Function name: render_pipes
   Input: UNIT32 *base
          const Pipe *pipe
          int speed
    Function details: The function render the motion of
    the pipe by removing the pipe at the old position and
    re-plotting the pipe at the new position. The speed
    of the pipe determines how many pixel the pipe moves
*/
void render_pipes(UINT32 *base, const Pipe *pipe, int speed);

/* Function name: render_bird
   Input: UNIT *base
          Bird *bird
   Output: None
   Function details: The function reder the motion of the bird
   by removing the bird at the old position and re-plotting the
   bird at the new position.
*/
void render_bird(UINT32 *base, Bird *bird);

/*  Function name: render_score
    Input: UINT16 *base,
           Score *score
    Output: None
    Function details: The function removes/clears each digit
    at the current position and re-plotts each digit at current
    position
*/
void render_score(UINT16 *base, Score *score);

/* Function name: render_game
   Inputs: UINT32 base
           UINT16base_word
           Bird * bird
           Pipe pipe 
           Scorescore_ptr
    Outputs: None
    Function details: the function is a master render function
    that renders the entire game objects 
*/
void render_game(UINT32 *base, UINT16 *base_word, Bird *bird, Pipe *pipe, Score *score_ptr);

#endif