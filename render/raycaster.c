/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/23 09:44:53 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

float	distance(ax, ay, bx, by, ang)
{
	return (cos(ang)*(bx-ax)-sin(ang)*(by-ay));
}

int	raycaster2d(t_game *game, t_ray ray, int i)
{
	int	next_case;

	ray.len = 0;
	next_case = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	ray.pos_rayx = game->player->x_pos;
	ray.pos_rayy = game->player->y_pos;
	while(game->map[(int)(game->player->y_pos + (ray.dy * ray.len)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * ray.len))  / game->player->scale] != '1')
	{
		ray.map_rayx = (ray.pos_rayx / game->player->scale) + 1;
		ray.map_rayy = (ray.pos_rayy / game->player->scale) + 1;
		if (ray.dx < 0)
		{
			next_case = (ray.map_rayx - 1) * game->player->scale;
			ray.nb_step_x = (ray.pos_rayx - next_case) / ray.dx;
			if (ray.nb_step_x < 0)
				ray.nb_step_x = -ray.nb_step_x;
		}
		else
		{
			next_case = ray.map_rayx * game->player->scale;
			ray.nb_step_x = (next_case - ray.pos_rayx) / ray.dx;
		}
		if (ray.dy < 0)
		{
			next_case = (ray.map_rayy - 1) * game->player->scale;
			ray.nb_step_y = (ray.pos_rayy - next_case) / -ray.dy;
			if (ray.nb_step_x < 0)
				ray.nb_step_y = -ray.nb_step_y;
		}
		else
		{
			next_case = ray.map_rayy * game->player->scale;
			ray.nb_step_y = (next_case - ray.pos_rayy) / ray.dy;
		}
		ft_dda(&ray);
	}
	ft_add_vertical(game, &ray, i);
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
		raycaster2d(state, ray, i);
		offset += increment;
		i++;
	}
	until = state->player->direction + PI / 3;
	while (offset <= until)
	{
		ray.angle = state->player->direction + offset;
		raycaster2d(state, ray, i);
		offset += increment;
		i++;
	}
	return (0);
}
