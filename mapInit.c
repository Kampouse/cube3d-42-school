#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/minilibx/mlx.h"

dlist *mapcreator(int fd) {
  dlist *list;
  list = NULL;
  char *str;
  get_next_line(fd, &str);
  ft_lst_add_backd(&list, node_init(str));
  while (get_next_line(fd, &str))
    ft_lst_add_backd(&list, node_init(str));
  list = ft_lst_firstnode(list);
  return (list);
}

void map_init(screen *state, dlist *map) {
  int len;
  len = ft_lst_lenght(map);
  state->map = malloc(sizeof(char *) * len + 1);
  state->map[len] = 0;
  len = 0;
  while (map) {
    state->map[len] = map->content;
    len++;
    map = map->next;
  }
}

void map_tiles(screen *state) {
  const char images[][30] = {"./assets/player.xpm", "./assets/floor.xpm"};
  int inc;
  int val;
  val =0;
	inc = 0;
  state->tiles = malloc(sizeof(void *) * 3);
  // this will either would nead to either to set in the global state of the
  // screen or malloced
  int width;
  int height;
  while (*images[inc]) {
    state->tiles[inc] = mlx_xpm_file_to_image(state->mlx, (char *)images[inc], &width, &height);
    inc++;
  }
}
