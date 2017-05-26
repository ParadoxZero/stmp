/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "stmp_process.h"

#define MAX_PATH_SIZE 255
#define FILE_SUFFIX "_STMP_OUT"

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

int process_source(char *const path){
    char output_filename[MAX_PATH_SIZE];
    if(get_output_name(path,output_filename)==-1){
        return -1;
    }

    FILE *fp = fopen(path,"r");
    if (fp == NULL){
        perror("stmp");
        return -1;
    }

    FILE *output = fopen(output_filename,"w");
    if (output == NULL){
        perror("stmp");
        return -1;
    }



    return 0;
}