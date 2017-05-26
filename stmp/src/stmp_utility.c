//
// Created by Sidhin Thomas on 23/05/17.
//

#include "stmp_utility.h"

#ifndef LOG_OUTPUT
#define LOG_OUTPUT stdout
#endif

#ifndef DEBUG_LOG_OUTPUT
#define DEBUG_LOG_OUTPUT stdout
#endif

char const FILE_ERROR_MESSAGE[] = "Unable to open the file.\n"
        "Please check the filename and ensure read permission.\n";


int get_all_words(char *const source, char **buffer, int buffer_size){
    int j = 0;

    buffer[0] = (char *) malloc(sizeof(char)*WORD_SIZE);
    if (buffer[0] == NULL){
        perror("stmp utility");
        return -1;
    }
    buffer[0][0] = '\0';

    int k = 0;
    for (int i = 0; source[i] != '\0' ; ++i) {

        if (j > buffer_size){
            fprintf(stderr, "Buffer overflow");
            return -1;
        }

        /* word finished, switching to next placeholder */
        if(source[i] == ' '){
            buffer[j][k] = '\0';
            j++;
            buffer[j] = (char *) malloc(sizeof(char)*WORD_SIZE);
            if (buffer[j] == NULL){
                perror("stmp utility");
                return -1;
            }
            buffer[j][0] = '\0';
            k = 0;
        }
        else {
            buffer[j][k] = source[i];
            k++;
        }
    }
    buffer[j][k]='\0';
    return j+1;
}

void print_string_array(char *const *src, const int size) {
    printf("Number of words: %d\nList of words:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("%d) %s\n",i,src[i]);
    }
}

int get_all_lines(char *const path, char **buffer, const int buffer_size){

    FILE *fp = fopen(path,"r");
    if (fp == NULL){
        perror("stmp utility");
        fprintf(stderr, FILE_ERROR_MESSAGE);
        return -1;
    }

    char *string_buffer = (char *) malloc(sizeof(char)*LINE_SIZE);
    if (string_buffer == NULL){
        perror("stmp utility");
        return -1;
    }

    int buff_index = 0;
    while (fgets(string_buffer,LINE_SIZE,fp)!= NULL){

        //Logging
        fprintf(DEBUG_LOG_OUTPUT,"Retrieving line: %s",string_buffer);
        for (int i = 0; string_buffer[i]!='\0'; ++i) {
            if (string_buffer[i] == '\n'){
                string_buffer[i] = '\0';
            }
        }
        buffer[buff_index] = string_buffer;
        buff_index++;
        if (buff_index >= buffer_size){
            fprintf(stderr,"Buffer overflow");
            return -1;
        }
        string_buffer = (char *) malloc(sizeof(char)*LINE_SIZE);
        if (string_buffer == NULL){
            perror("stmp utility");
            fprintf(stderr, "Unable to allocate memory.");
            return -1;
        }
    }

    return buff_index +1 ;
}
