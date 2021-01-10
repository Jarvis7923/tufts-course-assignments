// standard library
#include <stdio.h>

// problem library
#include "problem1.h"


// board state enumerate
enum State {
    INVALID = '\0',
    CATS_GAME='.', 
    O_WON='o', 
    X_WON='x',
    ONGOING=' ',
    NO_LINE='0'
}; 

// determine whether the board is in a valid condition
int is_valid(char board[3][3]) {
    int has_empty = 0;
    int nx = 0, no = 0;
    char c; 
    for(int i=0; i < 3; i++){
        for (int j=0; j < 3; j++ ){
            c = board[i][j];
            if (c == 'x') nx++ ;
            else if (c == 'o') no++; 
            else if (c == ' ') has_empty = 1;
            else 
                return 0;       
        }
    }
    // check if the difference in number of x and o exceeds 2
    if ( no-nx >= 2 || nx-no >= 2 ) {
        return 0;
    }
    // check if board has empty slots
    if (has_empty) 
        return 2;
    else 
        return 1;
}

// check if the board contains a complete line in
// "x", "o" 
char has_line(char b[3][3]) {
    int n_line = 0;
    char c = NO_LINE;
    // all the indeces for a line in the 3x3 board
    int id[8][3][2] = {
        {{0,0}, {0,1}, {0,2}},
        {{1,0}, {1,1}, {1,2}},
        {{2,0}, {2,1}, {2,2}},
        {{0,0}, {1,0}, {2,0}},
        {{0,1}, {1,1}, {2,1}},
        {{0,2}, {1,2}, {2,2}},
        {{0,0}, {1,1}, {2,2}},
        {{0,2}, {1,1}, {2,0}}
    };
    
    int *x, *y;
    for (int i=0; i < 8; i++) {
        x = id[i][1];
        y = x + 1;
        // check if there a complete line that is not 3 ' '
        if( b[*x][*y] != ' ' &&
                b[*x][*y] == b[*(x+2)][*(y+2)] && 
                b[*x][*y] == b[*(x-2)][*(y-2)] ) {
            n_line ++;
            c = b[*x][*y];
        }
    }
    return  (n_line <= 1) ? c : INVALID; 
}

// check winfunction
char check_win(char board[3][3]) {

    // check if the board is invalid
    int valid  = is_valid(board);
    if (!valid) return INVALID; 
    
    int has_empty = valid - 1;
    char line = has_line(board);
    // multiple lines 
    if (line == INVALID)  return INVALID;
    // no complete line
    if (line == NO_LINE) {
        return (has_empty) ? ONGOING : CATS_GAME;
    }
    // return winner
    return line; 
}


