/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: music.c
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#include "MUSIC.H"

/* array of Note for the music*/
const Note song_sheet[SONG_LENGTH] = {
    {C4_NOTE, 2}, {D4_NOTE, 1},
    {E4_NOTE, 5},{D4_NOTE, 1},
    {E4_NOTE, 1},{F4_NOTE, 2},
    {G4_NOTE, 2},{E4_NOTE, 5},
    {G4_NOTE, 2},{A4_NOTE, 5},
    {G4_NOTE, 2},{A4_NOTE, 1},
    {B_FLAT_NOTE, 1},{B4_NOTE, 2},
    {C5_NOTE, 2},{B_FLAT_NOTE, 1},
    {B4_NOTE, 1},{C5_NOTE, 1},
    {D5_NOTE, 2},{C5_NOTE, 1},
    {D5_NOTE, 1},{E5_NOTE, 2},
    {D5_NOTE, 1},{E5_NOTE, 1}
};


static int current_note = 1;
/*The current note to identify 
which note is at*/

/*  Function name: start_music()
    Inputs: None
    Outputs: None
    Function details: The function
    loads the first note in the song
    sheet
*/
void start_music()
{
    int vol = 5;

    enable_channel(CHANNEL_B,1,0); 
   
    
    set_volume(CHANNEL_B, vol);
}

/* Function name: update_music
   Inputs: timeElapse
   Output: int
   Function details: the function updates the current note
   in the song sheet along with the clock tick
*/
int update_music(UINT32 timeElapsed)
{
    static UINT32 last_time = 0;
    timeElapsed += song_sheet[current_note].duration;

  
    if (timeElapsed >=  song_sheet[current_note].duration) {
        current_note++;
        if (current_note >= SONG_LENGTH) {
             current_note = 0;
        }
        set_tone(CHANNEL_B, song_sheet[current_note].pitch_tone);
        return 1;
    }
    return 0;
}


