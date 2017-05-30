/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

/*
 * Copyright (C) 2017 Sidhin S Thomas. All rights reserved.
 */

#include "../stmp/src/stmp_process.h"

int main(){
    FILE *fp = fopen("testfile.asm","w");
    fprintf(fp,"test MACRO one two three\n"
            "Move one\n"
            "add two\n"
            "sub three\n"
            "MEND\n"
            "Mov 99, a\n"
            "END\n"
            "nm MACRO lol\n"
            "lol MACRO loa\n"
            "MEND");
    fclose(fp);

    char lines_buffer[LINE_BUFFER_SIZE][LINE_SIZE];
    int line_count = get_all_lines("testfile.asm",lines_buffer,LINE_BUFFER_SIZE);
    if (line_count == -1){
        fprintf(stderr,"Unable to retrieve source.\n");
        return -1;
    }

    struct stmp_MACROTABLE macrotable[10];
    int M_count = 0;
    int success = 1;
    char word_buffer[WORD_BUFFER_SIZE][WORD_SIZE];

    for (int i = 0; i < line_count; ++i) {
        printf("Processing line %d: %s\n", i, lines_buffer[i]);
        fflush(stdout);
        int word_count = get_all_words(lines_buffer[i],word_buffer,WORD_BUFFER_SIZE);
        if( word_count == -1){
            return -1;
        }

        if (strcmp(word_buffer[1],MACRO)==0) {
            success = parse_macro_definitions(lines_buffer, &i, line_count, macrotable, &M_count, 10);
            if(success == -1){
                fprintf(stderr,"Error parsing.\n");
                return 1;
            }
            else {
                for (int j = 0; j < M_count; ++j) {
                    printf("\nName: %s, arg count: %d\nDefinition:\n", macrotable[j].name, macrotable[j].arg_count);
                    for (int k = 0; k < macrotable[j].def_count; ++k) {
                        printf("%s\n", macrotable[j].definition[k]);
                    }
                    printf("MACRO END\n\n");
                    fflush(stdout);
                }
            }
        }
        else {
            printf("Source line: %s\n",lines_buffer[i]);
            fflush(stdout);

        }
    }

    return success;
}