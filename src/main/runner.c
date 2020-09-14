#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../headers/runner.h"
#include "../headers/map.h"

MAP m;
COORDINATES runner;

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