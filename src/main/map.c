#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/map.h"

void copyMap(MAP* origin, MAP* destiny) {
  destiny->lines = origin->lines;
  destiny->columns = origin->columns;

  allocateMap(destiny);
  for (int i = 0; i < origin->lines; i++) {
    // receives an array of chars and copies this array
    strcpy(destiny->matrix[i], origin->matrix[i]);
  }
}

void walkOnMap(MAP* m, int originX, int originY,
  int destinyX, int destinyY) {

  char character = m->matrix[originX][originY];
  m->matrix[destinyX][destinyY] = character;
  m->matrix[originX][originY] = VOID;
}

int pathIsValid(MAP* m, int x, int y) {
  if (x >= m->lines) return 0;
  if (y >= m->columns) return 0;

  return 1;
}

int pathIsEmpty(MAP* m, int x, int y) {
  if (m->matrix[x][y] != FOOD &&
      m->matrix[x][y] != VOID) return 0;

  return 1;
}

void findOnMap(MAP *m, COORDINATES *c, char ch)
{
  for (int i = 0; i < m->lines; i++)
  {
    for (int j = 0; j < m->columns; j++)
    {
      if (m->matrix[i][j] == ch)
      {
        c->x = i;
        c->y = j;
        break;
      }
    }
  }
}

void freeMap(MAP *m)
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

void readMap(MAP *m)
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

void allocateMap(MAP *m)
{
  // allocating the number os lines as pointers of chars
  m->matrix = malloc(sizeof(char *) * m->lines);
  // doing the same with columns
  for (int i = 0; i < m->lines; i++)
  {
    m->matrix[i] = malloc(sizeof(char) * (m->columns + 1));
  }
}

void drawMap(MAP *m)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", m->matrix[i]);
  }
}