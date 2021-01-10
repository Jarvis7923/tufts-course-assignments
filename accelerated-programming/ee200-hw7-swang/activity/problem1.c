/* problem1.c - Activity log 
 * append content to `activity.tsv`
 * create the file if the file not exist 
 * run the binary with command `./log run 20 "some note"`
 * if either of the first two command is invalid. A usage info should be print on the screen. 
 *
 * content to write in `activity.tsv`
 *  1. epoch time (sec since 00:00 Jan 1st 1970 UTC)
 *  2. activity name (string "run" or "swim" or other) 
 *  3. duration (in minute)
 *  4. note (optional)
 * 
 * */

#include <stdio.h>
#include <ctype.h>
#include <time.h>


void print_usage(){
    printf("usage: ./log arg1 arg2 [arg3]\n");
    printf("\targ1: name of the activity.\n");
    printf("\targ2: integer number] time spent on the activity in minute.\n");
    printf("\targ3: [optional] note of the activity, eg.\"nice day\".\n");
}

int main(int argc, char* argv[]) {
    // get the epoch time
    size_t epoch_time = time(NULL); 

    // check if the first two arguments are empty
    if (argc !=3 && argc !=4) {
        printf("Error. 2 or 3 args required but %d is given.\n", argc-1);
        print_usage();
        return 1;
    }

    char* activity = argv[1]; 
    char* duration = argv[2]; 
    
    char* pd = duration;
    
    while (*pd != '\0'){
        if (!isdigit(*pd)) {
            printf("Error. integer required but \"%s\" is given.\n", duration);
            print_usage();
            return 1; 
        }
        pd ++;   
    }

    // check if the third arg(note) is  empty
    char* note = NULL;
    if (argv[3]!=NULL) note = argv[3]; 

    char* filename = "activity.tsv";
    FILE* fp;
    fp = fopen(filename, "a");
    
    //check if fopen fails 
    if (fp == NULL){
        perror("fopen failed: ");    
        return 1;
    }

    if (note == NULL)
        fprintf(fp, "%ld\t%s\t%s\n", epoch_time, activity, duration);
    else 
        fprintf(fp, "%ld\t%s\t%s\t%s\n", epoch_time, activity, duration, note);

    fclose(fp);

    return 0;
}

