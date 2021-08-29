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

void map_init(screen *state, dlist *map) 
{
  int len;
  len = ft_lst_lenght(map);
  state->map = malloc(sizeof(char *) * len);
  state->map[len] = 0;
  len = 0;
  while (map) 
	{
    state->map[len] = map->content;
    len++;
    map = map->next;
	}
}

void map_tiles(screen *state) 
{
  const char images[6][35] = {"./assets/player.xpm", "./assets/floor.xpm","./assets/clear.xpm",
		"./assets/back.xpm","./assets/door.xpm", "./assets/doll3.xpm"};
  int inc,width,height;

	inc = -1;
  state->tiles = malloc(sizeof(void *) * 7);
  while (*images[++inc]) 
    state->tiles[inc] = mlx_xpm_file_to_image(state->mlx, (char *)images[inc], &width, &height);
  state->tiles[inc] = 0;
}
