/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: isr.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 9b
    Recent Update: April 4thth, 2023
*/
#include"isr.h"

Vector vbl_vector;
Vector ikbd_vector;

volatile UINT8* const ikbd_control = 0xfffc00;
volatile UINT8* const ikbd_status = 0xfffc00;
volatile UINT8* const ikbd_reader = 0xfffc02;
volatile UINT8* const ascii = 0xFFFE829C;
volatile UINT8* const isr_Mfp_Register = 0xfffa11;


UINT8 ikbd_buffer[256];
UINT16 buff_head = 0;
UINT16 buff_tail = 0;
UINT8 repeated_key ;
UINT8 key_repeat ; /*false = 0, true = 1*/

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
    the vector of VBL and the vector of 
    the IKBD
*/
void install_vectors() {
  vbl_vector = install_vector(VBL_ISR, vbl_isr);
  ikbd_vector = install_vector(IKBD_ISR, ikbd_isr);
}
/* Function name: remove_vectors
   Inputs: None
   Outputs: None
   Function details: The function remove
   the control over the VBL vector and 
   clear the IKBD buffer to set 
   the system back to normal state 

*/
void remove_vectors() {
  install_vector(VBL_ISR, vbl_vector);
  install_vector(IKBD_ISR, ikbd_vector);
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
/*  Function name: ikbd_irq
    Inputs: None
    Outputs: None
    Function details: The function sends the 
    IKBD request to interrup the IKBD to control
    the keyboard 
*/
void ikbd_irq() {
  UINT8 input_scan;

  *ikbd_control = 0x16;
  /* check if data was recieved */
  if (*ikbd_status & 0x1) {
     input_scan = *ikbd_reader;
    if ((input_scan & 0x80) == 0x00) 
    { /* check if it's a make code */
        write_to_ikbd_buffer(input_scan); 
        key_repeat = 1;/* key_repeat = true*/
      } 
      else if ((input_scan & 0x80) == 0x80) 
      { /* check if it's a break code */
        key_repeat = 0;/* key_repeat = false*/
      }
    *isr_Mfp_Register &= MFB_BIT_6_MASK_OFF;  
  }
       *ikbd_control = 0x96;
}
/*  Function name: write_to_ikbd_buffer
    Inputs: UINT8 input_scan
    Outputs: None
    Function details: the function writes to the
    IKBD buffer 
*/
void write_to_ikbd_buffer(UINT8 input_scan)
{
  if (buff_tail == 255)
  {
    buff_tail = 0;
  }
    

  ikbd_buffer[buff_tail] =input_scan ;
  buff_tail++;
}
/* Function name: ikbd_is_waiting
   Inputs: None
   Outputs: int
   Function details: The function checks whether the
   IKBD buffer is waiting for the key is pressed 
*/
int ikbd_is_waiting() {
  return buff_head != buff_tail; /* 0 = false if they are equal and 1 = true if they not euqal*/
}
/* Function name: read_from_ikbd_buffer
   Inputs: None
   Outputs: UINT32
   Function details: The function reads the scancode from
   the IKBD buffer and return it to the caller
*/
UINT32 read_from_ikbd_buffer() {
  UINT32 key;
  long old_ssp = Super(0); 

  if (buff_head == 255)
    buff_head = 0;

  *isr_Mfp_Register &= MFB_BIT_6_MASK_OFF;  

  key = ikbd_buffer[buff_head];
  key = key << 16;
  key = key + *(ascii + ikbd_buffer[buff_head++]);

  *isr_Mfp_Register |= MFB_BIT_6_MASK_ON;

  Super(old_ssp);
  return key;
}
/* Function name: clear_ikbd_buffer
   Inputs: None
   Outputs: None
   Function details: The function clears
   the IKBD buffer to reset the state to normal
*/
void clear_ikbd_buffer() {
  while(ikbd_is_waiting()) {
    buff_head++;
  }
  ikbd_buffer[buff_tail] = 0x00;
}
/* Function name: get_repeated_key
   Inputs: None
   Outputs: UINT8
   Function details: The function returns 
   the repeated key
*/
UINT8 get_repeated_key() {
  return repeated_key;
}
/* Function name: is_input_entered
   Inputs: None
   Outputs: int
   Function details: The function checks the 
   whether the key is pressed by calling
   the IKBD_is_waiting 
*/
int is_input_entered()
{
	return ikbd_is_waiting();
}
/* Function name: get_input
   Inputs: None
   Outputs: UINT32
   Function details: The function get the 
   scancode of the key being pressed by calling
   the function read_from_ikbd_buffer
*/
UINT32 get_input ()
{
	return read_from_ikbd_buffer();
}