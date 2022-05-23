/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/23 09:57:58 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

// uint32_t	ft_what_face(t_game *game, t_ray *ray, int i)
// {
// 	(void)game;
// 	printf("Ray %d = (%f, %f)\n", i, ray->pos_rayx, ray->pos_rayy);
// 	return ('c');
// }

void	ft_add_vertical(t_game *game, t_ray *ray, int i)
{
	const float	hauteur = (3000 / ray->len) / 2;
	int			offset;

	offset = 0;
	// ft_what_face(game, ray, i);
	while (offset < hauteur && (HEIGHT / 2) + offset < HEIGHT && HEIGHT / 2 - offset >= 0)
	{
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) + offset, 0XEBF00B);
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) - offset++, 0XEBF00B);
	}
}

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
	int	pos_x;
	int	pos_y;

	pos_x = game->player->x_pos + (WIDTH / 2) - ((game->map_width * game->player->scale) / 2);
	pos_y = game->player->y_pos + (HEIGHT / 2) - ((game->map_heigth * game->player->scale) / 2);
	y = 0;
	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			mlx_putpixel(game->image.image, pos_x + x, pos_y + y, 0XEBF00B);
			mlx_putpixel(game->image.image, pos_x - x, pos_y + y, 0XEBF00B);
			mlx_putpixel(game->image.image, pos_x + x, pos_y - y, 0XEBF00B);
			mlx_putpixel(game->image.image, pos_x - x, pos_y - y, 0XEBF00B);
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
