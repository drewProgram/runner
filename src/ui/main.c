#include <stdio.h>
#include <stdlib.h>

#include "../headers/map.h"
#include "../headers/ui.h"

char ghostSprite[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char wallSprite[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char runnerSprite[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char pillSprite[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char voidSprite[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};


void drawPart(char drawing[4][7], int part) {
  printf("%s", drawing[part]);
}

void drawMap(MAP *m)
{
  for (int i = 0; i < m->lines; i++)
  {
    for (int part = 0; part < 4; part++) {
      for (int j = 0; j < m->columns; j++) {
        switch (m->matrix[i][j])
        {
        case GHOST:
          drawPart(ghostSprite, part);
          break;
        case RUNNER:
          drawPart(runnerSprite, part);
          break;
        case PILL:
          drawPart(pillSprite, part);
          break;
        case HORIZONTAL_WALL1:
        case HORIZONTAL_WALL2:
        case VERTICAL_WALL:
          drawPart(wallSprite, part);
          break;

        case VOID:
          drawPart(voidSprite, part);
          break;
        }
      }
      printf("\n");
    }
  }
}