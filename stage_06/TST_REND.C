/*	Group Student Name: Khanh Le, Mohammed Arab
	Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
	File Name: Raster.c
	Instructor: Paul Pospisil
	Assignment: Flappy Bird - Stage 2
	Recent Update: February 15th, 2023
*/
#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "font.h"
#include "raster.h"
#include "render.h"
#include <linea.h>

#define BIRD_INIT_Y 150

void set_up_game(UINT32 *base, UINT16 *base_16, Bird *bird_ptr,
				 Pipe *pipe_ptr, Score *score_ptr);
void disable();
UINT32 get_time();
UINT8 *get_base(UINT8 *second_buffer);
UINT8 back_buffer_screen[32256];

int main()
{

	UINT32 timeThen, timeNow, timeElapsed;

	Pipe pipe;
	Pipe *pipe_ptr = &pipe;

	Score score = {0, SCORE_Y_POS, 0, 1, 6, 7, 8, 9, 0, 0, 0, 0, 0};
	Score *score_ptr = &score;

	Bird bird = {BIRD_X_POSITION};
	Bird *bird_ptr = &bird;

	char start_input;
	char jump_input;

	int game_over = 0;
	int swap_screen = 0;


	void *base = Physbase();
	

	void *back_buffer = get_base(back_buffer_screen);
	int bufferCounter = 0;
	timeThen = get_time();
	clear_qk(base);
	linea0();
	disable();
	
		set_up_game(base, base, bird_ptr, pipe_ptr, score_ptr);
		start_input = Cconin();
		while (start_input != SPACE_KEY)
		{
			start_input = Cconin();
		}
		while (!check_collision(bird_ptr, pipe_ptr))
		{
			timeNow = get_time();
			timeElapsed = timeNow - timeThen;

			update_bird(bird_ptr, jump_input);

			if (timeElapsed >= 1)
			{
				bird_falls(bird_ptr);
				update_pipes( pipe_ptr, PIPE_SPEED);
				if (swap_screen == 0)
				{
					render_game(base, base, bird_ptr, pipe_ptr, score_ptr);
					swap_screen++;
				}
				else
				{
					render_game(back_buffer, back_buffer, bird_ptr, pipe_ptr, score_ptr);
					swap_screen--;
				}
			
			}
			if (score_detection(bird_ptr, pipe_ptr))
			{
				score_ptr->score_counter += 1;
				update_score(score_ptr, strike_detection(score_ptr));
				extract_score(score_ptr);
			}

			timeThen = timeNow;
		}
		



	 Setscreen(-1, base, -1);
	Vsync();
	return 0;
}

UINT32 get_time()
{
	UINT32 timeNow;
	long old_ssp;

	old_ssp = Super(0); /* enter privileged mode */
	timeNow = *((UINT32 *)0x462);
	Super(old_ssp); /* exit privileged mode as soon as possible */

	return timeNow;
}

void set_up_game(UINT32 *base_32, UINT16 *base_16, Bird *bird_ptr,
				 Pipe *pipe_ptr, Score *score_ptr)
{

	clear_qk(base_32);
	init_pipes(pipe_ptr);
	initialize_bird(bird_ptr, BIRD_INIT_Y, 2);

	plot_solid(base_32);
	draw_score(base_16, score_ptr->score_x_pos, SCORE_Y_POS, letter_S);
	draw_score(base_16, score_ptr->score_x_pos + 1, SCORE_Y_POS, letter_C);
	draw_score(base_16, score_ptr->score_x_pos + 2, SCORE_Y_POS, letter_O);
	draw_score(base_16, score_ptr->score_x_pos + 3, SCORE_Y_POS, letter_R);
	draw_score(base_16, score_ptr->score_x_pos + 4, SCORE_Y_POS, letter_E);
	draw_score(base_16, score_ptr->score_x_pos + 5, SCORE_Y_POS, colons);

	draw_score(base_16, score_ptr->thousandth_x_pos, SCORE_Y_POS, zero);
	draw_score(base_16, score_ptr->hundredth_x_pos, SCORE_Y_POS, zero);
	draw_score(base_16, score_ptr->tenth_x_pos, SCORE_Y_POS, zero);
	draw_score(base_16, score_ptr->oneth_x_pos, SCORE_Y_POS, zero);
	draw_bird(base_32, BIRD_X_POSITION, bird_ptr->y_pos);
}

UINT8 *get_base(UINT8 *second_buffer)
{
	UINT8 *base;
	UINT16 difference;
	base = second_buffer;
	difference = (int)base;
	difference %= 0x100;
	difference = 0x100 - difference;
	return base + difference;
}
void disable()
{
	printf("\033f");
	fflush(stdout);
}
