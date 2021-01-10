// standard library
#include <stdio.h>

// problem library
#include "problem1.h"

// helper function to print the board elements
void print_board(char board[3][3]){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
        if (board[i][j] == ' ')
            printf("_ ");
        else
            printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// test for one case
void unit_test(char board[3][3]) {
    print_board(board);
    char c = check_win(board);
    if (c == '\0') 
        printf("\nInvalid results\n\n");
    else if (c == '.') 
        printf("\nCats game\n\n");
    else if (c == ' ') 
        printf("\nOn going\n\n");
    else 
        printf("\nWinner: %c \n\n", c);
}


void test(){
    // main test scenario
    char b[][3][3] = {
       // o wins 
       {{'o','o','x'},
        {'x','o','x'},
        {'x','x','o'}},
       
       {{'x','o','x'},
        {'o','o','o'},
        {'x','x','o'}},
       
       {{'x','o','o'},
        {'o','o','x'},
        {'x','o','x'}},
       
       // x wins
       {{'x','x','o'},
        {'o','x','o'},
        {'o','o','x'}},
       
       {{'o','x','o'},
        {'x','x','x'},
        {'o','o','x'}},
       
       {{'o','x','x'},
        {'x','x','o'},
        {'o','x','o'}},
       
       // ongoing
       {{'x','x',' '},
        {'o','o',' '},
        {' ',' ',' '}},
       
       // invalid
       {{'x','x','x'},
        {'o','o','o'},
        {' ',' ',' '}},
       
       {{'x','x',' '},
        {'o','o',' '},
        {' ',' ','r'}},
      
       {{'x','x','x'},
        {'o','o','x'},
        {' ','x','x'}},
      
       // cat's game
       {{'x','x','o'},
        {'o','o','x'},
        {'x','o','o'}},
    };
    int n = sizeof(b)/sizeof(b[0]);
    for (int i=0; i<n; i++) {
        unit_test(b[i]);
    }
}

// main function
int main(int argc, char* argv[]){
    test();   
    return(0);
}




