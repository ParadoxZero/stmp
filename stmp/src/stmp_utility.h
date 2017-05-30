/*
 *
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#ifndef MACRO_PROSSESOR_UTILITY_H
#define MACRO_PROSSESOR_UTILITY_H

#define WORD_SIZE 150
#define LINE_SIZE 500
#define MAX_PRINT_SIZE 3000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int get_all_words(char *const source, char buffer[][WORD_SIZE], const int buffer_size);

/*
 *  Description: Reads from the file pointed by path and fills the
 *  lines into buffer.
 *
 *  Parameters:
 *      path -> file to be read
 *      buffer -> char * array to store the lines
 *      buffer_size -> length of buffer
 */
int get_all_lines(char *const path, char buffer[][LINE_SIZE], const int buffer_size);

/*
 * Description: prints to std output the contents of string buffer.
 *
 * Parameters:
 *      src - array of string
 *      count - size of array
 */
void print_string_array(void *lines, const int size, const int line_size);

/*
 * Description: Checks if the string str starts with the string pre
 */
int startsWith(const char *str, const char *pre);


#endif //MACRO_PROSSESOR_UTILITY_H
