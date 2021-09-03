#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void	free_list(dlist *head)
{
	dlist	*next;

	if (head != NULL)
	{
		next = head->next;
		free(head->content);
		free(head);
		free_list(next);
	}
}

void	freeray(screen *ray)
{
	int	inc;

	free_list(ft_lst_firstnode(ray->player));
	inc = -1;
	while (ray->tiles[++inc])
		mlx_destroy_image(ray->mlx, ray->tiles[inc]);
	free(ray->tiles);
}

int	render_cycle(int keycode, screen *state)
{
	play_contact(state);
	if (keycode >= 0)
	{
		play_vert(state, keycode);
		play_horz(state, keycode);
	}
	if (keycode == ESC)
	{
		printf("session destroyed");
		mlx_destroy_window(state->mlx, state->win);
		freeray(state);
		exit(0);
	}
	return (0);
}

int	verif(dlist map)
{
	int	flag;

	flag = 0;
	flag += verif_len(map);
	flag += verif_wall(map);
	flag += verif_param(map, 'P');
	flag += verif_param(map, 'E');
	flag += verif_param(map, 'C');
	flag += verif_map_content(map);
	return (flag);
}

int	main(void)
{
	screen	state;
	dlist	*temp;
	int		fd;

	fd = open("./assets/map.ber", O_RDONLY);
	if (fd < 0)
	{
		printf("map could not be initiated");
		exit(-1);
	}
	temp = mapcreator(fd);
	main_init(&state, temp);
	if (verif(*temp) > 0)
	{
		free_list(temp);
		perror("your map is wrong");
		exit(0);
	}
	mlx_loop_hook(state.mlx, render_player, &state);
	mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
	mlx_loop(state.mlx);
}
