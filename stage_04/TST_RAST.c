#include "raster.h"
#include "font.h"
#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "bitmap.h"
#include "model.h"
#include "render.h"

int main(){
    int counter = 0;
    
    Pipe pipe;
    Pipe *pipe_ptr = &pipe;

    Bird bird = {7};
	Bird *bird_ptr = &bird;

    Score score = {0, 200, 0, 1, 6, 7, 8, 9, 0, 0, 0, 0, 0};
	Score *score_ptr = &score;

    char input;

    void *base = Physbase();	
    void *second_base = base;
    printf("\033E\033f\n");
	linea0();

    init_pipes(pipe_ptr);
    initialize_bird(bird_ptr, 200, 2);
/* Function tested: render_bird
   Purpose of testing: test the render 
   of the bird
*/
    draw_bird(base, 7, 200);
    input = Cconin();
    update_bird(bird_ptr, input);
    render_bird(base,bird_ptr);
/* Function tested: render_pipes
   Purpose of testing: test the render 
   of the pipes
*/
    plot_pipes(base, 10, 30);
    update_pipes(pipe_ptr, PIPE_SPEED);
    render_pipes(base, pipe_ptr, PIPE_SPEED);
/* Function tested: render_score
   Purpose of testing: test the render 
   of the score
*/
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
    for (counter = 0; counter < 3; counter++)
    {
        score_ptr -> score = counter;
        extract_score(score_ptr);
        render_score(base, score_ptr);
    }
    Cnecin();


    return 0;
}