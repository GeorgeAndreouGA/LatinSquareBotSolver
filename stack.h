//
// Created by Andreas Demosthenous on 05/11/2024.
//

#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct node
{
   int **square;
   int row;
   int col;
   struct node *next;
} NODE;
typedef struct
{
   NODE *top;
   int length;
} STACK;




/**
 * @brief Initializes a new stack.
 * 
 * Allocates memory for a new stack and initializes its top pointer and length.
 * 
 * @return A pointer to the newly allocated stack, or NULL if allocation fails.
 */
STACK *initStack();

/**
 * @brief Initializes an existing stack structure.
 * 
 * Resets the top pointer and length of a pre-allocated stack.
 * 
 * @param stack Double pointer to the stack to be initialized.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if the stack pointer is NULL.
 */
int initStack2(STACK **stack);

/**
 * @brief Checks if the stack is empty.
 * 
 * @param stack Pointer to the stack.
 * @return `true` if the stack is empty, `false` otherwise.
 */
bool IsEmptyStack(STACK *stack);

/**
 * @brief Gets the top node of the stack without popping it.
 * 
 * @param stack Pointer to the stack.
 * @return A pointer to the top node, or NULL if the stack is empty.
 */
NODE* top(STACK *stack);

/**
 * @brief Pushes a new node with a 2D array onto the stack.
 * 
 * Copies the contents of the given 2D array into the new node and
 * pushes it onto the stack. Increases the global push counter.
 * 
 * @param stack Pointer to the stack.
 * @param square 2D array to be copied into the node.
 * @param row Row position in the array.
 * @param col Column position in the array.
 * @param n Size of the 2D array.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if memory allocation fails.
 */
int push(STACK *stack, int **square, int row, int col, int n);

/**
 * @brief Pops the top node from the stack.
 * 
 * Removes the top node from the stack and returns its 2D array, row, and column.
 * Increases the global pop counter.
 * 
 * @param stack Pointer to the stack.
 * @param square Double pointer to the 2D array to receive the popped node's square.
 * @param row Pointer to an int to receive the popped row position.
 * @param col Pointer to an int to receive the popped column position.
 * @return EXIT_SUCCESS on success.
 */
int pop(STACK *stack, int ***square, int *row, int *col);

/**
 * @brief Frees a single node.
 * 
 * Frees the memory associated with a node, including its 2D array.
 * 
 * @param node Pointer to the node to be freed.
 * @param n Size of the 2D array in the node.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if node is NULL.
 */
int freeNode(NODE *node, int n);

/**
 * @brief Empties and frees the stack.
 * 
 * Frees all nodes in the stack, including their 2D arrays, then frees the stack itself.
 * 
 * @param stack Pointer to the stack to be emptied.
 * @param n Size of the 2D array in each node.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE if stack is NULL.
 */
int emptyStack(STACK *stack, int n);


/**
 * @brief Gets the number of push operations performed.
 * 
 * @return The total number of pushes.
 */
int getPushes();

/**
 * @brief Gets the number of pop operations performed.
 * 
 * @return The total number of pops.
 */
int getPops();

#endif //STACK_H
