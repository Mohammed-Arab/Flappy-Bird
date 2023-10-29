/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: isr.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 9a
    Recent Update: April 4thth, 2023
*/
#include"isr.h"

Vector vbl_vector;
MUSIC_TIMER = 0;
GAME_TIMER = 0;
RENDER_REQUEST = 1;

/*  Function name: vbl_req()
    Inputs: None
    Outputs: None
    Functiond details:
    Sending the request to interupt for VBL to
    the register when the time ticks
*/
void vbl_req() {

  MUSIC_TIMER++;
  GAME_TIMER++;
  RENDER_REQUEST = 1;
}

/*  Function name: instal_vectors
    Inputs: None
    Outputs: None
    Function details: The fuction loads
    the vector of VBL 
*/
void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
}
/* Function name: remove_vectors
   Inputs: None
   Outputs: None
   Function details: The function remove
   the control over the VBL vector to set 
   the system back to normal state 

*/
void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
}

Vector install_vector(int num, Vector vector) {
  Vector* vectp = (Vector *) ((long) num << 2);
  Vector orig;
  long old_ssp = Super(0);

  orig = *vectp;
  *vectp = vector;

  Super(old_ssp);
  return orig;
}