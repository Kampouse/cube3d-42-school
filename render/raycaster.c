/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/21 14:29:48 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

float	distance(ax, ay, bx, by, ang)
{
	return (cos(ang)*(bx-ax)-sin(ang)*(by-ay));
}

int	raycaster2d(t_game *game, t_ray ray)
{
	int	next_case;

	ray.len = 0;
	next_case = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
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
	ft_add_vertical(game, &ray);
	return (0);
}

// Got to change this so every pixel get a ray
int	ray_fov(t_game *state, float angle, int inc)
{
	float	until;
	float	plus;
	t_ray	ray;
	(void)angle;
	(void)inc;

	plus = 0;
	ray.pos_rayx = state->player->x_pos;
	ray.pos_rayy = state->player->y_pos;
	ray.angle = state->player->direction;
	until = WIDTH;
	while(state->player->direction + plus < until)
	{
		ray.angle = state->player->direction + plus;
		raycaster2d(state, ray);
		ray.angle = state->player->direction - plus;
		raycaster2d(state, ray);
		plus += 1; 
	}
	return (0);
}
