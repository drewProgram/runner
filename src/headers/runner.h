#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

int directionGhostWalks(int originX, int originY,
                        int *destinyX, int *destinyY);
void ghosts();
int isDirection(char direction);
void move(char direction);

int over();