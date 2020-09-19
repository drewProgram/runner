#ifndef _RUNNER_H_
#define _RUNNER_H_

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define BOMB 'b'

int directionGhostWalks(int originX, int originY,
                        int *destinyX, int *destinyY);
void ghosts();

int isDirection(char direction);
void move(char direction);

void explodePill();
void explodePill2(int x, int y,  int sumX, int sumY, int qty);

int over();

#endif