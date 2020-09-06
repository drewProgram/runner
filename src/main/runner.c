#include <stdio.h>
#include <stdlib.h>

#include "../headers/runner.h"
#include "../headers/map.h"

MAP m;
COORDINATES runner;

int over()
{
  return 0;
}

void move(char direction)
{
  m.matrix[runner.x][runner.y] = ' ';

  switch (direction)
  {
  case 'w':
    m.matrix[runner.x - 1][runner.y] = '@';
    runner.x--;
    break;
  case 'a':
    m.matrix[runner.x][runner.y - 1] = '@';
    runner.y--;
    break;
  case 's':
    m.matrix[runner.x + 1][runner.y] = '@';
    runner.x++;
    break;
  case 'd':
    m.matrix[runner.x][runner.y + 1] = '@';
    runner.y++;
    break;
  }
}

int main()
{
  readMap(&m);
  findOnMap(&m, &runner, '@');

  do
  {
    drawMap(&m);

    char command;
    scanf(" %c", &command);
    move(command);

  } while (!over());

  freeMap(&m);
}