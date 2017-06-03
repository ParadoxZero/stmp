/*
 *
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

/*
 * Exit codes:
 *  13 - Unexpected arguments
 *  10 - Too large filelist
 */
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "stmp_process.h"

#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define REVISION 3
#define PROGRAM_NAME "stmp"

#define MAX_NUM_PATH 255
#define MAX_LINE_BUFFER_SIZE 3000
#define MAX_WORD_BUFFER_SIZE 300

char *path_list[MAX_NUM_PATH];
int path_list_count = 0;

static void usage(){
    printf(""
                   "Usage:\n"
                   "    %s [FLAGS]... [PATH]\n"
                   "\n"
                   "Flags available to use:\n"
                   "1) -v, --version    Output version details and exit.\n"
                   "2) -h, --help    Output this help and exist.\n"
                   "\nExapmle: %s example.asm\n",
    PROGRAM_NAME,PROGRAM_NAME);
    fflush(stdout);
    exit(EXIT_SUCCESS);
}

static void version(){
    printf(""
                   "stmp version %d.%d.%d\n"
                   "Copyright (c) 2017 Sidhin S Thomas.\n"
                   "All rights reserverd.\n"
                   "Author holds no liability regarding usage.\n"
                   "Free to use and alter :)\n",
    MAJOR_VERSION,MINOR_VERSION,REVISION);
    fflush(stdout);
    exit(EXIT_SUCCESS);
}



static void parse_options(int argc, char *argv[]){
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'}
    };
    if (argc < 2){
        fprintf(stderr, "Missing arguments.\n");
        fflush(stderr);
        usage();
    }
    int opt_index = 0;
    int c ;
    while((c=getopt_long(argc,argv,"hv",long_options,&opt_index))!=-1){
        switch(c){
            case 'h':
                usage();
                break;
            case 'v':
                version();
                break;
            case '?':
                break;
            default:
                fprintf(stderr,"Unexpected argument");
                exit(13);
        }
    }
    if (optind >= argc){
        usage();
        return;
    }
    while (optind < argc){
        path_list[path_list_count++] = argv[optind++];
        if (path_list_count >= MAX_NUM_PATH){
            fprintf(stderr,"Input file count too huge.\n"
                    "Unable to process.\n");
            exit(10);
        }
    }
}

int main(int argc, char *argv[]) {

    parse_options(argc,argv);

    for (int i = 0; i < path_list_count; ++i) {
        printf("Processing file: %s\n",path_list[i]);
            if(process_source(path_list[i])){
                return -1;
            }
    }
    return 0;
}