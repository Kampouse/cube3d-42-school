#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void freeray(screen *ray)
{
	int inc;
	inc = 0;
while(ray->map[inc])
	{
	free(ray->map[inc]);
	inc++;
	}
	mlx_destroy_image(ray->mlx,ray->tiles[0]);
	mlx_destroy_image(ray->mlx,ray->tiles[1]);
	free(ray->tiles);
}

int render_cycle(int keycode, screen *state) {

  if (keycode >= 0) {
  //  render_tiles(state, 0, 0);
   // render_player(state);
	//play_horz(state,keycode);
	play_vert(state,keycode);
	play_horz(state,keycode);
  }
  if (keycode == 257) {
    printf("session destroyed");
    mlx_destroy_window(state->mlx, state->win);
	freeray(state);
    exit(0);
  }

  return (0);
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
  //sleep(1);
  const int width = 800;
  const int height = 800;
  state.mlx = mlx_init();

  state.win = mlx_new_window(state.mlx, width, height, "help");
  //mlx_put_image_to_window(state.mlx, state.win, state.tiles[1], 0, 0);
  map_tiles(&state);
  player_finder(&state, 0, 0);
//  render_tiles(&state, 0, 0);


  mlx_loop_hook(state.mlx, render_player, &state);
  mlx_key_hook(state.win, render_cycle, &state);
  mlx_loop(state.mlx);
  // mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
}
