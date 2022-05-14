/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_tonyg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/14 14:23:48 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	put_player_2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			mlx_putpixel(game->image.image, game->player->x_pos + x, game->player->y_pos + y, 0XEBF00B);
			y++;
		}
		x++;
	}
}

int	cast_ray(t_game *game, t_image image, t_ray ray)
{
	int		length;

	length = 0;
	return (length);
}
