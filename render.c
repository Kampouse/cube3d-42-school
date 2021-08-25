#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_image(screen *state, int x, int y, int image) {
  mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  return (0);
}

int type_render(screen *state, char type, int pos_x, int pos_y) {

  if (type == '1') {
    return (1);
  }
  if (type == 'P') {
    state->x_pos = pos_x;
    state->y_pos = pos_y;
  }
  return (1);
}

void render_tiles(screen *state, int x_axis, int y_axis) {
  char **ray;
  int inc, cin;

  inc = 0;
  cin = 0;
  ray = state->map;
  while (ray[inc]) {
    cin = 0;
    x_axis = 0;
    while (ray[inc][cin]) {
      render_image(state, x_axis, y_axis,
                   type_render(state, ray[inc][cin], x_axis, y_axis));

      x_axis += 50;
      cin++;
    }
    y_axis += 50;
    inc++;
  }

  render_image(state, state->x_pos, state->y_pos, 0);
}
