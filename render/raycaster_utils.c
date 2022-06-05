/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/04 12:29:03 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	ft_what_face(t_ray *ray)
{
	if (ray->dx < 0 && ray->dy < 0)
	{
		if (ray->last_hit == 'x')
			return ('W');
		return ('N');
	}
	if (ray->dx < 0 && ray->dy > 0)
	{
		if (ray->last_hit == 'x')
			return ('W');
		return ('S');
	}
	if (ray->dx > 0 && ray->dy > 0)
	{
		if (ray->last_hit == 'x')
			return ('E');
		return ('S');
	}
	if (ray->dx > 0 && ray->dy < 0)
	{
		if (ray->last_hit == 'x')
			return ('E');
		return ('N');
	}
	return ('X');
}

void	ft_add_vertical(t_game *game, t_ray *ray, int i)
{
	const double	hauteur = (3000 / ray->len) / 2;
	uint32_t		color;
	int				offset;
	const char		c = ft_what_face(ray);

	offset = 0;
	game->last_step = ray->last_hit;
	game->last_ray = c;
	if (c == 'N')
		color = color_to_rgb(255, 255, 255, 1);
	if (c == 'E')
		color = color_to_rgb(0, 0, 255, 1);
	if (c == 'S')
		color = color_to_rgb(0, 128, 0, 1);
	if (c == 'W')
		color = color_to_rgb(255, 0, 0, 1);
	while (offset <= hauteur && (HEIGHT / 2)
		+ offset <= HEIGHT && HEIGHT / 2 - offset >= 0)
	{
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) + offset, color);
		mlx_putpixel(game->image.image, i, (HEIGHT / 2) - offset++, color);
	}
}

void	ft_dda(t_game *game, t_ray *ray)
{
	if (ray->nb_step_x == ray->nb_step_y)
	{
		if (game->last_step == 'x')
			ray->nb_step_y++;
		else
			ray->nb_step_x++;
	}
	if (ray->nb_step_x < ray->nb_step_y)
		ft_step_x(ray);
	if (ray->nb_step_y < ray->nb_step_x)
		ft_step_y(ray);
}

void	put_player_2d(t_game *game)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	pos_x = game->player->x_pos + (WIDTH / 2)
		- ((game->map_width * game->player->scale) / 2);
	pos_y = game->player->y_pos + (HEIGHT / 2)
		- ((game->map_heigth * game->player->scale) / 2);
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
