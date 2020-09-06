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
  if (direction != 'w' &&
      direction != 'a' &&
      direction != 's' &&
      direction != 'd')
    return;

  int nextX = runner.x;
  int nextY = runner.y;

  switch (direction)
  {
  case 'w':
    nextX--;
    break;
  case 'a':
    nextY--;
    break;
  case 's':
    nextX++;
    break;
  case 'd':
    nextY++;
    break;
  }

  if (nextX >= m.lines) return;
  if (nextX >= m.columns) return;
  if (m.matrix[nextX][nextY] != '.' &&
      m.matrix[nextX][nextY] != ' ')
    return;

  m.matrix[nextX][nextY] = '@';
  m.matrix[runner.x][runner.y] = ' ';

  runner.x = nextX;
  runner.y = nextY;
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