#include "solong.h"
#include "utils/libft/libft.h"

#include "utils/minilibx/mlx.h"

void render_background(screen *state, dlist *map);

void render_background(screen *state, dlist *map) {
  while (map->next) {
    image_type(state, map);
    map = map->next;
  }
  image_type(state, map);
}
int render_image(screen *state, int x, int y, int image) {
  const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
  void *img;
  int width;
  int height;
  img =
      mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
  mlx_put_image_to_window(state->mlx, state->win, img, x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  free(img);
  return (0);
}
int render_player(screen *state, void *player) {
  int len;
  len = 50;
  render_image(state, state->player_x, state->player_y, 0);
  render_background(state, state->player);
  render_image(state, state->player_x + len, state->player_y, 0);
  return (0);
}

void image_type(screen *state, dlist *img) {

  if (img->type == 'P') {
    render_image(state, img->pos_x, img->pos_y, 1);
  } else if (img->type == '1')
    render_image(state, img->pos_x, img->pos_y, 1);
}

void render_imageStore(screen *state) {
  const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
  int inc;
  inc = 0;
  state->tiles = malloc(sizeof(void *) * 3);
  state->tiles[2] = 0;
  // this will either would nead to either to set in the global state of the
  // screen or malloced
  int width;
  int height;
  while (*images[inc]) {
    state->tiles[inc] =
        mlx_xpm_file_to_image(state->mlx, (char *)images[inc], &width, &height);
    inc++;
  }
}
int render_some(screen *state, int x, int y, void **elem) {
  mlx_put_image_to_window(state->mlx, state->win, state->tiles[0], x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  return (0);
}
