/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:09 by jemartel          #+#    #+#             */
/*   Updated: 2021/09/05 11:21:48 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "mlx/mlx.h"

void	play_contact(t_screen *state)
{
	if (state->map[state->locationy][state->locationx] == 'C')
	{
		state->map[state->locationy][state->locationx] = '0';
	}
	if (state->map[state->locationy][state->locationx] == 'E'
		&& ft_count_all(state->map, 'C') == 0)
	{
		printf("won");
		exit(0);
	}
}

void	play_right(t_screen *state, int keycode)
{
	if (keycode == RIGHT)
	{
		if (state->image_state >= 8 && state->image_state < 13)
		{
			state->image_state++;
		}
		else
		{
			state->image_state = 10;
		}
	}
}

void	play_left(t_screen *state, int keycode)
{
	if (keycode == LEFT)
	{
		if (state->image_state > 4 && state->image_state < 8)
		{
			state->image_state++;
		}
		else
		{
			state->image_state = 5;
		}
	}
}

void	play_horz(t_screen *state, int keycode)
	{
	play_left(state, keycode);
	play_right(state, keycode);
	if (keycode == LEFT && state->map[state->locationy]
		[state->locationx - 1] != '1' && state->move_x >= -33)
	{
		state->move_x -= 88;
		state->locationx -= 1;
		state->movecount++;
		ft_putnbr_fd(state->movecount, 1);
	}
	if (keycode == RIGHT && state->map[state->locationy]
		[state->locationx + 1] != '1' && state->move_x <= 33)
	{
		state->move_x += 88;
		state->locationx += 1;
		state->movecount++;
		ft_putnbr_fd(state->movecount, 1);
	}
}

void	play_vert(t_screen *state, int keycode)
{
	if (keycode == UP && state->map[state->locationy - 1]
		[state->locationx] != '1' && state->move_y > -23)
	{
		state->locationy -= 1;
		state->move_y -= 56;
		state->movecount++;
		ft_putnbr_fd(state->movecount, 1);
	}
	if (keycode == DOWN && state->map[state->locationy + 1]
		[state->locationx] != '1' && state->move_y < 23)
	{
		state->locationy += 1;
		state->move_y += 56;
		state->movecount++;
		ft_putnbr_fd(state->movecount, 0);
	}
}
