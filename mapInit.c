#include "solong.h"
#include "stdio.h"
#include "stdlib.h"

dlist *node_tiles(char content, int x, int y) {
  dlist *link;
  link = (dlist *)malloc(sizeof(*link));
  if (!link)
    return (NULL);
  link->content = &content;
  link->prev = NULL;
  link->next = NULL;
  link->content = NULL;
  return (link);
}
int tile_row(dlist *map) {
  char *iterator;
  dlist *tiles;
  int inc;

  inc = 0;
  tiles = NULL;
  iterator = (char *)map->content;
  while (iterator[inc]) {
    // init nde and add them to the back...
    printf("(%c)", iterator[inc]);
    inc++;
  }
  return 0;
}
