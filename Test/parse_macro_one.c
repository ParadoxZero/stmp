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
            "test tt ff gg \n"
            "END\n");
    fclose(fp);

    char lines_buffer[LINE_BUFFER_SIZE][LINE_SIZE];
    int line_count = get_all_lines("testfile.asm",lines_buffer,LINE_BUFFER_SIZE);
    if (line_count == -1){
        fprintf(stderr,"Unable to retrieve source.\n");
        return -1;
    }

    struct stmp_MACROTABLE *macrotable = (struct stmp_MACROTABLE*) malloc(sizeof(struct stmp_MACROTABLE)*255);
    if(macrotable==NULL){
        perror("Unable to allocate.\n");
        return -1;
    }
    int M_count = 0;
    int success = 1;
    char word_buffer[WORD_BUFFER_SIZE][WORD_SIZE];

    for (int i = 0; i < line_count; ++i) {
        //printf("Processing line %d: %s\n", i, lines_buffer[i]);
        fflush(stdout);
        int word_count = get_all_words(lines_buffer[i],word_buffer,WORD_BUFFER_SIZE);
        if( word_count == -1){
            return -1;
        }

        if (strcmp(word_buffer[1],MACRO)==0) {
            success = parse_macro_definitions(lines_buffer, &i, line_count, macrotable, &M_count, 10);
            if(success == -1){
                fprintf(stderr,"Error parsing.\n");
                break;
            }
            else {
                for (int j = 0; j < M_count; ++j) {
                    printf("\n------\nName: %s, arg count: %d\nDefinition:\n", macrotable[j].name, macrotable[j].arg_count);
                    for (int k = 0; k < macrotable[j].def_count; ++k) {
                        printf("%s\n", macrotable[j].definition[k]);
                    }
                    printf("MACRO END\n-----\n");
                    fflush(stdout);
                }
            }
        }
        else {
            struct stmp_arg_table arg_table[10];
            int arg_count = 0;
            int macro_called = 0;
            for (int j = 0; j < word_count; ++j) {
                int m_index;
                if ((m_index=check_table_macro_name(macrotable,M_count,word_buffer[j]))!=-1){
                    j++;
                    if(word_count-j != macrotable[m_index].arg_count){
                        fprintf(stderr,"Illegal macro \'%s\' invocation at line %d",word_buffer[j-1],i+1);
                        return -1;
                    }
                    for (int k = 0; k < macrotable[m_index].arg_count; ++k) {
                        strcpy(arg_table[k].arg,macrotable[m_index].arg_list[k]);
                        strcpy(arg_table[k].value,word_buffer[j]);
                        j++;
                    }
                    success = expand_macro(macrotable[m_index],arg_table,stdout);
                }
                else{
                    fprintf(stdout,"%s",word_buffer[j]);
                }
            }
            fprintf(stdout,"\n");
            fflush(stdout);

        }
    }

    return success;
}