/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "../stmp/src/stmp_utility.h"

int main(){
    char source[] = "Hello world good\0" ;
    char *buff[250];
    int count = get_all_words(source,buff,250);
    if (count != 3)
        return -1;
    print_string_array(buff, count);
    for (int i = 0; i < count; ++i) {
        int j;
        for (j = 0; buff[i][j]!='\0'; ++j);
        if (j < 1)
            return -1;
    }
    return 0;
}