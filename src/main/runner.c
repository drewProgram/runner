#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../headers/runner.h"
#include "../headers/map.h"

MAP m;
COORDINATES runner;

void ghosts() {
  MAP copy;

  copyMap(&m, &copy);

  for (int i = 0; i < m.lines; i++) {
    for (int j = 0; j < m.columns; j++) {
      if (copy.matrix[i][j] == GHOST) {
        if (pathIsValid(&m, i, j+1) && pathIsEmpty(&m, i, j+1)) {
          walkOnMap(&m, i, j, i, j+1);
        }
      }
    }
  }
  freeMap(&copy);
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

int over()
{
  return 0;
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
    ghosts();

  } while (!over());

  freeMap(&m);
}