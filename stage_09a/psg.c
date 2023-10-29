/*	Group Student Name: Khanh Le, Mohammed Arab
    Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
    File Name: psg.
    Instructor: Paul Pospisil
    Assignment: Flappy Bird - Stage 7
    Previous Update: March 17th, 2023
    Recent Update: April 5th, 2023
*/
#include "psg.h"

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
void write_psg(int reg, UINT8 val)
{
    long old_ssp;
    if ((0 <= reg && reg <= 15) && (0 <= val && val <= 255))
    {
        old_ssp = Super(0);
        *PSG_reg_select = reg;
        *PSG_reg_write = val;
        Super(old_ssp);
    }
}
/*  Function name: read_psg
    Inputs: int reg
    Output: UINT8 
    Function details: The function writes 
    the value to the specified register
    inside the PSG
*/

UINT8 read_psg(int reg)
{

    UINT8 value;
    long old_ssp;
    if (0 <= reg && reg <= 15)
    {
        old_ssp = Super(0);
        *PSG_reg_select = reg;
        value = *PSG_reg_select;
        Super(old_ssp);
    }
    return value;
}
/*  Function name: set_tone
    Inputs: int channel
            int tuning
    Outputs: None
    Function details: The function writes the 
    the value for the fine tone of the specified
    channel inside the PSG
*/
void set_tone(int channel, int tuning)
{
    if (channel == CHANNEL_A || channel == CHANNEL_B || channel == CHANNEL_C)
    {
        if (channel == CHANNEL_A)
        {
            write_psg(0, tuning);
        }
        else if (channel == CHANNEL_B)
        {
            write_psg(2, tuning);
        }
        else
        {
            write_psg(4, tuning);
        }
    }
    return;
}

/*  Function name: set_volume
    Inputs: int channel 
            int volume 
    Outputs: int channel
             int volume 
    Function details: The function set the volume 
    of the specified channel in the PSG
*/
void set_volume(int channel, int volume)
{
    if (channel == CHANNEL_A || channel == CHANNEL_B || channel == CHANNEL_C)
    {
        if (channel == CHANNEL_A)
        {
            write_psg(VOLUME_A, volume);
        }
        else if (channel == CHANNEL_B)
        {
            write_psg(VOLUME_B, volume);
        }
        else
        {
            write_psg(VOLUME_C, volume);
        }
    }
    return;
}

/* Function name: stop_sound()
   Inputs: None
   Outputs: None
   Function details: The function 
   turn off the channel B used for 
   the music 
*/
void stop_sound()
{
    set_volume(CHANNEL_B, OFF);
}
/* Function name: set_noise
   Inputs: int tuning
   Outputs: None 
   Function details: The function 
   writes the value to the coarse tune
   register in the PSG
*/
void set_noise(int tuning)
{
    write_psg(NOISE_FREQUENCY_REG, tuning);
}

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

void enable_channel(int channel, int tone_on, int noise_on){
    
    int enable_val;
    if(channel == CHANNEL_A){
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3E;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x37;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3E & 0x37);
            }
    }
        else if (channel == CHANNEL_B){
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3D;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x2F;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3D & 0x2F);
            }
            }
        else if (channel == CHANNEL_C){
            if(tone_on == 1 && noise_on == 0){
                    enable_val = 0x3B;
            }
            else if(tone_on == 0 && noise_on == 1){
                    enable_val = 0x1F;
            }
            else if(tone_on == 1 && noise_on == 1){
                    enable_val = (0x3B & 0x1F);
            }
           }
        else if (channel == ENABLE_BOTH_CHANNEL){
            if(tone_on == 0 && noise_on == 1){
                enable_val = (0x35);
            }
           }
 
    write_psg(0x7, enable_val);
}

/*  Function name: set_envelope 
    Inputs: int shape
            int sustain
    Function details: The function set the envelope 
    with the sustain in the PSG
*/
void set_envelope (int shape, int sustain)
{
    write_psg(FINE_FREQ_ENVELOPE_REG, sustain);
    write_psg(COARSE_FREQ_ENVELOPE_REG, sustain);
    write_psg(ENVELOPE_SHAPE_REG, shape);
}
