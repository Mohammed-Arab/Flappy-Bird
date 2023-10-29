#include "raster.h"
#include "font.h"
#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "bitmap.h"

int main(){
    int input;
    void *base = Physbase();	
    printf("\033E\033f\n");
	linea0();

/* Tested function: draw_bird
   Purpose of testing: to check whether the
   32x32 bitmap of the bird is plotted at the
   desired location 
*/
    draw_bird(base,6,343);

/* Tested function: plot_solid 
    Purpose of testing: to check whether
    a block of rectangle that runs from 
    (0,370) to (639,370) all the way to 
    the bottom of the screen
*/
	plot_solid(base);

/* Tested function: plot_pipes && plot_hline
   Purpose of teting: Because function plot_pipes
   calls the function plot_hline so it will also
   be tested. This tests 3 scenarios:
    (1) Plot pipes at x = 0 
    (2) Plot pipes at 0 < x < 607
    (3) Plot pipes at x = 607
   ** The gap between top and bottom pipes
   will be tested with different value 
*/
    plot_pipes(base, 0, 50);
    plot_pipes(base, 607, 30);
    plot_pipes(base, 400,40);


    draw_score(base,0, 378, letter_S);
	draw_score(base, 1, 378, letter_C);
	draw_score(base, 2, 378, letter_O);
	draw_score(base, 3, 378, letter_R);
	draw_score(base, 4, 378, letter_E);
	draw_score(base, 5, 378, colons);

	draw_score(base, 6, 378, zero);
	draw_score(base, 7, 378, zero);
	draw_score(base,8, 378, zero);
	draw_score(base, 9, 378, zero);

    scanf("%d", &input);
    while (input != 5)
    {
        if (input == 1) /* clear pipes*/
        {
        clear_pipes(base, 0, 50);
        clear_pipes(base, 607, 30);
        clear_pipes(base, 400,40);
        } else if (input == 2) /*clear_long_word*/
        {
        clear_long_word(base,6,343);
        } else if (input == 3) /* clear_qk */
        {
        clear_qk(base);
        } else if (input == 4) /*clear_word*/
        {
        clear_word(base,0, 378);
	    clear_word(base, 1, 378);
	    clear_word(base, 2, 378);
	    clear_word(base, 3, 378);
	    clear_word(base, 4, 378);
	    clear_word(base, 5, 378);

	    clear_word(base, 6, 378);
	    clear_word(base, 7, 378);
	    clear_word(base,8, 378);
	    clear_word(base, 9, 378);
        }
        scanf("%d", &input);
    }

    Cnecin();
    return 0;
}