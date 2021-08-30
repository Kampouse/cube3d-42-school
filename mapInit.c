#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/libft/libft.h"
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
  const char images[14][35] = { 
		"./assets/floor.xpm",
		"./assets/back.xpm","./assets/door.xpm", "./assets/doll3.xpm",
		"./assets/player/walk1_0.xpm", "./assets/player/walk1_1.xpm",
		"./assets/player/walk1_2.xpm", "./assets/player/walk1_3.xpm",
		"./assets/player/walk1_4.xpm", "./assets/player/walk1_0rp.xpm",
		"./assets/player/walk1_1rp.xpm",
		"./assets/player/walk1_2rp.xpm", 
		"./assets/player/walk1_3rp.xpm",  
		"./assets/player/walk1_4rp.xpm"};
  int inc,width,height;
  int *dog;

	inc = -1;
  state->tiles = malloc(sizeof(void *) * 15);
  while (*images[++inc]) 
	{

    state->tiles[inc] = mlx_xpm_file_to_image(state->mlx, (void *)images[inc], &width, &height);
	dog = &width;
	}
	  state->tiles[inc] = 0;
}

