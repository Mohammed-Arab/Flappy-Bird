/*	Group Student Name: Khanh Le, Mohammed Arab
	Student Email: kle6951@mtroyal.ca, marab@mtroyal.ca
	File Name: font.h
	Instructor: Paul Pospisil
	Assignment: Flappy Bird - Stage 2
	Recent Update: March 17th, 2023
*/
/* The library provides 8x8 bitmap for all
the characters and 16x16 bitmap for the letters
'S','C','O','R','E', and for numbers between
0 - 9.
*/
#ifndef FONT_H
#define FONT_H

#include "types.h"

extern const UINT8 font[]; /* 8x8 system font */

#define FONT_HEIGHT 8
#define CHAR_BEL 7
#define CHAR_TAB 9
#define CHAR_LF 10
#define CHAR_VT 11
#define CHAR_FF 12
#define CHAR_CR 13
#define CHAR_DEL 127

/*keys for menu*/
#define UP_KEY 0x00480000
#define DOWN_KEY 0x00500000
#define ENTER_KEY 0x001C000D
#define ESC_KEY 0x0001001B
/**/

#define IS_PRINTABLE(i) ((i) >= ' ' && (i) <= '~')
#define GLYPH_START(i) (font + (((i) - ' ') << 3))
#define BITMAP_SZ 16

extern const unsigned int zero[BITMAP_SZ]; /* BITMAP_SZxBITMAP_SZ system font */
extern const unsigned int one[BITMAP_SZ];
extern const unsigned int two[BITMAP_SZ];
extern const unsigned int three[BITMAP_SZ];
extern const unsigned int four[BITMAP_SZ];
extern const unsigned int five[BITMAP_SZ];
extern const unsigned int six[BITMAP_SZ];
extern const unsigned int seven[BITMAP_SZ];
extern const unsigned int eight[BITMAP_SZ];
extern const unsigned int nine[BITMAP_SZ];
extern const unsigned int letter_S[BITMAP_SZ];
extern const unsigned int letter_C[BITMAP_SZ];
extern const unsigned int letter_O[BITMAP_SZ];
extern const unsigned int letter_R[BITMAP_SZ];
extern const unsigned int letter_E[BITMAP_SZ];
extern const unsigned int colons[BITMAP_SZ];

#endif
