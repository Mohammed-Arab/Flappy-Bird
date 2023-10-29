/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: effect.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#include "effect.h"

/* Function name: collision_sound()
   Inputs: None
   Outputs: None
   Function details: The function generates
   the collision sound when the bird collides
   with either the ground or pipes
*/
void collision_sound()
{
  int vol = 16;
    
    set_noise(10);
    enable_channel(ENABLE_BOTH_CHANNEL, 0,1);
    set_volume(CHANNEL_A, vol);
    set_envelope(0x00,5); 
}

/* Function name: collision_sound()
   Inputs: None
   Outputs: None
   Function details: The function generates
   the flap sounds when the bird flaps up
*/
void flaps_sound ()
{
  int vol = 16;
    set_noise(20);
    enable_channel(ENABLE_BOTH_CHANNEL, 0,1);
    set_volume(CHANNEL_A, vol);
    set_envelope(0x7f,5); 
}