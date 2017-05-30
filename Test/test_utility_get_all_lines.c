/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include <string.h>

#include "../stmp/src/stmp_utility.h"

int main(){
    char source[5][20] = {"Hello world good",
                          "Like My demons",
                          "",
                          "",
                          "I am cool" };
    FILE *fp = fopen("testfile.dat","w");
    if(fp == NULL)
        return -1;
    for(int i=0; i < 5 ; ++i){
        fputs(&source[i],fp);
        fprintf(fp,"\n");
    }

    if(fclose(fp) != 0)
        return -1;

    char buffer[10][LINE_SIZE];
    int ret = get_all_lines("testfile.dat",buffer,10);
    if (ret == -1)
        return -1;

    printf("Number of lines: %d", ret);
    if (ret != 3){
        //return -1;
    }

    for (int i = 0; i < 5 ; ++i) {
        printf("\nOriginal: %s", source[i]);
        printf("\nRetrieved: %s", buffer[i]);
        if(strcmp(source[i],buffer[i]) != 0)
            return -1;
    }
    return 0;

}