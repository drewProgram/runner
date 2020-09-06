#include <stdio.h>
#include <stdlib.h>

#include "../headers/runner.h"
#include "../headers/map.h"

MAP m;

int over()
{
  return 0;
}

void move(char direction)
{
  int x;
  int y;

  for (int i = 0; i < m.lines; i++)
  {
    for (int j = 0; j < m.columns; j++)
    {
      if (m.matrix[i][j] == '@')
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
    m.matrix[x - 1][y] = '@';
    break;
  case 'a':
    m.matrix[x][y - 1] = '@';
    break;
  case 's':
    m.matrix[x + 1][y] = '@';
    break;
  case 'd':
    m.matrix[x][y + 1] = '@';
    break;
  }

  m.matrix[x][y] = ' ';
}

int main()
{
  readMap(&m);

  do
  {
    drawMap(&m);

    char command;
    scanf(" %c", &command);
    move(command);

  } while (!over());

  freeMap(&m);
}