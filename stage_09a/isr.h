/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: isr.h
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 9a
    Recent Update: April 4thth, 2023
*/
#ifndef isr_h
#define isr_h


#include "music.h"
#include "types.h"


#define VBL_ISR 28

typedef void (*Vector) ();
/*
 * Timers, used by VBL
 */
extern int MUSIC_TIMER;
extern int GAME_TIMER;

/*
 * Render, if followind flags set to true == 1
 */
extern int RENDER_REQUEST;

/*Source code: code written in assembly 
 in the vbl.s*/
void vbl_isr();

/*  Function name: vbl_req()
    Inputs: None
    Outputs: None
    Functiond details:
    Sending the request to interupt 
    the register when the time ticks
*/
void vbl_req();

/*  Function name: instal_vectors
    Inputs: None
    Outputs: None
    Function details: The fuction loads
    the vector of VBL 
*/
void install_vectors();
/* Function name: remove_vectors
   Inputs: None
   Outputs: None
   Function details: The function remove
   the control over the VBL vector to set 
   the system back to normal state 

*/
void remove_vectors();

Vector install_vector(int num, Vector vector);

#endif