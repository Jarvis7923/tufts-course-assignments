/* problem1.c - implementation of Linux `tree` */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

void print_usage(){
    printf("usage\n");
}

void printf_error(){
    printf("error\n");
}


// check if the path is a directory
int is_dir(const char *path) {
    struct stat pstat;
    stat(path, &pstat);
    return (S_ISDIR(pstat.st_mode));
}


int show_tree(char * path, int depth){
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(path);
    
    if (pDir == NULL) {
        return 0;
    }

    if (chdir(path)==-1) 
        return 0;

    if (depth==0) {
        printf("%s\n", path);
        depth++;
    }
    while ((pDirent = readdir(pDir)) != NULL) {
        if (is_dir( pDirent->d_name)) {
          if (pDirent->d_name[0] != '.' || strcmp(pDirent->d_name, "..")==-1 ) {
            printf ("%*s%s\n", 4*depth, "", pDirent->d_name);
            if (!show_tree( pDirent->d_name , depth + 1)){
                return 0;
            }
          }
        }
        else printf ("%*s%s\n", 4*depth, "", pDirent->d_name);
    }
    chdir("..");

    // Close directory and exit.
    closedir (pDir);
    return 1;
}


int main(int argc, char* argv[]) {

    // show tree of the current dir
    if (argc == 1) {
        show_tree(".", 0);
        return 0;
    }
    else if (argc == 2) {
        if (!show_tree(argv[1], 0)) {
            printf_error();
            return 1;
        }
    }
    else {
        print_usage();
        return 1;
    }
    // Ensure correct argument count.


    // Ensure we can open directory.


    // Process each entry.

    return 0;
}

