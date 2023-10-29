/*	Group Student Name: Khanh Le, Mohammed Arab
	Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
	File Name: Raster.h
	Instructor: Paul Pospisil
	Assignment: Flappy Bird - Stage 2
	Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include <linea.h>
#include "font.h"
#include "BITMAP.H"

#define SCREEN_WIDTH_BYTE 80 /* horizontal pixel width for 8 width*/
#define SCREEN_WIDTH_WORD 40 /* horizontal pixel width for 16x6 graph */
#define SCREEN_WIDTH_LONG 20 /* horizontal pixel width for 32x32 graph */
#define SCREEN_HEIGHT 400	 /* Screen height*/
/* acceptable number of pixels between
top and bottom pipes */
#define GAP 90

#define BIRD_WIDTH 32      /* The width of the bird*/
#define PIPE_WIDTH 32      /* The width of the pipe*/
#define LONG_WORD 32       /* Long word = 32 bits*/

#define BIRD_WIDTH 32      /* The width of the bird*/
#define PIPE_WIDTH 32      /* The width of the pipe*/
#define LONG_WORD 32       /* Long word = 32 bits*/

/* The x position of the ground
 */
#define GROUND 370

/* The final pixel x position of the screen*/
#define X_SCREEN_BOUNDARY 639

/**************************** NEED TO BE FINISHED ****************************/

/* Function name: updated_bitmap
   Inputs: UINT32 *base
		   UINT32 bitmap[]
		   UINT16 x_position
		   UINT16 y_position
		   UINT16 bitmap_width
		   UINT16 bitmap_height
	Output: None
	Function details: 

*/
void updated_bitmap(UINT32 *base, UINT32 bitmap[], UINT16 x_position, UINT16 y_position, UINT16 bitmap_widtth, UINT16 bitmap_height);

/**************************************************************************************************************/

/* Function name: clear_qk
   Input: UINT32 * 
   Output: None
   Source code: The definition of this function is written in 
   assembly language. It is located in file RAST_ASM.S
   Function details: The function clears the enitre screen 
   with the size 640x400 pixels
*/
void clear_qk(UINT32 *);

UINT16 *get_video_base();
void set_video_base(UINT16 *base);


/*
*/
void clear_screen(UINT32 *);
/* 	Function name: clear_long_world
	Input: UINT32 *base
		   unsigned int starting_x
		   unsigned int starting_y
	Output: None
	Function details: The function turn off 32 bits
	starting from the passed vertex(x,y) to vertex
	(x + 32, y+ 32)
*/
void clear_long_word(UINT32 *base, unsigned int starting_x, unsigned int starting_y);


/* 	Function name: clear_world
	Input: UINTT16 *base
		   unsigned int starting_x
		   unsigned int starting_y
	Output: None
	Function details: The function turn off 16 bits
	starting from the passed vertex(x,y) to vertex
	(x + 16, y+ 16)
*/
void clear_word(UINT16 *base, unsigned int starting_x, unsigned int starting_y);


/* 	Function name: clear_draw_score
	Input: UINT16 *base
		   unsigned int x
		   unsigned int y
		   unsigned int bitmap[]
	Output: None
	Function details: The function draw 16x16 bitmap
	starting from x and y that are passed by the caller
*/
void draw_score(UINT16 *base, unsigned int x, unsigned int y, unsigned int bitmap[]);


/*  Function name: select_num_bitmap
	Input: UINT16 *base
		   unsigned int number
		   unsigned int num_x_pos
		   unsigned int num_y_pos
	Output: None
	Function details: The function select the bitmap for each digit of
	the score and plotting the bitmap at the specified vertex(x,y) passed
	by the caller
*/
void select_num_bitmap(UINT16 *base, unsigned int number, unsigned int num_x_pos,
					   unsigned int num_y_pox);


/*	Function Name: clear_region
	Input: UINT32 * base
		   unsigned int starting_x
		   unsigned int ending_x
		   unsigned starting_y
		   unsigned ending_y
	Output: None
	Fuction Details: The function will clear a region starting at the specified
	starting vertices to the specified ending vertices passed by the caller.
*/
void clear_region(UINT32 *base, unsigned int starting_x, unsigned int ending_x, unsigned int starting_y, unsigned int ending_y);


/*	Function Name: clear_bit
	Input: UINT32 *base
		   unsigned int x_pos
		   unsigned int y_pos
	Output: None
	Function Details: The function clear a single pixel at the specified
	vertice (x position, y position) that is passed by the caller.
*/
void clear_bit(UINT32 *base, unsigned int x_pos, unsigned int y_pos);


/*	Function Name: draw_entire_screen
	Input: pointer UINT16 *base
	Output: None
	Function Details: The function draws the entire screen.
	The entire screen is in black.
*/
void draw_entire_screen(UINT16 *base);


/*	Function Name: draw_bird
	Input: pointer UINT32 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
	Output: None
	Function Details: The function plots the bird by using the bitmap
	provided in raster.c file called bird_bitmap, which is 32x32 px.
	The caller chooses which pixel vertices for the graph to be plotted.
*/
void draw_bird(UINT32 *base, int x, int y);

/*	Function name: plot_pixel
	Input: pointer UINT16 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
		   int screen_width
		   int screen_height
	Output: None
	Function Details: The function plots a single pixel into the screen.
	The user chooses which pixel vertice the dot will be plotted.
*/
void plot_pixel(UINT16 *base, int x, int y);

/*	Function Name: plot_hline
	Input: pointer UINT32 *base
		   int starting_x
		   int ending_x
		   int x1
		   int x2
	Output: None
	Function Details: The function plots a single horizontal line starting
	frome one x coordinate to another ending x coordinate being passed by
	the caller.
*/
void plot_hline(UINT32 *base, int starting_x, int ending_x, int y);

/*	Function Name: plot_vline
	Input: pointer UINT16 *base
		   int x
		   int y1
		   int y2
	Output: None
	Function Details: The function plots a single vertical line starting
	frome one y coordinate to another ending y coordinate being passed by
	the caller.
*/
void plot_vline(UINT16 *base, int x, int y1, int y2);

/* Function Name: plot_bitmap
	Input: pointer UINT16 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
		   int bitmap_height
		   int graph_width
		   int bitmap[]
	Output: None
	Function Details: The function plots the bitmap of the graph at the
	chosen pixel vertice by the caller. The caller can decide the width
	of the graph.
*/
void plot_bitmap(UINT32 *base, int x, int y, int bitmap_height, int graph_width, UINT32 bitmap[]);

/*	Function Name: plot_pipes
	Input: pointer UINT16 *base
		   int x (ie: x coordinate)
		   int start_gap(ie: the horizontal between 2 pairs of pipes)
	Output: None
	Function Details: The function plots a pair of pipes, one is at the
	top	and another is at the bottom at the chosen x coordinate. The gap
	between the top and bottom pipes will be determined by the caller.
*/
void plot_pipes(UINT32 *base, int x, int start_gap);

/*	Function Name: plot_solid
	Input: pointer UINT16 *base
	Output: None
	Function Details: The function draws a solid block horizontally to
	represent the ground in the game. The solid block starts at pixel 370
	to pixel 399.
*/
void plot_solid(UINT32 *base);

/* Function name: clear_pipes
   Input: UINT32 *base
		  int x
		  int start_gap
	Output: None
	Function details: The function remove/clear a
	pair of pipes(top and bottom pipes). The size
	of the pipe is 32 bit wide. The pipes are cleared
	starting from specified x to x plus 32. The function
	does not clear the area starting from the start_gap
	position until the top line of the bottom pipe
*/
void clear_pipes(UINT32 *base, int x, int start_gap);

/*	Function Name: clear_hline
	Input: pointer UINT32 *base
		   int ending_x
		   int starting_x
		   int y
	Output: None
	Function Details: The function clear a single horizontal line starting
	frome one x coordinate to another ending x coordinate being passed by
	the caller.
*/
void clear_hline(UINT32 *base, int starting_x, int ending_x, int y);


#endif
