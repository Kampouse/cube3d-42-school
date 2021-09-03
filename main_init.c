#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

dlist	*player_node(dlist *map)
{
	map = ft_lst_firstnode(map);
	while (map && map->type != 'P')
		map = map->next;
	return (map);
}

void	main_init(screen *state, dlist *temp)
{
	map_init(state, temp);
	state->player = temp;
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, state->screenwidth,
			state->screeheight, "help");
	state->moveY = 0;
	state->moveX = 0;
	state->collected = 0;
	state->moveCount = 0;
	state->image_state = 4;
	map_tiles(state);
	player_finder(state, 0, 0);
}

int	type_render(screen *state, char type)
{
	if (type == '1')
		return (1);
	if (type == 'C')
		return (3);
	if (type == 'E')
		return (2);
	return (0);
}

void	player_finder(screen *state, int x_axis, int y_axis)
{
	int	vert;
	int	horz;

	vert = 0;
	horz = vert;
	while (state->map[vert])
	{
		horz = 0;
		x_axis = 0;
		while (state->map[vert][horz])
		{
			x_axis += 39;
			if (state->map[vert][horz] == 'P')
			{
				y_axis = (vert * horz) * 56;
				state->locationX = horz;
				state->locationY = vert;
				state->x_pos = x_axis;
				state->y_pos = y_axis - 20;
				return ;
			}
			horz++;
		}
		vert++;
	}
}
