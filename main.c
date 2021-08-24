#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_cycle(int keycode, screen *state) {
  int x;
  x = state->player_x;
  if (keycode > 0) {
    printf("%c", state->player->type);

    //    render_background(state, state->player);
    // render_image(state, state->player_x, state->player_y, 0);
    state->player_x += 2;
  }
  if (keycode == 257) {
    printf("session destroyed");
    mlx_destroy_window(state->mlx, state->win);
    exit(0);
  }

  return (0);
}
void print_content(char content) { printf("%c \n", content); }
dlist *mapcreator(fd) {
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
int verif(dlist map) {
  int flag;
  flag = 0;
  // should i do an error for each?
  flag += verif_len(map);
  flag += verif_wall(map);
  flag += verif_param(map, 'P');
  flag += verif_param(map, 'E');
  flag += verif_param(map, 'C');
  flag += verif_map_content(map);
  return (flag);
}

dlist *player_node(dlist *map) {
  map = ft_lst_firstnode(map);
  while (map->next) {

    if (map->type == 'P') {
      return (map);
    }
    map = map->next;
  }
  if (map->type == 'P')
    return (map);
  return (map);
}

int main(void) {

  dlist map;
  screen state;
  dlist *temp;
  int fd;

  fd = open("./assets/map.ber", O_RDONLY);
  if (fd < 0) {
    printf("map could not be initiated");
    exit(-1);
  }
  map = *mapcreator(fd);
  if (verif(map)) {
    ft_lstiterd(&map, free);
    ft_cleardlist(&temp, free);
    printf("error as occured");
  }
  map = *tile_all(&map);
  state.player = player_node(&map);
  // printf("(type = %d %d)", tempb->pos_x, tempb->pos_y);
  //
  // tiles = render_imageStore(&state);
  // ft_clearnode(temp, free);
  state.player_x = state.player->pos_x;
  state.player_y = state.player->pos_y;

  const int width = 690;
  const int height = 190;

  state.mlx = mlx_init();
  state.win = mlx_new_window(state.mlx, width, height, "help");
  state.tiles = NULL;
  render_imageStore(&state);
  render_background(&state, &map);
  mlx_key_hook(state.win, render_cycle, &state);
  mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
  mlx_loop_hook(state.mlx, render_player, &state);
  mlx_loop(state.mlx);
}
