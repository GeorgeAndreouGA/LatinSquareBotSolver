//
// Created by andrewdems on 11/6/24.
//

#ifndef SOLVER_H
#define SOLVER_H
#include <stdbool.h>
#include "stack.h"

/**
 * @brief 
 *
 * This function uses backtracking to find a solution to the puzzle by trying each
 * possible move and using the stack to undo moves as necessary.
 *
 * @param stack Pointer to the stack used for backtracking.
 * @param square 2D array representing the puzzle square.
 * @param n The size of the puzzle (number of rows and columns).
 * @return true if the puzzle is solved, false if no solution exists.
 */
bool solve(STACK *stack,int **square, int n);

/**
 * @brief Finds the first empty cell in the puzzle.
 *
 * This function locates the next cell in the puzzle square that is empty (represented by 0)
 * and sets the row and column values to the location of this cell.
 *
 * @param square 2D array representing the puzzle square.
 * @param n The size of the puzzle (number of rows and columns).
 * @param row Pointer to store the row index of the empty cell.
 * @param col Pointer to store the column index of the empty cell.
 */

static void findEmptyCell(int **square, int n, int *row, int *col);


/**
 * @brief Checks if a number can be placed in a specific cell.
 *
 * This function verifies that a given number does not conflict with other numbers in
 * the same row or column. If the number is already present in either, the move is invalid.
 *
 * @param square 2D array representing the puzzle square.
 * @param row The row index of the cell.
 * @param col The column index of the cell.
 * @param n The size of the puzzle (number of rows and columns).
 * @param num The number to place in the cell.
 * @return true if the move is valid, false if the move is invalid.
 */



static bool checkIfValidMove(int **square, int row, int col, int n, int num);


#endif //SOLVER_H

