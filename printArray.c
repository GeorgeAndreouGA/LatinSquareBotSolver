#include"printArray.h"


void printSquare(int **pin,int size){
      printf("+");
    for (int j = 0; j < size; j++) {
        printf("-----+");
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size; j++) {
            int value = pin[i][j];
            if (value < 0) {  
                printf(" (%d) ", -value);
            } else if (value == 0) {  
                printf("  0  ");
            } else {  
                printf("  %d  ", value);
            }
            printf("|");
        }
        printf("\n");

        
        printf("+");
        for (int j = 0; j < size; j++) {
            printf("-----+");
        }
        printf("\n");
    }
}