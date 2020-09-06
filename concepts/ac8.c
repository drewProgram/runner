#include <stdio.h>
#include <stdlib.h>

int main()
{
  int **matrix;
  int lines = 5;
  int columns = 10;

  matrix = malloc(sizeof(int *) * lines);
  for (int i = 0; i < lines; i++)
  {
    matrix[i] = malloc(sizeof(int) * columns);
  }

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < columns; j++ ) {
      printf("%d", j);
    }
    printf("\n");
  }

  for (int i = 0; i < lines; i++) {
    free(matrix[i]);
  }
  free(matrix);
}