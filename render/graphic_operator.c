/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 18:06:01 by jemartel         ###   ########.fr       */
/*   Updated: 2022/06/06 14:20:52 by aguay            ###   ########.fr       */
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
