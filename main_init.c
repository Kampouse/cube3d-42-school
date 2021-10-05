/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2021/10/05 13:03:20 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void	main_init(t_screen *state, t_dlist *temp)
{
	map_init(state, temp);
	state->player = temp;
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, state->screenwidth,
			state->screeheight, "./so_long");
	state->move_y = 0;
	state->move_x = 0;
	state->movecount = 0;
	state->image_state = 4;
	map_tiles(state);
	player_finder(state, 0, 0);
}

int	type_render(t_screen *state, char type)
{
	if (type == '1')
		return (1);
	if (type == 'C')
		return (3);
	if (type == 'E')
		return (2);
	return (0);
}

void	player_finder(t_screen *state, int x_axis, int y_axis)
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
			x_axis += vert;
			if (state->map[vert][horz] == 'P')
			{
				state->locationx = horz;
				state->locationy = vert;
				state->x_pos = (80 * horz) + horz;
				state->y_pos = y_axis;
				return ;
			}
			horz++;
		}
		y_axis += 54;
		vert++;
	}
}

int	exit_please(t_screen *state)
{
	mlx_destroy_window(state->mlx, state->win);
	exit(0);
	return (0);
}

char	freelist(char **list)
{
	int	inc;

	inc = 0;
	while (list[inc])
	{
		free(list[inc]);
		inc++;
	}
	return (0);
}
