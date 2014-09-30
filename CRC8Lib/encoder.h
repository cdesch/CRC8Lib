/*
 * encoder.h
 *
 *  Created on: May 7, 2012
 *      Author: cj cdesch@gmail.com @cjdesch
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <string.h>
#include <math.h>

short crcTest(char dataframe[]);
int floor0( float value );
void uint_to_str_leading( char* dst, unsigned int i, size_t size );
void int_to_str_leading( char* dst, int i, size_t size );



#endif /* ENCODER_H_ */
