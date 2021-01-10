/* problem2.c - Activity summary
 * 
 * binary name "summarize"
 * 
 * argument is a integer and one of the:
 *  "d", for day
 *  "w", for week
 *  "y", for year
 * example input: ./summarize 1w
 * output on the screen: Total exercise: 99 minutes
 *
 * usage should be printed containing the word "usage" 
 *  2nd arg is not given, usage shows up.
 * 
 * error should be printed containing the word "error"
 *  the file does not exsit
 *  fail to open
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

// print usage information
void print_usage(){
    printf("usage: ./summarize arg1\n");
    printf("\targ1: duration of the summarize.\n");
    printf("\t      format is a integer plus one of 'd','w' or 'y'.\n");
    printf("\t      (eg.31d or 2w,1y)\n");
}

// print error information 
void print_error(){
    printf("error: file error\n");
}

int parse_arg(char* duration, const size_t len, size_t* start, size_t* end) {
    
    if (len < 2) {
        return 0; 
    }

    char* pd = duration;
    for (int i=0; i<len-1; i++) {
        if (!isdigit(*pd)) {
            return 0; 
        }
    }

    char num_s[len];
    strncpy(num_s, duration, len-1);
    
    char dur = *(duration+len-1);  
    int num = atoi(num_s);
    
    // assume no negative time allowed
    switch (dur){
        case 'd':
            *start = *end - num * 60*60*24;
            break;
        case 'w':
            *start = *end - num * 7*60*60*24;
            break;
        case 'y':
            *start = *end - num * 365*60*60*24;
            break;
        default:
            return 0;
    }
    return 1;
}


int acc_minute(char* filename, int* minute, size_t start, size_t end){
    // open file
    FILE *fp;
    fp = fopen(filename,"r");
    
    // check if file does not exist
    if (fp == NULL) {
        return 0;
    }
    
    size_t t = 0;  // epoch time in the file
    char *line = NULL; 
    size_t len = 0;
    char *ls =NULL, *le=NULL;
    
    while((getline(&line, &len, fp)) != -1) {
        le = strtok (line," \t");
        t = atoi(le); 
        if (t==0) {
            return 0; 
        }
        if (t <= end && t >= start ){
            for (int i=0; i<2; i++) {
                le = strtok (NULL, " \t");
            }
            *minute += atoi(le);
        }
    }
    
    free(line);
    fclose(fp);
    
    return 1;
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        printf("Error. 1 args required but %d is given.\n", argc-1);
        print_usage();
        return 1;
    }
       
    char* duration = argv[1]; 
    const size_t lend = strlen(duration);
    
    size_t start = 0, end = time(NULL); // start and end of the summary

    // parse the argument in to num and dur
    if (!parse_arg(duration, lend, &start, &end)){
        printf("Error. invalid arg \"%s\".\n", duration);
        print_usage();
        return 1;
    }

    char* filename = "activity.tsv";
    int minute = 0;
    
    // accumulate the 
    if (!acc_minute(filename, &minute, start, end)) {
        print_error();
        return 1;
    }
 

    printf("Total exercise: %d minutes\n", minute);
    return(0);
}

