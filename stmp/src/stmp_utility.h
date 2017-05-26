/*
 * Copyright (c) 2017 Sidhin S Thomas. All rights reserved.
 */

#ifndef MACRO_PROSSESOR_UTILITY_H
#define MACRO_PROSSESOR_UTILITY_H

#define WORD_SIZE 150
#define LINE_SIZE 500

#include <stdio.h>
#include <stdlib.h>

/*
 *  Description: Function will take a character array as input
 *  Produces a 2 dimensional array of words retrieved from it.
 *
 *  Parameters:
 *      Source - input string
 *      buffer - a char* array
 *      buffer_size - size of the char * array
 *
 *  Return value:
 *      number of words
 *      if -1 then it means error occurred
 *
 */
int get_all_words(char *const source, char **buffer, const int buffer_size);

/*
 *  Description: Reads from the file pointed by path and fills the
 *  lines into buffer.
 *
 *  Parameters:
 *      path -> file to be read
 *      buffer -> char * array to store the lines
 *      buffer_size -> length of buffer
 */
int get_all_lines(char *const path, char **buffer, const int buffer_size);

/*
 * Description: prints to std output the contents of string buffer.
 *
 * Parameters:
 *      src - array of string
 *      count - size of array
 */
void print_string_array(char *const *src, const int size);

/* Constants used */


#endif //MACRO_PROSSESOR_UTILITY_H
