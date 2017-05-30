/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "../stmp/src/stmp_utility.h"

int main(){
    int num = 4;
    int ret = 0;
    char source[4][100] = {"    Hello    world    good     !" ,
                           "lol i good * # Hello world     p ",
                           "  Hel, wr k   lk    ",
                           "   #ho lo"};
    int wc [4] = {4,4,5,0};
    for (int k = 0; k < num ; ++k) {
        char buff[250][WORD_SIZE];
        int count = get_all_words(source[k],buff,250);
        print_string_array(buff, count, WORD_SIZE);
        if (count != wc[k]) {
            ret = -1;
        }
        for (int i = 0; i < count; ++i) {
            int j;
            for (j = 0; buff[i][j]!='\0'; ++j);
            if (j < 1)
                if(buff[i][j] == ' ')
                    ret = -1;
        }
    }
    return ret;
}