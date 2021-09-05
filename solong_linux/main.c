/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:37:17 by jemartel          #+#    #+#             */
/*   Updated: 2021/09/05 11:20:48 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "./mlx/mlx.h"

void	free_list(t_dlist *head)
{
	t_dlist	*next;

	if (head != NULL)
	{
		next = head->next;
		free(head->content);
		free(head);
		free_list(next);
	}
}

void	freeray(t_screen *ray)
{
	int	inc;

	inc = -1;
	while (ray->tiles[++inc])
		mlx_destroy_image(ray->mlx, ray->tiles[inc]);
	free(ray->tiles);
	free_list(ray->player);
}

int	render_cycle(int keycode, t_screen *state)
{
	play_contact(state);
	if (keycode >= 0)
	{
		play_vert(state, keycode);
		play_horz(state, keycode);
	}
	if (keycode == ESC)
	{
		freeray(state);
		mlx_destroy_window(state->mlx, state->win);
		exit(0);
	}
	return (0);
}

t_dlist	*verif(t_dlist *map)
{
	int	flag;

	flag = 0;
	if (!map)
	{
		ft_putstr_fd("Error:could not read map\n", 1);
		exit(0);
	}
	flag += assert(verif_len(*map), "Error: len incorrect\n");
	flag += assert(verif_wall(*map), "Error: incorrect wall\n");
	flag += assert(verif_param(*map, 'P'), "Error: wrong number of Player\n");
	flag += assert(verif_param(*map, 'E'), "Error: wrong number of exit\n");
	flag += assert(verif_param(*map, 'C'), "Error: wrong nbr of collectibe\n");
	flag += assert(verif_map_content(*map), "Error: wrong element in the map\n");
	if (flag > 0)
	{
		free_list(map);
		exit(0);
	}
	return (map);
}

int	main(int argc, char *argv[])
{
	t_screen	state;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	main_init(&state, verif(mapcreator(fd)));
	mlx_loop_hook(state.mlx, render_player, &state);
	mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
	mlx_do_sync(state.mlx);
	mlx_loop(state.mlx);
}
