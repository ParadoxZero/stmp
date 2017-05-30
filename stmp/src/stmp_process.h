/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
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

int parse_macro_definitions(char source_lines[][LINE_SIZE], int *index, int max_lines, struct stmp_MACROTABLE count[],
                            int *table_size, int max_table_size);

int expand_macro(struct stmp_MACROTABLE macro_details, struct stmp_arg_table *const arguements, FILE * outputfile);

/*
 * Description: Takes the path as input and adds a suffix to it.
 */
int get_output_name(char *const path, char *output_filename);

int check_table_macro_name(struct stmp_MACROTABLE pMACROTABLE[255], int count, char *string);


#endif //MACRO_PROSSESOR_STMP_PROCESS_H
