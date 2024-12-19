/**
 * @file fileHandler.h
 * @brief Header file for file handling functions that read and validate text files containing integers in an NXN format.
 */


#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Reads integers from a text file and fills a dynamically allocated 2D array.
 *
 * This function reads integers from a text file specified by @p txt, and expects
 * the file to contain an NXN grid of numbers, where N is provided in the file.
 * If the file does not match the required format, the program exits with an error.
 *
 * @param txt The name of the text file to read from.
 * @param sizeOfArray Pointer to an integer that will hold the size of the array (N).
 * @return A pointer to the dynamically allocated 2D array filled with integers from the file.
 */
int **fill(char *txt, int *sizeOfArray);

/**
 * @brief Checks if a given file has a .txt extension.
 *
 * This function verifies that the file specified by @p txt has a ".txt" extension.
 *
 * @param txt The file name to check.
 * @return true if the file has a .txt extension, false otherwise.
 */

static bool checkIfTxt(char *txt);

/**
 * @brief Opens a text file for reading.
 *
 * This function checks if the specified file has a ".txt" extension and opens it in read mode.
 * If the file does not have a .txt extension or cannot be opened, the program exits with an error.
 *
 * @param txt The name of the text file to open.
 * @return A pointer to the opened file.
 */
static FILE *openFile(char *txt);

/**
 * @brief Frees a dynamically allocated 2D array.
 *
 * This function iterates through each row of the 2D array and frees the allocated memory for each,
 * as well as freeing the array itself.
 *
 * @param pin Pointer to the 2D array to free.
 * @param sizeOfArray The size of the array (number of rows and columns).
 */
void freeArray(int **pin, int sizeOfArray);

#endif 