#include "raster.h"
#include "font.h"
#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "bitmap.h"
#include "model.h"

int main(){
    int counter = 0;
    
    Pipe pipe;
    Pipe *pipe_ptr = &pipe;

    Bird bird = {7};
	Bird *bird_ptr = &bird;

    Score score = {0, 200, 0, 1, 6, 7, 8, 9, 0, 0, 0, 0, 0};
	Score *score_ptr = &score;

    UINT32 input;

    init_pipes(pipe_ptr);
    initialize_bird(bird_ptr, 20, 16);

    /* Function tested: update_pipes
       Purpose of testing: to check whether
       the function updates the x position of the
       pipes
    */

    for (counter = 0; counter < 3; counter++)
    {
        printf("Old x of pipes: %d \n", (int) pipe_ptr->x);
        update_pipes(pipe_ptr, PIPE_SPEED);
        printf("New x of pipes: %d \n", (int) pipe_ptr->x);
    }
    /* Function tested: update_bird
       Purpose of testing: to check whether the 
       function updates the y position of the bird
       when it flaps up
    */
        input = Cconin();
        printf("Old y of bird: %u \n", bird_ptr -> y_pos);
        update_bird(bird_ptr,input);
        printf("New y of bird: %u \n", bird_ptr -> y_pos);

    /* Function tested: update_bird
       Purpose of testing: to check whether the 
       function updates the y position of the bird
       when it falls down
    */
        initialize_bird(bird_ptr, 20, 16);
        printf("Old y of bird: %u \n", bird_ptr -> y_pos);
        bird_falls(bird_ptr);
        printf("New y of bird: %u \n", bird_ptr -> y_pos);


    /* Function tested: update_score 
       Purpose of testing: Check whether the function
       updates the earned score and score in both case
       of there is strike and there is not strike 
    */    
        printf("Old score: %u \n", score_ptr -> score);
        printf("Old earned score: %u \n", score_ptr -> earned_score);
        update_score(score_ptr, 0);
        printf("New score: %u \n", score_ptr -> score);
        printf("Old earned score: %u \n", score_ptr -> earned_score);

        printf("Old score: %u \n", score_ptr -> score);
        printf("Old earned score: %u \n", score_ptr -> earned_score);
        update_score(score_ptr, 1);
        printf("New score: %u \n", score_ptr -> score);
        printf("Old earned score: %u \n", score_ptr -> earned_score);

    return 0;
}