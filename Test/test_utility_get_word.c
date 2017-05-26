/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "../stmp/src/stmp_utility.h"

int main(){
    char source[3][100] = {"    Hello    world    good     !" ,
                           "# Hello world     p ",
                           "Hel wr k   lk    "};
    for (int k = 0; k < 3 ; ++k) {
        char *buff[250];
        int count = get_all_words(source[k],buff,250);
        print_string_array(buff, count);
        if (count != 4) {
            return -1;
        }
        for (int i = 0; i < count; ++i) {
            int j;
            for (j = 0; buff[i][j]!='\0'; ++j);
            if (j < 1)
                return -1;
        }
    }
    return 0;
}