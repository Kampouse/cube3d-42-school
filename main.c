#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_cycle(int keycode, screen *state) {

  if (keycode > 0) {

    render_tiles(state, 0, 0);
    render_player(state);
    state->x_pos += 50;
  }
  if (keycode == 257) {
    printf("session destroyed");
    mlx_destroy_window(state->mlx, state->win);
    exit(0);
  }

  return (0);
}
void print_content(char content) { printf("%c \n", content); }

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

  screen state;
  dlist *temp;
  int fd;

  fd = open("./assets/map.ber", O_RDONLY);
  if (fd < 0) {
    printf("map could not be initiated");
    exit(-1);
  }

  temp = mapcreator(fd);
  map_init(&state, temp);

  const int width = 690;
  const int height = 190;

  state.mlx = mlx_init();
  map_tiles(&state);

  state.win = mlx_new_window(state.mlx, width, height, "help");
  mlx_put_image_to_window(state.mlx, state.win, state.tiles[1], 0, 0);
  player_finder(&state, 0, 0);
  render_tiles(&state, 0, 0);

  mlx_key_hook(state.win, render_cycle, &state);

  mlx_loop_hook(state.mlx, render_player, &state);
  mlx_loop(state.mlx);
  // mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
}
