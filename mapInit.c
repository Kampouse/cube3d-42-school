#include "solong.h"
#include "stdio.h"
#include "stdlib.h"

dlist *node_tiles(char content, int x, int y) {
  dlist *link;
  link = (dlist *)malloc(sizeof(*link));
  if (!link)
    return (NULL);
  link->type = content;
  link->pos_x = x;
  link->pos_y = y;
  link->prev = NULL;
  link->next = NULL;
  link->content = NULL;
  return (link);
}
dlist *tile_row(dlist *map, int y) {
  char *iterator;
  dlist *tiles;
  int inc, x;

  inc = 0;
  x = 0;
  tiles = NULL;
  iterator = (char *)map->content;

  while (iterator[inc]) {
    ft_lst_add_backd(&tiles, node_tiles(iterator[inc], x += 5, y));
    inc++;
  }
  return tiles;
}

dlist *tile_all(dlist *map) {
  dlist *mapList;
  mapList = NULL;
  int y;
  y = 0;
  while (map->next) {
    ft_lst_add_backd(&mapList, tile_row(map, y));
    y++;
    map = map->next;
  }
  ft_lst_add_backd(&mapList, tile_row(map, y));
  return (mapList);
}
