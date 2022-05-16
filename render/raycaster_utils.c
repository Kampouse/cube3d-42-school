/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/16 12:46:21 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	put_player_2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			mlx_putpixel(game->image.image, game->player->x_pos + x, game->player->y_pos + y, 0XEBF00B);
			mlx_putpixel(game->image.image, game->player->x_pos - x, game->player->y_pos + y, 0XEBF00B);
			mlx_putpixel(game->image.image, game->player->x_pos + x, game->player->y_pos - y, 0XEBF00B);
			mlx_putpixel(game->image.image, game->player->x_pos - x, game->player->y_pos - y, 0XEBF00B);
			y++;
		}
		x++;
	}
}
