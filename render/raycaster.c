/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/01 14:29:14 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Include/cube.h"

float	ft_fabs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	raycaster2d(t_game *game, t_ray *ray, int i)
{
	float	next_case;

	ray->len = 0;
	next_case = 0;
	ray->dy = cos(ray->angle);
	ray->dx = sin(ray->angle);
	ray->pos_rayx = game->player->x_pos;
	ray->pos_rayy = game->player->y_pos;
	if (i == WIDTH / 2)
	{
		game->player->dx = ray->dx;
		game->player->dy = ray->dy;
	}
	ray->last_cordy = (int)(game->player->y_pos + (ray->dy * ray->len)) / game->player->scale;
	ray->last_cordx  = (int)(game->player->x_pos + (ray->dx * ray->len)) / game->player->scale;
	while (game->map[ray->last_cordy][ray->last_cordx] != '1')
	{
		ray->map_rayx = (ray->pos_rayx / game->player->scale) + 1;
		ray->map_rayy = (ray->pos_rayy / game->player->scale) + 1;
		if (ray->dx < 0)
		{
			next_case = (ray->map_rayx - 1) * game->player->scale;
			if (ray->pos_rayx == (ray->map_rayx - 1) * game->player->scale)
				next_case = ray->map_rayx * game->player->scale;
			ray->nb_step_x = ft_fabs((ray->pos_rayx - next_case) / ray->dx);
		}
		else
		{
			next_case = ray->map_rayx * game->player->scale;
			if (ray->pos_rayx == ray->map_rayx * game->player->scale)
				next_case = (ray->map_rayx + 1) * game->player->scale;
			ray->nb_step_x = (next_case - ray->pos_rayx) / ray->dx;
		}
		if (ray->dy < 0)
		{
			next_case = (ray->map_rayy - 1) * game->player->scale;
			if (ray->pos_rayy == (ray->map_rayy - 1) * game->player->scale)
				next_case = ray->map_rayy * game->player->scale;
			ray->nb_step_y = ft_fabs((ray->pos_rayy - next_case) / -ray->dy);
		}
		else
		{
			next_case = ray->map_rayy * game->player->scale;
			if (ray->pos_rayy == ray->map_rayy * game->player->scale)
				next_case = (ray->map_rayy + 1) * game->player->scale;
			ray->nb_step_y = (next_case - ray->pos_rayy) / ray->dy;
		}
		ft_dda(game, ray);
		if (ray->dy < 0)
			ray->last_cordy = (int)((game->player->y_pos + (ray->dy * ray->len) - 0.0003) / game->player->scale);
		else
			ray->last_cordy = (int)((game->player->y_pos + (ray->dy * ray->len) + 0.0003) / game->player->scale);
		if (ray->dx < 0)
			ray->last_cordx = (int)((game->player->x_pos + (ray->dx * ray->len) - 0.0003) / game->player->scale);
		else
			ray->last_cordx = (int)((game->player->x_pos + (ray->dx * ray->len) + 0.0003) / game->player->scale);
		if (ray->last_cordy >= game->map_heigth)
			ray->last_cordy = game->map_heigth - 1;
		if (ray->last_cordx > (int)ft_strlen(game->map[ray->last_cordy]))
			ray->last_cordx = (int)ft_strlen(game->map[ray->last_cordy]);
	}
	ft_add_vertical(game, ray, i);
	return (0);
}

int	ray_fov(t_game *state)
{
	float	until;
	float	offset;
	float	increment;
	int		i;
	t_ray	ray;

	i = 0;
	offset = state->player->direction - PI / 3;
	until = state->player->direction;
	increment = ((state->player->direction + PI / 3) - (state->player->direction - PI / 3)) / WIDTH;
	while(offset <= until)
	{
		ray.angle = state->player->direction + offset;
		raycaster2d(state, &ray, i);
		offset += increment;
		i++;
	}
	until = state->player->direction + PI / 3;
	while (offset <= until)
	{
		ray.angle = state->player->direction + offset;
		raycaster2d(state, &ray, i);
		offset += increment;
		i++;
	}
	fix_it_hihi(state);
	return (0);
}
