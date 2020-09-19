#ifndef _MAP_H_
#define _MAP_H_

#define RUNNER '@'
#define GHOST 'G'
#define PILL 'P'

#define VOID '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL1 '='
#define HORIZONTAL_WALL2 '-'

// struct = group of vars (similar to a class)
struct map {
  char** matrix;
  int lines;
  int columns;
};

// defining a nickname to the struct
typedef struct map MAP;

struct coordinates {
  int x;
  int y;
};

typedef struct coordinates COORDINATES;

void readMap(MAP* m);
void allocateMap(MAP* m);
void freeMap(MAP* m);
int findOnMap(MAP *m, COORDINATES *c, char ch);
void copyMap(MAP* origin, MAP* destiny);

int canWalk(MAP* m, char character, int x, int y);
int pathIsValid(MAP* m, int x, int y);
int pathIsEmpty(MAP* m, int x, int y);
int pathHasWall(MAP* m, int x, int y);
int pathHasCharacter(MAP* m, char character, int x, int y);
void walkOnMap(MAP* m, int originX, int originY,
  int destinyX, int destinyY);

#endif