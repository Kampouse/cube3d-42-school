#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_image(screen *state, int x, int y, int image) {
  mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  return (0);
}

int type_render(char type) {

  if (type == '1') {
    return (0);
  }
  return (0);
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
      render_image(state, x_axis, y_axis, type_render(ray[inc][cin]));
      x_axis += 50;
      cin++;
    }
    y_axis += 50;
    inc++;
  }
}
