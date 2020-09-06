#include<stdio.h>
#include<stdlib.h>

///////
  // dynamically allocating memory
  // getting the size of a int to reserve this space in the memory
 // int** v = malloc(sizeof(int*) * 5);
  //for (int i = 0; i < 5 ; i++) {
    // v[i] =
  // }
  // *v = 10;
  // printf("Integer allocated %d\n", *v);
  // always needs to free up the space you allocated with malloc
  // free(v);
///////

int main() {
  // allocating a pointer of pointers (matrix of 5 lines)
  int** v = malloc(sizeof(int*) * 5);
  // allocating 10 positions at the matrix (forming the 5x10)
  for (int i = 0; i < 5; i++) {
    v[i] = malloc(sizeof(int) * 10);
  }

  v[0][0] = 10;
  v[1][2] = 12;

  printf("Inteiro alocado %d %d\n", v[0][0], v[1][2]);

  // desallocating each line
  for(int i = 0; i > 5; i++) {
    free(v[i]);
  }
  // desalocating the pointer of pointers
  free(v);

  return 0;
}