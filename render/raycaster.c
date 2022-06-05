/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/04 12:37:49 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	ft_last_cord(t_game *game, t_ray *ray, int i)
{
	const float	offset = 0.0062;

	if (ray->dy < 0)
	{
		ray->last_cordy = (int)((game->player->y_pos
					+ (ray->dy * ray->len) - offset) / game->player->scale);
	}
	else
	{
		ray->last_cordy = (int)((game->player->y_pos
					+ (ray->dy * ray->len) + offset) / game->player->scale);
	}
	if (ray->dx < 0)
	{
		ray->last_cordx = (int)((game->player->x_pos
					+ (ray->dx * ray->len) - offset) / game->player->scale);
	}
	else
	{
		ray->last_cordx = (int)((game->player->x_pos
					+ (ray->dx * ray->len) + offset) / game->player->scale);
	}
	if (ray->last_cordy >= game->map_heigth)
		ray->last_cordy = game->map_heigth - 1;
	if (ray->last_cordx > (int)ft_strlen(game->map[ray->last_cordy]))
		ray->last_cordx = (int)ft_strlen(game->map[ray->last_cordy]);
}

void	ft_nb_step(t_game *game, t_ray *ray)
{
	ray->map_rayx = (ray->pos_rayx / game->player->scale) + 1;
	ray->map_rayy = (ray->pos_rayy / game->player->scale) + 1;
	ft_nb_step_dx(game, ray);
	ft_nb_step_dy(game, ray);
	// printf("stepy = %f stepx = %f\n", ray->nb_step_y, ray->nb_step_x);
}

int	raycaster(t_game *game, t_ray *ray, int i)
{
	ft_init_ray(game, ray, i);
	while (game->map[ray->last_cordy][ray->last_cordx] != '1')
	{
		ft_nb_step(game, ray);
		ft_dda(game, ray);
		ft_last_cord(game, ray, i);
	}
	// printf("%d) Last hit = %c (%d,%d), (%f,%f)\n", i, ray->last_hit, ray->last_cordy, ray->last_cordx, game->player->y_pos + (ray->dy * ray->len), game->player->x_pos + (ray->dx * ray->len));
	ft_fishey(game, ray, i);
	ft_add_vertical(game, ray, i);
	return (0);
}

int	ray_fov(t_game *state)
{
	double	until;
	double	offset;
	double	increment;
	int		i;
	t_ray	ray;

	i = 0;
	offset = state->player->direction - PI / 6;
	until = state->player->direction + PI / 6;
	increment = ((state->player->direction
				+ PI / 6) - (state->player->direction - PI / 6)) / WIDTH;
	while (offset <= until)
	{
		ray.angle = ft_wrap_angle(offset);
		raycaster(state, &ray, i);
		offset += increment;
		i++;
	}
	fix_it_hihi(state);
	return (0);
}
