#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_image(screen *state, int x, int y, int image) {
  mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  return (0);
}

void render_tiles(screen *state) {
  char **ray;
  int inc, cin;
  inc = 0;
  cin = 0;
  ray = state->map;
  while (ray[inc]) {
    cin = 0;
    while (ray[inc][cin]) {
      printf("%c", ray[inc][cin]);
      cin++;
    }

    printf("\n");
    inc++;
  }
}
