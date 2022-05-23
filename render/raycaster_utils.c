/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/23 15:36:56 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

int	ft_what_pos(float x)
{
	int	retour;

	retour = 0;
	while (x >= 0)
	{
		retour++;
		x--;
	}
	return (retour);
}

char	ft_what_face(t_game *game, t_ray *ray)
{
	int	pos_x;
	int	pos_y;
	int	scale;

	scale = game->player->scale;
	pos_x = ft_what_pos(ray->pos_rayx);
	pos_y = ft_what_pos(ray->pos_rayy);
	if (ray->dx < 0 && ray->dy < 0)	// entre Nort et West
	{
		return ('N');
	}
	if (ray->dx < 0 && ray->dy > 0) // entre West et Sud
	{
		return ('W');
	}
	if (ray->dx > 0 && ray->dy > 0) // entre Sud et East
	{
		return ('S');
	}
	if (ray->dx > 0 && ray->dy < 0) // entre East et Nord
	{
		return ('E');
	}
	return ('X');
}

void	ft_add_vertical(t_game *game, t_ray *ray, int i)
{
	const float	hauteur = (3000 / ray->len) / 2;
	uint32_t	color;
	int			offset;
	char		c = ft_what_face(game, ray);

	offset = 0;
	if (c == 'N')
		color = color_to_rgb(1, 0, 0, 100);
	if (c == 'E')
		color = color_to_rgb(1, 0, 100, 0);
	if (c == 'S')
		color = color_to_rgb(1, 100, 0, 0);
	if (c == 'w')
		color = color_to_rgb(1, 100, 100, 100);
	while (offset <= hauteur && (HEIGHT / 2) + offset <= HEIGHT && HEIGHT / 2 - offset >= 0)
	{
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) + offset, color);
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) - offset++, color);
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
