/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:26 by jemartel          #+#    #+#             */
/*   Updated: 2021/09/03 23:28:03 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int	render_image(t_screen *state, int x, int y, int image)
{
	mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
	return (0);
}

int	rend_dec(t_screen *state)
{
	  if (state->move_x > 0)
	{
		state->move_x -= 11;
		state->x_pos += 11;
	}
	if (state->move_x < 0)
	{
		state->move_x += 11;
		state->x_pos -= 11;
	}
	if (state->move_y > 0)
	{
		state->move_y -= 10;
		state->y_pos += 10;
	}
	if (state->move_y < 0)
	{
		state->move_y += 10;
		state->y_pos -= 10;
	}
	return (render_walk(state));
}

int	render_player(t_screen *state)
{
	rend_dec(state);
	render_tiles(state, 0, 0);
	render_image(state, state->x_pos, state->y_pos, state->image_state);
	return (0);
}

int	render_walk(t_screen *state)
{
	static int	image_state;

	if (state->move_x != 0)
		image_state++;
	if (image_state == 9)
		image_state = 6;
	return (image_state);
}

int	render_tiles(t_screen *state, int x_axis, int y_axis)
{
	int	inc;
	int	cin;

	inc = 0;
	cin = 0;
	while (state->map[inc])
	{
		cin = 0;
		x_axis = 0;
		while (state->map[inc][cin])
		{
			render_image(state, x_axis, y_axis,
				type_render(state, state->map[inc][cin]));
			x_axis += 89;
			cin++;
		}
		y_axis += 56;
		inc++;
	}
	return (0);
}
