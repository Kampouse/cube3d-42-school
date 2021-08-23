#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int display_image(screen *state, int x, int y, int image) {
  const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
  void *img;
  int width;
  int height;
  img =
      mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
  mlx_put_image_to_window(state->mlx, state->win, img, x, y);
  free(img);
  return (0);
}

int close_win(int keycode, screen *state, dlist tempb) {
  int x;

  if (keycode > 0) {
    x = state->player_x;
    printf("what%d", state->player_x);
    state->player_x += 2;

    //  display_backgroud(state);
    //
    display_image(state, state->player_x, state->player_y, 0);
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
void image_type(screen *state, dlist *img) {

  if (img->type == 'P') {
    display_image(state, img->pos_x, img->pos_y, 1);
  } else if (img->type == '1')
    display_image(state, img->pos_x, img->pos_y, 1);
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
  const int width = 1000;
  const int height = 1000;
  state.mlx = mlx_init();
  state.win = mlx_new_window(state.mlx, width, height, "help");

  while (temp->next) {
    image_type(&state, temp);
    temp = temp->next;
  }
  image_type(&state, temp);
  display_image(&state, state.player_x, state.player_y, 0);
  mlx_do_sync(state.mlx);
  //
  mlx_key_hook(state.win, close_win, &state);
  mlx_hook(state.win, 2, (1L << 0), close_win, &state);
  // mlx_loop_hook(state.mlx, close_win, &state);
  mlx_loop(state.mlx);
  // 1 4 17 moving direction;
}
