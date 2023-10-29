/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: psg.h
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "TYPES.H"

#define ON 1
#define OFF 0
#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2
#define ENABLE_BOTH_CHANNEL 3
#define VOLUME_A 8
#define VOLUME_B 9
#define VOLUME_C 10
#define NOISE_FREQUENCY_REG 6
#define MIXER_FREQUENCY_REG 7


#define FINE_FREQ_ENVELOPE_REG 0xB
#define COARSE_FREQ_ENVELOPE_REG 0xC
#define ENVELOPE_SHAPE_REG 0xD

#define REVERSE_EXPONENTIAL_SHAPE 0x7F
#define FLAT_SHAPE 0x00
extern volatile char *PSG_reg_select = 0xFF8800;
extern volatile char *PSG_reg_write = 0xFF8802;

/*  Function name: write_psg
    Inputs: int reg
            UINT8 val
    Output: None
    Function details:
Writes the given byte value (0-255) to the given PSG register (0-15)
Channel 0 = A
        1 = B
        2 = C
*/
void write_psg(int reg, UINT8 val);

/*  Function name: read_psg
    Inputs: int reg
    Output: UINT8 
    Function details: The function writes 
    the value to the specified register
    inside the PSG
*/
UINT8 read_psg(int reg);

/*  Function name: set_tone
    Inputs: int channel
            int tuning
    Outputs: None
    Function details: The function writes the 
    the value for the fine tone of the specified
    channel inside the PSG
*/
void set_tone(int channel, int tuning);
/*  Function name: set_volume
    Inputs: int channel 
            int volume 
    Outputs: int channel
             int volume 
    Function details: The function set the volume 
    of the specified channel in the PSG
*/
void set_volume(int channel, int volume);
/* Function name: stop_sound()
   Inputs: None
   Outputs: None
   Function details: The function 
   turn off the channel B used for 
   the music 
*/
void stop_sound();
/* Function name: set_noise
   Inputs: int tuning
   Outputs: None 
   Function details: The function 
   writes the value to the coarse tune
   register in the PSG
*/
void set_noise(int tuning);
/*  Function name: enable_channel
    Inputs: int channel
            int tone_on
            int noise_on
    Outputs: None
    Function details:
Used for enabling channels without changing other
values

and = 1
or = 0

*/
void enable_channel(int channel, int tone_on, int noise_on);

/*  Function name: set_envelope 
    Inputs: int shape
            int sustain
    Function details: The function set the envelope 
    with the sustain in the PSG
*/
void set_envelope(int shape, int sustain);

#endif