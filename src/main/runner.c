#include <stdio.h>
#include <stdlib.h>

#include "../headers/runner.h";

// declaring matrix as a pointer of pointers
char** map;
int lines;
int columns;

void readMap() {
  FILE* f;

  f = fopen("src/assets/map.txt", "r");

  if (f == 0) {
    printf("Error while reading the file\n");
    exit(1);
  }

  fscanf(f, "%d %d", &lines, &columns);

  allocateMap();

  for (int i = 0; i < 5 ; i++) {
    fscanf(f, "%s", map[i]);
  }

  fclose(f);
}

void allocateMap() {
  // allocating the number os lines as pointers of chars
  map = malloc(sizeof(char*) * lines);
  // doing the same with columns
  for (int i = 0; i < lines; i++) {
    map[i] = malloc(sizeof(char) * (columns + 1));
  }
}

void freeMap() {
  // desallocating map
  for (int i = 0; i < lines; i++) {
    free(map[i]);
  }
  free(map);
}



int main() {
  readMap();

  for (int i = 0; i < 5 ; i++) {
    printf("%s\n", map[i]);
  }

  freeMap();

  return 0;
}