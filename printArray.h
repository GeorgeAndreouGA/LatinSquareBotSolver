#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

/**
 * @brief Prints a square 2D array to the console.
 *
 * This function takes a dynamically allocated 2D array and prints it
 * in a square format, with each row on a new line.
 *
 * @param pin The 2D array to print.
 * @param size The size of the array (number of rows and columns).
 */
void printSquare(int **pin, int size);

#endif 
