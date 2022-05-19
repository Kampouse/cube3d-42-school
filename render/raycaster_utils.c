/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/19 07:50:32 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	ft_dda(t_ray *ray)
{
	ray->nb_step_x++;
	ray->nb_step_y++;
	if (ray->nb_step_x == 0 && ray->nb_step_y == 0)
	{
		ray->len++;
		ray->pos_rayx = ray->pos_rayx + ray->dx;
		ray->pos_rayy = ray->pos_rayy + ray->dy;
	}
	if (ray->nb_step_x == 0)
		ray->nb_step_x = 9999;
	if (ray->nb_step_y == 0)
		ray->nb_step_y = 9999;
	if (ray->nb_step_x <= ray->nb_step_y)
	{
		ray->len = ray->len + ray->nb_step_x;
		while (ray->nb_step_x > 0)
		{
			ray->pos_rayx = ray->pos_rayx + ray->dx;
			ray->pos_rayy = ray->pos_rayy + ray->dy;
			ray->nb_step_x--;
		}
	}
	if (ray->nb_step_y < ray->nb_step_x)
	{
		ray->len = ray->len + ray->nb_step_y;
		while (ray->nb_step_y > 0)
		{
			ray->pos_rayx = ray->pos_rayx + ray->dx;
			ray->pos_rayy = ray->pos_rayy + ray->dy;
			ray->nb_step_y--;
		}
	}
}

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

float	ft_fabs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
