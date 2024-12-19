#include"fileHandler.h"
#include"printArray.h"
#include "solver.h"
#include "stack.h"

int main(int argc,char *argv[]){

   if (argc < 2) {
      printf("Usage: %s <input>.txt\n", argv[0]);
      return EXIT_FAILURE;
   }
   

   int size=0;
   int **latinSquare=fill(argv[1],&size);
   STACK *stack=initStack();
   if(!solve(stack,latinSquare,size))
      printf("Error: The latin square is unsovable\n");
   else
      printf("Solved\n");
   emptyStack(stack,size);
   freeArray(latinSquare,size);
   return 0;
}
