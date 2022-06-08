/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/08 13:45:54 by jemartel         ###   ########.fr       */
/*   Updated: 2022/06/06 14:20:52 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

uint32_t	color_to_rgb(uint32_t r, uint32_t g, uint32_t b)
{
	return (0xFF | (r << 8) | g << 16 | (b << 24));
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
