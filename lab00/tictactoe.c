#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)
#define CROSS 'X'
#define CIRCLE 'O'

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char row_check(char board[BOARD_SIZE][BOARD_SIZE], char player){
   char winner = '-';
   bool win = false;

   for(int row = 0; row < BOARD_SIZE && !win; ++row){
       win = true;
       for(int colum = 0; colum < BOARD_SIZE && win; ++colum){
           if(board[row][colum] != player){
              win = false;
            }
        }
        if(win){
           winner = player;
        }
    }
    
    return winner;
}
char colum_check(char board[BOARD_SIZE][BOARD_SIZE], char player){
   char winner = '-';
   bool win = false;

   for(int row = 0; row < BOARD_SIZE && !win; ++row){
       win = true;
       for(int colum = 0; colum < BOARD_SIZE && win; ++colum){
           if(board[colum][row] != player){
              win = false;
            }
        }
        
    }
    if(win){
           winner = player;
    }
    
    return winner;
}
char diagonals_check(char board[BOARD_SIZE][BOARD_SIZE], char player){
   char winner = '-';
   bool win = true;

   for(int row = 0; row < BOARD_SIZE && win; ++row){
       if(board[row][row] != player){
          win = false;
       }
   }
   if(!win){
       win = true;
       for(int row = 0; row < BOARD_SIZE; ++row){
           if(board[row][BOARD_SIZE - 1 - row] != player){
              win = false;
           }
       }
   }
   
   if(win){
      winner = player;
   }
    
    
    return winner;
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    char winner = '-';
    
    
    winner = row_check(board, CROSS);
       
    if(winner == '-'){
        winner = colum_check(board, CROSS);
    }
    if(winner == '-'){
        winner = diagonals_check(board, CROSS);
    }
           
    if(winner == '-'){
        winner = row_check(board, CIRCLE);
    } 
    if(winner == '-'){
        winner = colum_check(board, CIRCLE);
    }
    if(winner == '-'){
        winner = diagonals_check(board, CIRCLE);
    }
     
    
    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    bool free_cell = false;

    // IMPLEMENTAR
    for(int row = 0; row < BOARD_SIZE; ++row){
        for(int column = 0; column < BOARD_SIZE  && !free_cell; ++column){ 
            free_cell = board[row][column] == '-';
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
