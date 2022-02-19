/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/19 12:46:05 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
void	main_init(t_screen *state, t_dlist *temp)
{
	map_init( temp);
	state->player = temp;
	//state->mlx = mlx_init();
	//state->win = mlx_new_window(state->mlx, state->screenwidth,
		//	state->screeheight, "./cube42");
	state->move_y = 0;
	state->move_x = 0;
	state->movecount = 0;
	state->image_state = 4;
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
	free(list);
	return (0);
}
