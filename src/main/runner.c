#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../headers/runner.h"
#include "../headers/map.h"
#include "../headers/ui.h"

MAP m;
COORDINATES runner;
int hasPill = 0;

int directionGhostWalks(int originX, int originY,
                        int *destinyX, int *destinyY)
{

  // defining a matrix with the possible directions
  int options[4][2] = {
    {originX, originY + 1},
    {originX + 1, originY},
    {originX, originY - 1},
    {originX - 1, originY}
  };

  // randomizing which direction will be chosen
  srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    int position = rand() % 4;

    if (canWalk(&m, GHOST, options[position][0], options[position][1]))
    {
      *destinyX = options[position][0];
      *destinyY = options[position][1];

      return 1;
    }

  }
  return 0;
}

void ghosts()
{
  MAP copy;

  copyMap(&m, &copy);

  for (int i = 0; i < m.lines; i++)
  {
    for (int j = 0; j < m.columns; j++)
    {
      if (copy.matrix[i][j] == GHOST)
      {
        int destinyX;
        int destinyY;

        int found = directionGhostWalks(i, j, &destinyX, &destinyY);

        if (found)
        {
          walkOnMap(&m, i, j, destinyX, destinyY);
        }
      }
    }
  }
  freeMap(&copy);
}

int isDirection(char direction)
{
  return direction == UP ||
         direction == LEFT ||
         direction == DOWN ||
         direction == RIGHT;
}

void move(char direction)
{
  if (!isDirection(direction))
    return;

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

  if(!canWalk(&m, RUNNER, nextX, nextY)) return;

  if (pathHasCharacter(&m, PILL, nextX, nextY)) {
    hasPill = 1;
  }

  walkOnMap(&m, runner.x, runner.y, nextX, nextY);

  runner.x = nextX;
  runner.y = nextY;
}

int over()
{
  COORDINATES cord;
	int runnerOnMap = findOnMap(&m, &cord, RUNNER);
	return !runnerOnMap;
}

void explodePill() {
  explodePill2(runner.x, runner.y, 0, 1, 3);
  explodePill2(runner.x, runner.y, 0, -1, 3);
  explodePill2(runner.x, runner.y, 1, 0, 3);
  explodePill2(runner.x, runner.y, -1, 0, 3);

  hasPill = 0;
}

void explodePill2(int x, int y,  int sumX, int sumY, int qty) {
  if (qty == 0) return;

  int newX = x + sumX;
  int newY = y + sumY;

  if (pathHasWall(&m, newX, newY)) return;
  if (!pathIsValid(&m, newX, newY)) return;

  m.matrix[newX][newY] = VOID;
  explodePill2(newX, newY, sumX, sumY, qty - 1);
}

int main()
{
  readMap(&m);
  findOnMap(&m, &runner, RUNNER);

  do
  {
    printf("Has a pill: %s\n", (hasPill ? "YES" : "NO"));
    drawMap(&m);

    char command;
    scanf(" %c", &command);
    tolower(command);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    move(command);
    if (command == BOMB && hasPill) explodePill();

    ghosts();

  } while (!over());

  printf("Oh no, the runner has been caught!\n");

  freeMap(&m);
}