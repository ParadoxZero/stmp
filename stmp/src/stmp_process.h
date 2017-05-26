/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#ifndef MACRO_PROSSESOR_STMP_PROCESS_H
#define MACRO_PROSSESOR_STMP_PROCESS_H

#include <stdio.h>
#include <string.h>

struct smtp_MACROTABLE{
    char* name;
    char **definition;
    char **arg_list;
};

struct stmp_arg_table {
    char *arg;
    char *value;
};

/*
 * Description: Process the MACROs defined
 * in the file pointed by path
 */
int process_source(char *const path);

int parse_macro_definitions(char *const *const source_lines);

int expand_macro(char *const name, struct arg_table *const arguements, char *buffer, int buffer_size);

int get_output_name(char *const path, char *output_filename);

#endif //MACRO_PROSSESOR_STMP_PROCESS_H
