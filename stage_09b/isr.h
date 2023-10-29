/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: isr.h
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 9b
    Recent Update: April 4thth, 2023
*/
#ifndef isr_h
#define isr_h


#include "music.h"
#include "types.h"


#define VBL_ISR 28
#define IKBD_ISR 70

extern UINT8 repeated_key;
extern UINT8 key_repeat;

#define MFB_BIT_6_MASK_OFF 0xbf
#define MFB_BIT_6_MASK_ON 0x40


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
code in the vbl.s*/
void vbl_isr();
/*  Function name: vbl_req()
    Inputs: None
    Outputs: None
    Functiond details:
    Sending the request to interupt 
    the register when the time ticks
*/
void vbl_req();
/*Source code: code written in assembly
code in isr.s*/
void ikbd_isr();
/*  Function name: ikbd_irq
    Inputs: None
    Outputs: None
    Function details: The function sends the 
    IKBD request to interrup the IKBD to control
    the keyboard 
*/
void ikbd_irq();
/*  Function name: write_to_ikbd_buffer
    Inputs: UINT8 input_scan
    Outputs: None
    Function details: the function writes to the
    IKBD buffer 
*/
void write_to_ikbd_buffer(UINT8 input_scan);
/* Function name: ikbd_is_waiting
   Inputs: None
   Outputs: int
   Function details: The function checks whether the
   IKBD buffer is waiting for the key is pressed 
*/
int ikbd_is_waiting();
/* Function name: read_from_ikbd_buffer
   Inputs: None
   Outputs: UINT32
   Function details: The function reads the scancode from
   the IKBD buffer and return it to the caller
*/
UINT32 read_from_ikbd_buffer();
/* Function name: clear_ikbd_buffer
   Inputs: None
   Outputs: None
   Function details: The function clears
   the IKBD buffer to reset the state to normal
*/
void clear_ikbd_buffer();
/* Function name: get_repeated_key
   Inputs: None
   Outputs: UINT8
   Function details: The function returns 
   the repeated key
*/
UINT8 get_repeated_key();
/* Function name: get_input
   Inputs: None
   Outputs: UINT32
   Function details: The function get the 
   scancode of the key being pressed by calling
   the function read_from_ikbd_buffer
*/
UINT32 get_input ();
/* Function name: is_input_entered
   Inputs: None
   Outputs: int
   Function details: The function checks the 
   whether the key is pressed by calling
   the IKBD_is_waiting 
*/
int is_input_entered();
/*  Function name: instal_vectors
    Inputs: None
    Outputs: None
    Function details: The fuction loads
    the vector of VBL and the vector of 
    the IKBD
*/
void install_vectors();
/* Function name: remove_vectors
   Inputs: None
   Outputs: None
   Function details: The function remove
   the control over the VBL vector and 
   clear the IKBD buffer to set 
   the system back to normal state 

*/
void remove_vectors();

Vector install_vector(int num, Vector vector);

#endif