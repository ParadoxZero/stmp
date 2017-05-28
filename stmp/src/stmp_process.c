/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include <stdbool.h>
#include "stmp_process.h"

#define MAX_PATH_SIZE 255
#define FILE_SUFFIX "_STMP_OUT"
#define LINE_BUFFER_SIZE 3000
#define WORD_BUFFER_SIZE 300


int get_output_name(char *const path, char *output_filename){
    strcpy(output_filename,path);
    size_t path_length = strlen(output_filename);
    char suffix[] = FILE_SUFFIX;
    size_t suffix_length = strlen(suffix);
    if(path_length+suffix_length > MAX_PATH_SIZE){
        fprintf(stderr,"Path is too large to handle.");
        return -1;
    }
    size_t extention_start = 0;
    for (size_t i = path_length-1; output_filename[i]!='/' && i > 0; --i) {
        if(output_filename[i]=='.'){
            extention_start = i;
            break;
        }
    }

    if(extention_start!=0){
        char ext[100];
        int j = 0;
        for (size_t i = extention_start; i < path_length ; ++i) {
            ext[j++] = output_filename[i];
            output_filename[i] = '\0';
        }
        ext[j] = '\0';
        strcat(output_filename,suffix);
        strcat(output_filename,ext);
    }
    else{
        strcat(output_filename,suffix);
    }
    return 0;
}

/*
 * Description: frees an array of string pointers
 *
 * Parameter:
 *  size-> size of the array i.e length of array containing pointers
 */
void free_string_array(char **string, const int size){
    for (int i = 0; i < size; ++i) {
        free(string[i]);
        string[i] = NULL;
    }
}

int process_source(char *const path){
    char output_filename[MAX_PATH_SIZE];
    if(get_output_name(path,output_filename)==-1){
        return -1;
    }

    char *lines_buffer[LINE_BUFFER_SIZE] = {NULL};
    int line_count = get_all_lines(path,lines_buffer,LINE_BUFFER_SIZE);
    if (line_count == -1){
        fprintf(stderr,"Unable to retrieve source.\n");
        return -1;
    }

    FILE *output = fopen(output_filename,"w");
    if (output == NULL){
        perror("stmp");
        return -1;
    }

    struct stmp_MACROTABLE macrotable[255];
    int M_count = 0;
    struct stmp_arg_table arg_table[255];
    int arg_count = 0;
    int success = 1;
    char *word_buffer[WORD_BUFFER_SIZE] = {NULL};

    for (int i = 0; i < line_count; ++i) {
        int word_count = get_all_words(lines_buffer[i],word_buffer,WORD_BUFFER_SIZE);
        if( word_count == -1){
            return -1;
        }

        if (strcmp(word_buffer[2],MACRO)) {
            success = parse_macro_definitions(lines_buffer, &i, line_count, macrotable, &M_count, 255);
        }
        else {
            int macro_called = 0;
            for (int j = 0; j < word_count; ++j) {
                int m_index;
                if ((m_index=check_macro_called(macrotable,M_count,word_buffer[j]))!=-1){
                    j++;
                    for (int k = 0; k < macrotable[m_index].arg_count; ++k) {
                        strcpy(arg_table[k].arg,macrotable[m_index].arg_list[k]);
                        strcpy(arg_table[k].value,word_buffer[j]);
                        j++;
                    }
                    success = expand_macro(macrotable[m_index],arg_table,output);
                }
                else{
                    fprintf(output,"%s",word_buffer[j]);
                }
            }
            fprintf(output,"\n");
        }

        free_string_array(word_buffer,WORD_BUFFER_SIZE);
    }

    if (!success){
        fclose(output);
        if(remove(output_filename)==-1){
            perror("Unable to delete temporary file.");
        }
        return -1;
    }

    return 0;
}

int check_macro_called(struct stmp_MACROTABLE pMACROTABLE[255], int count, char *string) {
    for (int i = 0; i < count ; ++i) {
        if(strcmp(pMACROTABLE[i].name,string)){
            return i;
        }
    }
    return -1;
}

int parse_macro_definitions(char *source_lines[3000], int *index, int max_lines, struct stmp_MACROTABLE table[255],
                            int *table_size, int max_table_size) {
    char *word_buffer[300];
    int line_no = *index;
    int tab_size = *table_size;

    int word_count = get_all_words(source_lines[line_no],word_buffer,300);
    if (word_count > 2) {
        strcpy(table[*table_size].name, word_buffer[0]);
        table[tab_size].arg_count = word_count - 2;
        table[tab_size].arg_list = (char **) malloc(sizeof(char) * table[tab_size].arg_count);
        for (int i = 2; i < word_count; ++i) {
            table[tab_size].arg_list[i - 2] = (char *) malloc(sizeof(char) * WORD_SIZE);
            strcpy(table[*table_size].arg_list[i - 2], word_buffer[i]);
        }
    }
    else {
        free_string_array(word_buffer,300);
        fprintf(stderr, "Error reading macro at line %d.", line_no);
        return -1;
    }
    free_string_array(word_buffer,300);
    line_no++;

    char definition_buffer[3000][300];
    int cont_loop = 1, defintion_line_count=0;
    while(line_no < max_lines){
        word_count = get_all_words(source_lines[line_no],word_buffer,300);
        for (int i=0; i < word_count; ++i){
            if(strcmp(word_buffer[i],MACRO_END)){
                cont_loop = 0;
                break;
            }
        }
        if (cont_loop == 0){
            table[tab_size].definition = (char**) malloc(sizeof(char*)*defintion_line_count);
            for (int i = 0; i < defintion_line_count; ++i) {
                strcpy(table[tab_size].definition[i],definition_buffer[i]);
            }
            tab_size++;
            *index = line_no;
            *table_size = tab_size;
            return 1;
        }
        strcpy(definition_buffer[defintion_line_count],source_lines[line_no]);
        line_no++;
        defintion_line_count++;
    }

    *index = line_no;
    *table_size = tab_size;
    return 0;
}

