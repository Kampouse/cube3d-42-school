/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_tonyg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/16 11:37:44 by aguay            ###   ########.fr       */
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

// Every time the ray reach an intersection of case, verify if
// there is collision. If there is (wich must), change the image
// pixel to show in 3d with the good color (with the wall facing
// what direction. return the length of the ray after that.
int	cast_ray2(t_game *game)
{
	int	length = 0;
	game->ray->delta_y = cos(game->ray->angle) / 1;
	game->ray->delta_x = sin(game->ray->angle);
	game->ray->dx = cos(degToRad(game->ray->angle)) * game->ray->delta_x -  sin(degToRad(game->ray->angle)) * game->ray->delta_y;
	game->ray->dy = sin(degToRad(game->ray->angle)) * game->ray->delta_x + cos(degToRad(game->ray->angle)) * game->ray->delta_y;
	show_player_info(game);
	printf("delta_y\t\t= %f\n", game->ray->delta_y);
	printf("delta_x\t\t= %f\n", game->ray->delta_x);
	printf("dx\t\t= %f\n", game->ray->dx);
	printf("dy\t\t= %f\n", game->ray->dy);
	printf("angle\t\t= %f\n", game->ray->angle);
	printf("silence image and game %d %d\n\n", game->image.endian, game->image_state);
	return (length);
}
