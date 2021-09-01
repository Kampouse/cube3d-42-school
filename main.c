#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void freeray(screen *ray)
{
	int inc;

	ft_cleardlist(&ray->player,free);
	free(ray->map);
inc = 0;
while(ray->tiles[inc])
	{
	mlx_destroy_image(ray->mlx,ray->tiles[inc]);
	printf("destroyed %d",inc);
	inc++;
	}
	free(ray->tiles);
}

int render_cycle(int keycode, screen *state) 
{

play_contact(state);
  if (keycode >= 0) 
	{
	play_vert(state,keycode);
	play_horz(state,keycode);
  }
  if (keycode == 257) 
{
    printf("session destroyed");
    mlx_destroy_window(state->mlx, state->win);
	freeray(state);
    exit(0);

  }
  return (0);
}

int verif(dlist map) 
{
  int flag;
  flag = 0;
  flag += verif_len(map);
  flag += verif_wall(map);
  flag += verif_param(map, 'P');
  flag += verif_param(map, 'E');
  flag += verif_param(map, 'C');
  flag += verif_map_content(map);
  return (flag);
}

dlist *player_node(dlist *map) 
{
  map = ft_lst_firstnode(map);
  while (map && map->type != 'P') 
    map = map->next;
  return (map);
}

int main(void) 
{

  screen state;
  dlist *temp;
  int fd;

  fd = open("./assets/map.ber", O_RDONLY);
  if (fd < 0) 
	{
    printf("map could not be initiated");
    exit(-1);
  }
  temp = mapcreator(fd);
if(verif(*temp) > 0)
	{
	printf("error");
	exit(0);
	}
  map_init(&state, temp);
  close(fd);
  state.player = temp;
  state.mlx = mlx_init();
  state.win = mlx_new_window(state.mlx, state.screenwidth, state.screeheight, "help");
  state.moveY = 0;
  state.moveX = 0;
  state.collected = 0;
  state.moveCount = 0;
  state.image_state = 4;
  map_tiles(&state);
  player_finder(&state, 0, 0);
  mlx_loop_hook(state.mlx, render_player, &state);
  mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
  mlx_loop(state.mlx);
}
