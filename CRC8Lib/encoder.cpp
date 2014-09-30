/*
 * encoder.cpp
 *
 *  Created on: May 7, 2012
 *      Author: cj cdesch@gmail.com @cjdesch
 */

#include "encoder.h"


/**
 * CRC8 - Create CRC8 Checksum for passed array
 */
//dataframe[]  is an array of characters starting at 0
//[0][1][2][3][4][5][6]  <-- Index
// :  0  0  0  1  3   4  <-- Value
short crcTest(char dataframe[]){



    char j;
    short crc8 = 0;	 //Short is a smaller Integer number. Starts at 0
    char x = 0;

    //i will loop from 0 to 12 and will increment by 1 each iteration of the loop
    for (int i = 0; i < 13; i++){
        x = dataframe[i];	//Take the character at index i and store it in X for this iteration of the loop// Overwrite this value when the next iteration comes.

        //k will loop from 0 to 7 and will increment by 1 each iteration of the loop
        for (int k = 0; k < 8; k++){

            j = 1 & (x ^ crc8); //& and ^ or logical operators
            crc8 = floor0(crc8 / 2) & 0xFF;		//Divide CRC8 calc by 2 and take the FLOOR of that number (round down), then do Logical & using Hex value
            x = floor0(x / 2) & 0xFF;			// Do the same with X
            if (j != 0 ){						// if J is not equal 0 ,
                crc8 = crc8 ^ 0x8C;				//find the CRC8
            }
        }
    }

    //Return the final CRC 8 (3 digit number)
    return crc8;

}


/**
 * Floor - Closest whole number from   0
 */
int floor0( float value )
{
    if (value < 0.0)
        return (int)ceil( value );
    else
        return (int)floor( value );
}

/**
 * Convert unsinged int into string with leading 0's
 */
void uint_to_str_leading( char* dst, unsigned int i, size_t size )
{
    char* pCurChar;

    if (size == 0) return;

    pCurChar = dst + size;  // we'll be working the buffer backwards

    *--pCurChar = '\0';   // take this out if you don't want an ASCIIZ output
                          //   but think hard before doing that...

    while (pCurChar != dst) {
        int digit = i % 10;
        i = i /10;

        *--pCurChar = '0' + digit;
    }

    return;
}

/**
 * Convert signed int into string with leading 0's
 */
void int_to_str_leading( char* dst, int i, size_t size )
{
    if (size && (i < 0)) {
        *dst++ = '-';
        size -= 1;

        i *= -1;
    }

    uint_to_str_leading( dst, i, size);

    return;
}
