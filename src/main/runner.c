#include <stdio.h>
#include <stdlib.h>

#include "../headers/runner.h"

// declaring matrix as a pointer of pointers
char **map;
int lines;
int columns;

void readMap()
{
  FILE *f;

  f = fopen("src/assets/map.txt", "r");

  if (f == 0)
  {
    printf("Error while reading the file\n");
    exit(1);
  }

  fscanf(f, "%d %d", &lines, &columns);

  allocateMap();

  for (int i = 0; i < 5; i++)
  {
    fscanf(f, "%s", map[i]);
  }

  fclose(f);
}

void allocateMap()
{
  // allocating the number os lines as pointers of chars
  map = malloc(sizeof(char *) * lines);
  // doing the same with columns
  for (int i = 0; i < lines; i++)
  {
    map[i] = malloc(sizeof(char) * (columns + 1));
  }
}

void drawMap()
{
  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", map[i]);
  }
}

void freeMap()
{
  // desallocating map
  for (int i = 0; i < lines; i++)
  {
    free(map[i]);
  }
  free(map);
}

int over()
{
  return 0;
}

void move(char direction)
{
  int x;
  int y;

  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (map[i][j] == '@')
      {
        x = i;
        y = j;
        break;
      }
    }
  }

  switch (direction)
  {
  case 'w':
    map[x - 1][y] = '@';
    break;
  case 'a':
    map[x][y - 1] = '@';
    break;
  case 's':
    map[x + 1][y] = '@';
    break;
  case 'd':
    map[x][y + 1] = '@';
    break;
  }

  map[x][y] = ' ';
}

int main()
{
  readMap();

  do
  {
    drawMap();

    char command;
    scanf(" %c", &command);
    move(command);

  } while (!over());

  freeMap();
}