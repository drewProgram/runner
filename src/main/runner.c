#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../headers/runner.h"
#include "../headers/map.h"

MAP m;
COORDINATES runner;

int over()
{
  return 0;
}

int isDirection(char direction) {
  return direction == UP ||
  direction == LEFT ||
  direction == DOWN ||
  direction == RIGHT;
}

void move(char direction)
{
  if (!isDirection(direction)) return;

  int nextX = runner.x;
  int nextY = runner.y;

  switch (direction)
  {
  case UP:
    nextX--;
    break;
  case LEFT:
    nextY--;
    break;
  case DOWN:
    nextX++;
    break;
  case RIGHT:
    nextY++;
    break;
  }

  if (!pathIsValid(&m, nextX, nextY)) return;
  if (!pathIsEmpty(&m, nextX, nextY)) return;

  walkOnMap(&m, runner.x, runner.y, nextX, nextY);

  runner.x = nextX;
  runner.y = nextY;
}

int main()
{
  readMap(&m);
  findOnMap(&m, &runner, RUNNER);

  do
  {
    drawMap(&m);

    char command;
    scanf(" %c", &command);
    tolower(command);

    move(command);

  } while (!over());

  freeMap(&m);
}