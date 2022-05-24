/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_operator2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/24 10:40:52 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	paint_in_black(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			mlx_putpixel(game->image.image, x, y++, color_to_rgb(0, 0, 0,0));
		x++;
	}
}

void	initialise_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
			mlx_putpixel(game->image.image, x, y++, 0xFFFF);
		while (y < HEIGHT)
			mlx_putpixel(game->image.image, x, y++, 0x0000);
		x++;
	}
}

void	fix_it_hihi(t_game *game)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
		mlx_putpixel(game->image.image, 0, y++, 0x000000);
}