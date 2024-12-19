//
// Created by Andreas Demosthenous on 05/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

static int pops = 0;
static int pushes = 0;

STACK * initStack() {
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    stack->length = 0;
    return stack;
}

int initStack2(STACK **stack) {
    if(*stack == NULL) {
        return EXIT_FAILURE;
    }
    (*stack)->top = NULL;
    (*stack)->length = 0;
    return EXIT_SUCCESS;
}

bool IsEmptyStack(STACK *stack) {
    if (stack->top == NULL) {
        return true;
    }
    return false;
}

NODE* top(STACK *stack) {
    if(stack->top == NULL) {
        return NULL;
    }
    return stack->top;
}

int push(STACK *stack, int **square, int row, int col, int n) { // push a new node to the stack
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        return EXIT_FAILURE;
    }
    newNode->square = (int **)malloc(n * sizeof(int *)); // allocate memory for the rows
    if (newNode->square == NULL) {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++) {
        newNode->square[i] = (int *)malloc(n * sizeof(int)); // allocate memory for the columns
        if (newNode->square[i] == NULL) {
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newNode->square[i][j] = square[i][j];
        }
    }
    newNode->row = row;
    newNode->col = col;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->length++;
    pushes++;
    return EXIT_SUCCESS;
}

int pop(STACK *stack, int ***square, int *row, int *col) {
    *square = stack->top->square; // return the square to the caller
    *row = stack->top->row;
    *col = stack->top->col;
    NODE *temp = stack->top;
    stack->top = stack->top->next;
    free(temp); // free the memory allocated for the node except the square
    stack->length--;
    pops++;
    return EXIT_SUCCESS;
}
int freeNode(NODE *node, int n) {
    if (node == NULL) {
        return EXIT_FAILURE;
    }
    if (node->square == NULL) {
        free(node);
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < n; i++){
        free(node->square[i]);
    }
    free(node->square);
    free(node);
    return EXIT_SUCCESS;
}
int emptyStack(STACK *stack, int n) {
    if (stack == NULL) {
        return EXIT_FAILURE;
    }
    while (stack->top != NULL) {
        NODE *temp = stack->top;
        stack->top = stack->top->next;
        freeNode(temp, n);
    }
    free(stack);
    return EXIT_SUCCESS;
}


int getPushes() {
    return pushes;
}
int getPops() {
    return pops;
}
#ifdef DEBUG
#include <assert.h>
int main()
{
    int **square = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        square[i] = (int *)malloc(9 * sizeof(int));
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // random number generator
            square[i][j] = rand() % 9 + 1;
        }
    }
    STACK *stack = initStack();
    push(stack, square, 0, 0, 9);
    assert(stack->length == 1);
    int **square2;
    int row, col;
    NODE *node = top(stack);
    assert(node->row == 0);
    assert(node->col == 0);
    pop(stack, &square2, &row, &col);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            assert(square[i][j] == square2[i][j]); // check if the squares are the same
        }
    }

    assert(stack->length == 0);
    assert(getPushes() == 1);
    assert(getPops() == 1);
    push(stack, square, 0, 1, 9);
    push(stack, square, 0, 2, 9);
    push(stack, square, 0, 3, 9);
    push(stack, square, 0, 4, 9);
    push(stack, square, 0, 5, 9);
    push(stack, square, 0, 6, 9);
    push(stack, square, 0, 7, 9);
    push(stack, square, 0, 8, 9);
    assert(stack->length == 8);
    assert(getPushes() == 9);
    assert(getPops() == 1);
    emptyStack(stack, 9);
    for(int i = 0; i < 9; i++) {
        free(square[i]);
        free(square2[i]);
    }
    free(square);
    free(square2);

    return 0;
}
#endif