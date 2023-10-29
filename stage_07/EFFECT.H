/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: effect.h
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#ifndef EFFECT_H
#define EFFECT_H

#include "psg.h"

#define EFFECT_VOL 50

/* Function name: collision_sound()
   Inputs: None
   Outputs: None
   Function details: The function generates
   the collision sound when the bird collides
   with either the ground or pipes
*/
void collision_sound();
/* Function name: collision_sound()
   Inputs: None
   Outputs: None
   Function details: The function generates
   the flap sounds when the bird flaps up
*/
void flaps_sound ();

#endif