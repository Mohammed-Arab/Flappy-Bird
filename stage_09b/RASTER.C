/*	Group Student Name: Khanh Le, Mohammed Arab
	Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
	File Name: Raster.c
	Instructor: Paul Pospisil
	Assignment: Flappy Bird - Stage 2
	Recent Update: March 17th, 2023
*/
#include "raster.h"

/* 	Function name: clear_long_world
	Input: UINT32 *base
		   unsigned int starting_x
		   unsigned int starting_y
	Output: None
	Function details: The function turn off 32 bits
	starting from the passed vertex(x,y) to vertex
	(x + 32, y+ 32)
*/
void clear_long_word(UINT32 *base, unsigned int starting_x, unsigned int starting_y)
{
	int i = 0;
	while (i < 32)
	{
		*(base + starting_x + (starting_y + i) * SCREEN_WIDTH_LONG) = 0x00000000;
		i++;
	}
}

/* 	Function name: clear_world
	Input: UINTT16 *base
		   unsigned int starting_x
		   unsigned int starting_y
	Output: None
	Function details: The function turn off 16 bits
	starting from the passed vertex(x,y) to vertex
	(x + 16, y+ 16)
*/
void clear_word(UINT16 *base, unsigned int starting_x, unsigned int starting_y)
{
	int i = 0;
	while (i < 32)
	{
		*(base + starting_x + (starting_y + i) * SCREEN_WIDTH_WORD) = 0x0000;
		i++;
	}
};

/* 	Function name: clear_draw_score
	Input: UNIT16 *base
		   unsigned int x
		   unsigned int y
		   unsigned int bitmap[]
	Output: None
	Function details: The function draw 16x16 bitmap
	starting from x and y that are passed by the caller
*/
void draw_score(UINT16 *base, unsigned int x, unsigned int y, unsigned int bitmap[])
{
	int i = 0;
	while (i < 16)
	{
		*(base + x + (y + i) * SCREEN_WIDTH_WORD) = bitmap[i];
		i++;
	}
}
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
					   unsigned int num_y_pox)
{
	if (number == 0)
	{
		draw_score(base, num_x_pos, num_y_pox, zero);
	}
	else if (number == 1)
	{
		draw_score(base, num_x_pos, num_y_pox, one);
	}
	else if (number == 2)
	{
		draw_score(base, num_x_pos, num_y_pox, two);
	}
	else if (number == 3)
	{
		draw_score(base, num_x_pos, num_y_pox, three);
	}
	else if (number == 4)
	{
		draw_score(base, num_x_pos, num_y_pox, four);
	}
	else if (number == 5)
	{
		draw_score(base, num_x_pos, num_y_pox, five);
	}
	else if (number == 6)
	{
		draw_score(base, num_x_pos, num_y_pox, six);
	}
	else if (number == 7)
	{
		draw_score(base, num_x_pos, num_y_pox, seven);
	}
	else if (number == 8)
	{
		draw_score(base, num_x_pos, num_y_pox, eight);
	}
	else if (number == 9)
	{
		draw_score(base, num_x_pos, num_y_pox, nine);
	}
}
/*	Function Name: draw_entire_screen
	Input: pointer UINT16 *base
	Output: None
	Function Details: The function draws the entire screen.
	The entire screen is in black.
*/
void draw_entire_screen(UINT16 *base)
{
	int x = 0;
	int y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH_WORD)
		{
			*(base + x + y * SCREEN_WIDTH_WORD) = 0xFFFF;
			x++;
		}
		y++;
	}
}


/*	Function Name: draw_bird
	Input: pointer UINT32 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
	Output: None
	Function Details: The function plots the bird by using the bitmap
	provided in this file bird_bitmap, which is 32x32 px. The caller
	chooses which pixel vertices for the graph to be plotted.
*/
void draw_bird(UINT32 *base, int x, int y)
{
	int i = 0;
	while (i < 32)
	{
		*(base + x + (y + i) * SCREEN_WIDTH_LONG) = bird_bitmap[i];
		i++;
	}
}


/*	Function name: plot_pixel
	Input: pointer UINT16 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
	Output: None
	Function Details: The function plots a single pixel into the screen.
	The user chooses which pixel vertice the dot will be plotted.

*/
void plot_pixel(UINT16 *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH_WORD && y >= 00 && y < SCREEN_HEIGHT)
	{
		*(base + (x >> 4) + y * SCREEN_WIDTH_WORD) |= 1 << 15 - (x % 15);
	}
}


/*	Function Name: clear_region
	Input: UINT32 * base
		   unsigned int starting_x
		   unsigned int ending_x
		   unsigned xy
		   unsigned ending_y
	Output: None
	Fuction Details: The function will clear a region starting at the specified
	starting vertices to the specified ending vertices passed by the caller.
*/
void clear_region(UINT32 *base, unsigned int starting_x, unsigned int ending_x, unsigned int xy, unsigned int ending_y)
{
	int counter;
	int counter_02;

	for (counter_02 = xy; counter_02 <= ending_y; counter_02++)
	{
		for (counter = starting_x; counter <= ending_x; counter++)
		{
			clear_bit(base, counter, counter_02);
		}
	}
}


/*	Function Name: clear_bit
	Input: UINT32 *base
		   unsigned int x_pos
		   unsigned int y_pos
	Output: None
	Function Details: The function clear a single pixel at the specified
	vertice (x position, y position) that is passed by the caller.
*/
void clear_bit(UINT32 *base, unsigned int x_pos, unsigned int y_pos)
{

	/* *(base + (x_pos >> 3) + y_pos * SCREEN_WIDTH_BYTE) &= ~(1 << (x_pos & 7)); */

	while (y_pos < 400)
	{
		*(base + (y_pos * SCREEN_WIDTH_LONG) + (x_pos >> 5)) &= ~(1 << (31 - (x_pos & 31)));
		y_pos++;
	}
}


/*	Function Name: plot_hline
	Input: pointer UINT32 *base
		   int ending_x
		   int starting_x
		   int y
	Output: None
	Function Details: The function plots a single horizontal line starting
	frome one x coordinate to another ending x coordinate being passed by
	the caller.
*/
void plot_hline(UINT32 *base, int starting_x, int ending_x, int y)
{
	int temp;
	UINT32 *p;
	UINT32 *row_start;
	UINT32 *row_end;
	UINT32 start_mask;
	UINT32 end_mask;
	UINT32 mask;
	if (y >= 0 && y < 400)
	{
		if (starting_x > ending_x)
		{
			temp = starting_x;
			starting_x = ending_x;
			ending_x = temp;
		}
		if (starting_x < 0)
			starting_x = 0;
		if (ending_x > 639)
			return;
		row_start = base + (starting_x >> 5) + y * 20;	   /*finds the UINT32 where it needs to get plotted*/
		row_end = base + (ending_x >> 5) + y * 20;		   /*finds the UINT32 where it will stop plotting*/
		start_mask = (0xFFFFFFFF >> (starting_x & 31));	   /*finds the bit where it needs to get plotted*/
		end_mask = (0xFFFFFFFF << (31 - (ending_x & 31))); /*finds the bit where it will stop plotting*/
		if (row_start == row_end)
		{
			mask = start_mask & end_mask; /*if plotting is being done in the same UINT32 then it masks both starting and ending bits*/
			*row_start |= mask;
		}
		else
		{
			*row_start |= start_mask; /*sets that starting bit in row_start*/
			*row_end |= end_mask;	  /*sets that ending bit in row_end*/
			p = row_start + 1;		  /*p = first long word + 1 goes to 2nd long word*/
			while (p < row_end)
			{
				*p = 0xFFFFFFFF; /*Set each byte to all ones*/
				p++;
			}
		}
	}
	return;
}


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
void plot_vline(UINT16 *base, int x, int y1, int y2)
{
	int temp;
	UINT16 pattern;
	UINT16 *screen_byte;
	if (x >= 0 && x < 640)
	{
		if (y1 > y2)
		{
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if (y1 < 0)
			y1 = 0;
		if (y2 > 399)
			y2 = 399;
		pattern = 1 << (15 - (x & 15));
		screen_byte = base + y1 * 40 + (x >> 4);
		for (; y1 <= y2; y1++)
		{
			*screen_byte = pattern;
			screen_byte = screen_byte + 40;
		}
	}
	return;
}
/* Function Name: plot_bitmap
	Input: pointer UINT16 *base
		   int x (ie: x coordinate)
		   int y (ie: y coordinate)
		   int bitmap_height
		   int graph_width
		   int bitmap[]
	Output: None
	Function Details: The function plots the bitmap of the graph at the
	chosen pixel vertice by the caller. The caller can decides the width
	of the graph.
*/
void plot_bitmap(UINT32 *base, int x, int y, int bitmap_height, int graph_width, UINT32 bitmap[])
{
	int i;
	i = 0;
	while (i < bitmap_height)
	{
		*(base + x + (y + i) * graph_width) = bitmap[i];
		i++;
	}
}
/*	Function Name: plot_pipes
	Input: pointer UINT32 *base
		   int x (ie: x coordinate)
		   int start_gap(ie: the horizontal between 2 pairs of pipes)
	Output: None
	Function Details: The function plots a pair of pipes, one is at the
	top	and another is at the bottom at the chosen x coordinate. The gap
	between the top and bottom pipes will be determined by the caller.
*/
void plot_pipes(UINT32 *base, int x, int start_gap)
{
	int i;
	int y1;
	int y2;
	y1 = 0;
	if (start_gap >= 30 && start_gap <= 223)
	{
		while (y1 < start_gap)
		{
			plot_hline(base, x, x + PIPE_WIDTH, y1);
			/*plot_hline1(base, y1, x, x + 32);*/
			y1++;
		}
		y2 = start_gap + GAP; /*gap between top and bottom pipes = 100*/
		while (y2 < GROUND)
		{
			plot_hline(base, x, x + PIPE_WIDTH, y2);
			/*plot_hline1(base, y2, x, x + 32);*/
			y2++;
		}
	}
}
/*	Function Name: plot_solid_ground
	Input: pointer UINT16 *base
	Output: None
	Function Details: The function draws a solid block horizontally to
	represent the ground in the game. The solid block starts at pixel 370
	to pixel 399.
*/

void plot_solid(UINT32 *base)
{
	int y = GROUND;
	plot_hline(base, 0, X_SCREEN_BOUNDARY, y);
	y++;
	while (y < 400)
	{
		plot_hline(base, 160, X_SCREEN_BOUNDARY, y);
		y++;
	}
}
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
void clear_pipes(UINT32 *base, int x, int start_gap)
{
	int y;
	y = 0;

	while (y < start_gap)
	{
		*(base + y * SCREEN_WIDTH_LONG + (x >> 5)) = 0x00000000;
		*(base + y * SCREEN_WIDTH_LONG + (x + PIPE_WIDTH >> 5)) = 0x00000000;
		y++;
	}
	y += GAP;
	while (y < GROUND)
	{
		*(base + y * 20 + (x >> 5)) = 0x00000000;
		*(base + y * 20 + (x + PIPE_WIDTH >> 5)) = 0x00000000;
		y++;
	}
}

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
void clear_hline(UINT32 *base, int starting_x, int ending_x, int y)
{
	int temp;
	UINT32 *row_start;
	UINT32 *row_end;
	UINT32 start_mask;
	UINT32 end_mask;
	UINT32 mask;
	if (y >= 0 && y < 400)
	{
		if (starting_x > ending_x)
		{
			temp = starting_x;
			starting_x = ending_x;
			ending_x = temp;
		}
		if (starting_x < 0)
			starting_x = 0;
		if (ending_x > 639)
			return;
		row_start = base + (starting_x >> 5) + y * 20;		/*finds the UINT32 where it needs to get cleared*/
		row_end = base + (ending_x >> 5) + y * 20;			/*finds the UINT32 where it will stop clearing*/
		start_mask = ~(0xFFFFFFFF >> (starting_x & 31));	/*finds the bit where it needs to get cleared*/
		end_mask = ~(0xFFFFFFFF << (31 - (ending_x & 31))); /*finds the bit where it will stop clearing*/
		if (row_start == row_end)
		{
			mask = start_mask & end_mask; /*if clearing is being done in the same UINT32 then it masks both starting and ending bits*/
			*row_start &= ~mask;
		}
		else
		{
			*row_start &= ~start_mask; /*clears starting from first bit*/
			*row_end &= ~end_mask;	   /*clears untill it gets last bit*/
		}
	}
	return;
}

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
void updated_bitmap(UINT32 *base, UINT32 bitmap[], UINT16 x_position, UINT16 y_position, UINT16 bitmap_widtth, UINT16 bitmap_height)
{
	int i = 0;
	int height = 0;
	int curr_index = 0;
	while (height < bitmap_height)
	{
		while (i < (bitmap_widtth / LONG_WORD))
		{
			*(base + (x_position + i) + y_position * 20) = bitmap[curr_index];
			curr_index++;
			i++;
		}
		y_position++;
		height++;
		i = 0;
	}
}