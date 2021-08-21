#include "get_next_line.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "solong.h"
#include "stdio.h"
#include "stdlib.h"

int display_image(screen *state, int x, int y, int image) {
  const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
  void *img;
  int width;
  int height;
  img =
      mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
  //
  mlx_put_image_to_window(state->mlx, state->win, img, x, y);
  free(img);
  return (0);
}

int display_backgroud(screen *state) {
  int j;
  int i;
  j = 0;
  i = 0;
  while (j < 1080) {
    while (i < 1900) {
      //  display_image(state, i, j, 1);
      i += 89;
    }
    i = 0;
    j += 55;
  }
  return (0);
}

int close_win(int keycode, screen *state) {
  int x;

  if (keycode > 0) {
    state->player_x += 2;
    x = state->player_x;
    // display_backgroud(state);
    // display_image(state, x, 0, 0);
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
int image_type(char type) {
  if (type == 'P')
    return (0);
  else if (type == '1')
    return (1);
  return (0);
}
int main(void) {

  dlist map;
  screen state;
  dlist *temp;
  int fd;

  fd = open("./map.ber", O_RDONLY);
  map = *mapcreator(fd);
  temp = &map;
  if (verif(map)) {
    ft_lstiterd(temp, free);
    ft_cleardlist(&temp, free);
    printf("error as occured");
  }
  temp = tile_all(&map);
  // ft_clearnode(temp, free);

  const int width = 1000;
  const int height = 1000;

  state.mlx = mlx_init();
  state.win = mlx_new_window(state.mlx, width, height, "help");
  while (temp->next) {
    display_image(&state, temp->pos_x, temp->pos_y, image_type(temp->type));
    temp = temp->next;
  }

  mlx_key_hook(state.win, close_win, &state);
  // mlx_loop_hook(state.mlx, close_win, &state);
  mlx_loop(state.mlx);
  // 1 4 17 moving direction;
}
