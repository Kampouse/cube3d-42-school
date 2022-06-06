/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 13:28:06 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

uint32_t	color_to_rgb(int a, int r, int g, int b)
{
	uint32_t	color;
	const int	ra = r & 0xFF;
	const int	ga = g & 0xFF;
	const int	ba = b & 0xFF;
	const int	aa = a & 0xFF;

	(void) aa;
		color = 0xFF | (ra << 8) | (ga << 16) | (ba << 24);
	return (color);
}

int	square_shape(t_image *image, int x_pos, int y_pos, uint32_t color)
{
	int	inc;
	int	cin;

	inc = 0;
	cin = 0;
	while (cin < 12)
	{
		while (inc < 12)
		{
			mlx_putpixel(image->image, x_pos + inc, y_pos + cin, color);
			inc++;
		}
		inc = 0;
		cin++;
	}
	return (0);
}

void	draw_map(t_game *state, t_image image, int scale)
{
	int	inc;
	int	cin;
	int	stepx;
	int	stepy;

	paint_in_black(state);
	inc = 0;
	cin = 0;
	stepx = (WIDTH / 2) - ((state->map_width * scale) / 2);
	stepy = (HEIGHT / 2) - ((state->map_heigth * scale) / 2);
	while (state->map[cin])
	{
		while (state->map[cin][inc])
		{
			if (state->map[cin][inc] == '1')
				square_shape(&image, stepx, stepy, color_to_rgb(0, 0, 0, 0));
			else
				square_shape(&image, stepx, stepy, color_to_rgb(0, 0, 255, 0));
			inc++;
			stepx += scale;
		}
		stepx = (WIDTH / 2) - ((state->map_width * scale) / 2);
		inc = 0;
		stepy += scale;
		cin++;
	}
}
