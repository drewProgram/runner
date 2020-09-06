#include <stdio.h>
#include <stdlib.h>

#include "../headers/map.h"

void freeMap(MAP* m)
{
  // desallocating map
  // instead of using (*m).lines, we can use m->lines
  // as we are getting the pointer of the map, we also need to tell the program that we
  // are using a pointer to reference the map.
  for (int i = 0; i < m->lines; i++)
  {
    free(m->matrix[i]);
  }
  free(m->matrix);
}

void readMap(MAP* m)
{
  FILE *f;

  f = fopen("src/assets/map.txt", "r");

  if (f == 0)
  {
    printf("Error while reading the file\n");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->lines), &(m->columns));

  allocateMap(m);

  for (int i = 0; i < 5; i++)
  {
    fscanf(f, "%s", m->matrix[i]);
  }

  fclose(f);
}

void allocateMap(MAP* m)
{
  // allocating the number os lines as pointers of chars
  m->matrix = malloc(sizeof(char *) * m->lines);
  // doing the same with columns
  for (int i = 0; i < m->lines; i++)
  {
    m->matrix[i] = malloc(sizeof(char) * (m->columns + 1));
  }
}

void drawMap(MAP* m)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", m->matrix[i]);
  }
}