#include <stdio.h>
#include <stdlib.h>

// declaring matrix as a pointer of pointers
char** map;
int lines;
int columns;

int main() {

  FILE* f;

  f = fopen("src/assets/map.txt", "r");

  if (f == 0) {
    printf("Error while reading the file\n");
    exit(1);
  }

  fscanf(f, "%d %d", &lines, &columns);
  printf("lines %d columns %d", lines, columns);

  // allocating the number os lines as pointers of chars
  map = malloc(sizeof(char*) * lines);
  // doing the same with columns
  for (int i = 0; i < lines; i++) {
    map[i] = malloc(sizeof(char) * (columns + 1));
  }

  for (int i = 0; i < 5 ; i++) {
    fscanf(f, "%s", map[i]);
  }

  for (int i = 0; i < 5 ; i++) {
    printf("%s\n", map[i]);
  }

  fclose(f);

  return 0;
}