//
// Created by Andreas Demosthenous on 11/6/24.
//
static int stepCounter=1;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "solver.h"
#include "printArray.h"

static bool solveHelper(STACK *stack, int **square, int n);
static void findEmptyCell(int **square, int n, int *row, int *col);  
static bool checkIfValidMove(int **square, int row, int col, int n, int num);

static bool checkIfValidMove(int **square, int row, int col, int n, int num) {
   int plith=0;

   for(int j=0;j<n;j++) {
      if(square[row][j]==num || square[row][j] == -num){
         plith++;
      }
   }
   if (plith>=1) {
      return false;
   }
   plith=0;

   for(int i=0;i<n;i++) {
      if((square[i][col]==num)|| square[i][col]== -num)
         plith++;
   }
   if (plith>=1) {
      return false;
   }
   return true;
}



 bool solve(STACK *stack, int **square, int n) {
   int row = 0, col = 0, blacklist = -1;

   while (true) {
      findEmptyCell(square, n, &row, &col);
     if (row == -1 && col == -1) {
         printf("PUSH NUM: %d\n", getPushes());
         printf("POP NUM: %d\n", getPops());
         return true;
      }

      int i = 1;
      if (blacklist != -1) {
         i = blacklist + 1;
      }

      bool found = false;
      for (int num = i; num <= n; num++) {
         if (checkIfValidMove(square, row, col, n, num)) {
            square[row][col] = num;
            push(stack, square, row, col, n);
            printf("PUSH STEP %d\n", stepCounter++);
            printSquare(square, n);
            blacklist = -1;
            found = true;
            break;
         }
      }

      if (!found) {
         if (IsEmptyStack(stack)) {
            printf("PUSH NUM: %d\n", getPushes());
            printf("POP NUM: %d\n", getPops());
            return false;
         }


         int **squareBacktracked;
         pop(stack, &squareBacktracked, &row, &col);
         // do a copy of the square
         for (int k = 0; k < n;k++) {
            for (int j = 0; j < n; j++) {
               square[k][j] = squareBacktracked[k][j];
            }
         }
         for (int j = 0; j < n; j++) {
            free(squareBacktracked[j]);
         }
         free(squareBacktracked);
         printf("POP STEP %d\n", stepCounter++);
         printSquare(square, n);
         blacklist = square[row][col];
         square[row][col] = 0;
      }
   }
}
static void findEmptyCell(int **square, int n, int *row, int *col){
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         if (square[i][j] == 0){
            *row = i;
            *col = j;
            return;
         }
      }
   }
   *row = -1;
   *col = -1;
}






#ifdef DEBUG_SOLVER
#include <assert.h>
int main(){
   
      int n = 4;
      int **square = (int **)malloc(n * sizeof(int *));
      for (int i = 0; i < n; i++){
         square[i] = (int *)malloc(n * sizeof(int));
      }
      square[0][0] = 1;
      square[0][1] = 2;
      square[0][2] = 3;
      square[0][3] = 4;
      square[1][0] = 3;
      square[1][1] = 4;
      square[1][2] = 1;
      square[1][3] = 2;
      square[2][0] = 4;
      square[2][1] = 3;
      square[2][2] = 2;
      square[2][3] = 1;
      square[3][0] = 2;
      square[3][1] = 1;
      square[3][2] = 4;
      square[3][3] = 3;
      int row = 0;
      int col = 0;
      findEmptyCell(square, n, &row, &col);
      assert(row == -1);
      assert(col == -1);
      square[0][0] = 0;
      square[0][1] = 0;
      square[0][2] = 0;
      square[0][3] = -4;
      square[1][0] = 0;
      square[1][1] = -2;
      square[1][2] = 0;
      square[1][3] = 0;
      square[2][0] = 0;
      square[2][1] = 0;
      square[2][2] = 0;
      square[2][3] = 0;
      square[3][0] = 0;
      square[3][1] = 0;
      square[3][2] = 0;
      square[3][3] = -2;
      assert(checkIfValidMove(square, 0, 0, n, 1) == true);
      assert(checkIfValidMove(square, 0, 0, n, 2) == true);
      assert(checkIfValidMove(square, 0, 0, n, 3) == true);
      assert(checkIfValidMove(square, 0, 0, n, 4) == false);
      assert(checkIfValidMove(square, 0, 0, n, 1) == true);
      assert(checkIfValidMove(square, 0, 0, n, 2) == true);
      assert(checkIfValidMove(square, 0, 1, n, 3) == true);
      assert(checkIfValidMove(square, 0, 1, n, 4) == false);
      assert(checkIfValidMove(square, 1, 1, n, 1) == true);
      assert(checkIfValidMove(square, 1, 1, n, 2) == false);
      assert(checkIfValidMove(square, 1, 1, n, 3) == true);
      assert(checkIfValidMove(square, 1, 1, n, 4) == true);
      assert(checkIfValidMove(square, 1, 3, n, 1) == true);
      assert(checkIfValidMove(square, 1, 3, n, 2) == false);
      assert(checkIfValidMove(square, 1, 3, n, 3) == true);
      assert(checkIfValidMove(square, 1, 3, n, 4) == false);
      assert(checkIfValidMove(square, 3, 3, n, 1) == true);
      assert(checkIfValidMove(square, 3, 3, n, 2) == false);
      assert(solve(square, n) == true);
      return 0;


}
#endif