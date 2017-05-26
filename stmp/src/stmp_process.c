/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

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

int free_string_array(char **string, const int size){
    for (int i = 0; i < size; ++i) {
        free(string[i]);
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

    char *word_buffer[WORD_BUFFER_SIZE] = {NULL};
    for (int i = 0; i < line_count; ++i) {
        int word_count = get_all_words(lines_buffer[i],word_buffer,WORD_BUFFER_SIZE);
        if( word_count == -1){
            return -1;
        }

        for (int j = 0; j < word_count ; ++j) {
            switch (lines_buffer[i][0])
            if (strcmp(word_buffer[i],"MACRO")){

            }
        }

        free_string_array(word_buffer,WORD_BUFFER_SIZE);
    }



    return 0;
}