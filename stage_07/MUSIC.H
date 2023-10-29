/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: music.
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"

#define SONG_LENGTH 24
#define C4_NOTE 262
#define D4_NOTE 294
#define E4_NOTE 330
#define F4_NOTE 349
#define G4_NOTE 392
#define A4_NOTE 440
#define B4_NOTE 494
#define B_FLAT_NOTE 466
#define C5_NOTE 523
#define D5_NOTE 587
#define E5_NOTE 659
#define SONG_VOL 10


/* struct that holds the pitch_tone
and the duration of the note
*/
typedef struct {
    int pitch_tone;
    int duration;
} Note;

/*  Function name: start_music()
    Inputs: None
    Outputs: None
    Function details: The function
    loads the first note in the song
    sheet
*/
void start_music();

/*  Function name: start_music()
    Inputs: None
    Outputs: None
    Function details: The function
    loads the first note in the song
    sheet
*/
void update_music(UINT32 time_elapsed);
#endif
