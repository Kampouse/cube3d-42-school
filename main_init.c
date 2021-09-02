#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void main_init(screen *state ,dlist *temp)
{
  map_init(state, temp);
  state->player = temp;
  state->mlx = mlx_init();
  state->win = mlx_new_window(state->mlx, state->screenwidth, state->screeheight, "help");
  state->moveY = 0;
  state->moveX = 0;
  state->collected = 0;
  state->moveCount = 0;
  state->image_state = 4;
  map_tiles(state);
  player_finder(state, 0, 0);
}

