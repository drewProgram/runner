// struct = group of vars (similar to a class)
struct map {
  char** matrix;
  int lines;
  int columns;
};

// defining a name nickname to the struct
typedef struct map MAP;

void readMap(MAP* m);
void allocateMap(MAP* m);
void freeMap(MAP* m);
void drawMap(MAP* m);
