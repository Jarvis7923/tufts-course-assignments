/* problem3.c - Word counting */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// state machine variables for counting words.
enum State{
    WORD,
    NONWORD,
} state;

// prompt of usage information
void print_usage() {
    printf("usage: available options: -l -w -c. file shouzu be the last\n ");
}

// error message
void print_error() {
    printf("error\n");
}

// parse the input arguments, get options and filename
int parse_input(int argc, char* argv[], char** filename, int* l, int* c, int* w) {
    // no args to process if argc is 1, 
    if(argc == 1) {
        *filename = "\0";
        return 1;   
    }
    
    // get the last argv as file name
    char* last = argv[argc-1];
    if ( *last != '-') {
        *filename = argv[argc-1];
        argc-- ;
    }

    char* v = NULL;
    size_t len = 0;
    for(int i=1; i<argc; i++) {
        v = argv[i];
        len = strlen(v);
        // option with len < 2 is invalid
        if (*v < 2) {
            return 0;
        }
        else {
            // option does not start with '-' is invalid
            if (*v != '-') {
                return 0;
            }
            else {
                // set flags for which option is triggerd
                for (int i=1; i<len; i++) {
                    switch (*(v+i)){
                        case 'l':
                            *l = 1; break;

                        case 'w':
                            *w = 1; break;

                        case 'c':
                            *c = 1; break;
                        // other option is invalid
                        default:
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}


// add counting number on the previous counting number.
void add_count(char* buf, unsigned int* lc, unsigned int* cc, unsigned int* wc) {
    char ch = *buf;
    unsigned int i = 0;
    int s = NONWORD; // state variable
    while (ch!='\0') {
        // non word charactors 
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            s = NONWORD;
        }
        else {
            // last ch is NONWORD and this ch is WORD then wordnum ++ 
            if (s == NONWORD) {
                *wc = *wc + 1;
                s = WORD;      
            }
        }
        // num of bytes
        i ++;
        ch = *(buf + i);
    }
    *lc = *lc + 1; // line num increase by 1 for each call of getline()
    *cc = *cc + (i)*sizeof(char); 
}

// print the result to screen 
void print_count(char* filename, int l, unsigned int lc, int c, unsigned int cc, int w, unsigned int wc) {
    if (l) printf("  %u", lc);
    if (w) printf("  %u", wc);
    if (c) printf("  %u", cc);

    // if no option is set then assume all options are set
    if (!l && !w && !c) {
        printf("  %u  %u  %u", lc, wc, cc); 
    }

    if (filename != NULL) {
       printf("  %s", filename);
    }
    printf("\n");
}


int main(int argc, char* argv[]) {
    
    // file init
    char* filename = NULL;
    FILE * fp = NULL;
    
    // flags and counts 
    int l=0, c=0, w=0;
    unsigned int wc=0, lc=0, cc=0;  
    
    // show usage if invalid args are given
    if (!parse_input(argc, argv, &filename, &l, &c, &w)) {
        print_usage();
        return 1;
    }

    // read from stdin if no filename is given
    if (filename == NULL || *filename=='\0' ) {
        // buffer init 
        char* buf = NULL;
        size_t bufsize = 0;
        while ((getline(&buf, &bufsize, stdin)) != -1){
            add_count(buf, &lc, &cc, &wc);
        }
        free(buf);
        // else{
        //     print_error();
        //     return 1;
        // }
    }
    // read from file 
    else {
        fp = fopen(filename, "r");

        // check if file does not exist
        if (fp == NULL) {
            print_error();
            return 0;
        }
        // get line buffer
        char *line = NULL; 
        size_t len = 0;

        while((getline(&line, &len, fp)) != -1) {
            add_count(line, &lc, &cc, &wc);
        }
        free(line);
        fclose(fp);
    }
    // show the results
    print_count(filename, l, lc, c, cc, w, wc);
    
    return(0);
}

