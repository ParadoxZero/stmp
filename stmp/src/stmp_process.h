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


#ifndef MACRO_PROSSESOR_STMP_PROCESS_H
#define MACRO_PROSSESOR_STMP_PROCESS_H

#include <stdio.h>
#include <string.h>

#include "stmp_utility.h"
#include "MACRO_DEF_LANGUAGE.h"

#define MAX_PATH_SIZE 255
#define FILE_SUFFIX "_STMP_OUT"
#define LINE_BUFFER_SIZE 3000
#define WORD_BUFFER_SIZE 300
#define MAX_DEF_SIZE 500
#define MAX_ARG_SIZE 50

struct stmp_MACROTABLE{
    char* name;
    char definition[MAX_DEF_SIZE][LINE_SIZE];
    char arg_list[MAX_ARG_SIZE][WORD_SIZE];
    int arg_count;
    int def_count;
};

struct stmp_arg_table {
    char arg[WORD_SIZE];
    char value[WORD_SIZE];
};

/*
 * Description: Process the MACROs defined
 * in the file pointed by path
 */
int process_source(char *const path);

/*
 * Decription: This is the function that will fill out the macro details. It will strore them in
 * the array 'table'.
 * Parameters:
 *      source_lines: the array of string which represents the source code.
 *      index: pointer to index variable used. It points to the currently being
 *          processed line. It's a pointer so index chhange will be reflected in calling
 *          function
 *      table: array of stmp_MACROTABLE. This contains the details of all MACROs found so far.
 *      table_size: current size of the table i.e the smallest free index. It's is a pointer so that
 *          the change will be reflected in calling function.
 *      max_table_size: the upper limit of table_size i.e the size of array 'table'
 */
int parse_macro_definitions(char source_lines[][LINE_SIZE], int *index, int max_lines, struct stmp_MACROTABLE table[],
                            int *table_size, int max_table_size);
/*
 *  Description: This function expands the MACRO call to full definition by referencing the arguements.
 *
 *  Parameters:
 *      macro_details: The structure containing details of macro to be filled.
 *      arguements: array of stmp_arg_table, contains the arguement for macro
 *      outputfile: the file pointer where the MACRO should be expanded.
 */
int expand_macro(struct stmp_MACROTABLE macro_details, struct stmp_arg_table *const arguements, FILE * outputfile);

/*
 * Description: Takes the path as input and adds a suffix to it.
 */
int get_output_name(char *const path, char *output_filename);

/*
 * Description: checks if a macro name is present in the string
 *
 * Parameters:
 *      table: the array containing details of all MACROs
 *      count: size of array
 *      string: the string which needs to be checked.
 */
int check_table_macro_name(struct stmp_MACROTABLE table[255], int count, char *string);


#endif //MACRO_PROSSESOR_STMP_PROCESS_H
