/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "../stmp/src/stmp_process.h"

int main(){
    char path[] = "Hi.txt";
    char out[255] ;
    get_output_name(path,out);
    printf("Path: %s\nOutput: %s\n",path,out);
    if(strcmp(out,"Hi_STMP_OUT.txt")!=0){
        return -1;
    }
    printf("--------------\n");
    char path2[] = "test/Hi.txt";
    get_output_name(path2,out);
    printf("Path: %s\nOutput: %s\n",path,out);
    if(strcmp(out,"test/Hi_STMP_OUT.txt")!=0){
        return -1;
    }
    printf("--------------\n");
    char path3[] = "lol-funny";
    get_output_name(path3,out);
    printf("Path: %s\nOutput: %s\n",path,out);
    if(strcmp(out,"lol-funny_STMP_OUT")!=0){
        return -1;
    }

}
