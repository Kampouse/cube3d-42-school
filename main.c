#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"
void render_background(screen *state, dlist *map);
int render_image(screen *state, int x, int y, int image) {
  const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
  void *img;
  int width;
  int height;
  img =
      mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
  mlx_put_image_to_window(state->mlx, state->win, img, x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  // free(img);
  return (0);
}
int render_player(screen *state, dlist *map) {
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

void render_background(screen *state, dlist *map) {
  while (map->next) {
    image_type(state, map);
    map = map->next;
  }
  image_type(state, map);
}
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
  dlist *tempb;
  int fd;

  fd = open("./assets/map.ber", O_RDONLY);
  if (fd < 0) {
    printf("map could not be initiated");
    exit(-1);
  }
  map = *mapcreator(fd);
  temp = &map;
  if (verif(map)) {
    ft_lstiterd(temp, free);
    ft_cleardlist(&temp, free);
    printf("error as occured");
  }
  temp = tile_all(&map);
  tempb = player_node(temp);
  printf("(type = %d %d)", tempb->pos_x, tempb->pos_y);
  // ft_clearnode(temp, free);
  state.player_x = tempb->pos_x;
  state.player_y = tempb->pos_y;
  state.player = tempb;
  const int width = 690;
  const int height = 190;
  state.mlx = mlx_init();
  state.win = mlx_new_window(state.mlx, width, height, "help");
  render_background(&state, temp);
  // render_image(&state, state.player_x, state.player_y, 0);
  mlx_key_hook(state.win, render_cycle, &state);
  mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
  mlx_loop_hook(state.mlx, render_player, &state);
  mlx_loop(state.mlx);
  // 1 4 17 moving direction;
}
