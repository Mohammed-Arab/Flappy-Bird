/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: Render.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 4
    Recent Update: March 17th, 2023
*/
#include "render.h"

/* Function name: render_pipes
   Input: UNIT32 *base
          const Pipe *pipe
          int speed
    Function details: The function render the motion of
    the pipe by removing the pipe at the old position and
    re-plotting the pipe at the new position. The speed
    of the pipe determines how many pixel the pipe moves
*/
void render_pipes(UINT32 *base, const Pipe *pipe, int speed)
{
    /*clear_pipes(base, pipe->x + speed, pipe->start_gap);*/
    plot_pipes(base, pipe->x, pipe->start_gap);
}

/* Function name: render_bird
   Input: UNIT *base
          Bird *bird
   Output: None
   Function details: The function reder the motion of the bird
   by removing the bird at the old position and re-plotting the
   bird at the new position.
*/
void render_bird(UINT32 *base, Bird *bird)
{
    /*clear_long_word(base, BIRD_X_POSITION, bird->old_y_pos);*/
    draw_bird(base, BIRD_X_POSITION, bird->y_pos);
}

/*  Function name: render_score
    Input: UINT16 *base,
           Score *score
    Output: None
    Function details: The function removes/clears each digit
    at the current position and re-plotts each digit at current
    position
*/
void render_score(UINT16 *base, Score *score)
{
    clear_word(base, score->thousandth_x_pos, score->fixed_y_pos);
    clear_word(base, score->hundredth_x_pos, score->fixed_y_pos);
    clear_word(base, score->tenth_x_pos, score->fixed_y_pos);
    clear_word(base, score->oneth_x_pos, score->fixed_y_pos);

    draw_score(base, score->score_x_pos, SCORE_Y_POS, letter_S);
    draw_score(base, score->score_x_pos + 1, SCORE_Y_POS, letter_C);
    draw_score(base, score->score_x_pos + 2, SCORE_Y_POS, letter_O);
    draw_score(base, score->score_x_pos + 3, SCORE_Y_POS, letter_R);
    draw_score(base, score->score_x_pos + 4, SCORE_Y_POS, letter_E);
    draw_score(base, score->score_x_pos + 5, SCORE_Y_POS, colons);

    select_num_bitmap(base, score->thousandth_digit, score->thousandth_x_pos, score->fixed_y_pos);
    select_num_bitmap(base, score->hundredth_digit, score->hundredth_x_pos, score->fixed_y_pos);
    select_num_bitmap(base, score->tenth_digit, score->tenth_x_pos, score->fixed_y_pos);
    select_num_bitmap(base, score->oneth_digit, score->oneth_x_pos, score->fixed_y_pos);
}

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
void render_game(UINT32 *base, UINT16 *base_word, Bird *bird, Pipe *pipe, Score *score_ptr)
{
    clear_screen(base);
    render_bird(base, bird);
    render_pipes(base, pipe, PIPE_SPEED);
    plot_hline(base, 0, 639, 370);
    plot_solid(base);

    /*Setscreen(-1, base, -1);*/
    set_video_base(base_word);
    render_score(base_word, score_ptr);

    return;
}
