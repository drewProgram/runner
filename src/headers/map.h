#define RUNNER '@'
#define GHOST 'G'

#define FOOD '.'
#define VOID ' '
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

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
void drawMap(MAP* m);
void findOnMap(MAP *m, COORDINATES *c, char ch);
void copyMap(MAP* origin, MAP* destiny);

int canWalk(MAP* m, int x, int y);
int pathIsValid(MAP* m, int x, int y);
int pathIsEmpty(MAP* m, int x, int y);
void walkOnMap(MAP* m, int originX, int originY,
  int destinyX, int destinyY);
