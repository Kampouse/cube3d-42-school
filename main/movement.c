/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/06 05:28:35 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

static bool	is_in_wall(t_game *game, int point_x, int point_y)
{
	if (game->map[point_y][point_x] && game->map[point_y][point_x] != '1')
		return (true);
	return (false);
}

void	move(t_game *game, char c)
{
	float	point_x;
	float	point_y;

	if (c == '+')
	{
		point_x = game->player->x_pos + game->player->dx;
		point_y = game->player->y_pos + game->player->dy;
	}
	else
	{
		point_x = game->player->x_pos - game->player->dx;
		point_y = game->player->y_pos - game->player->dy;
	}
	if (is_in_wall(game, (point_x / game->player->scale),
			((point_y) / game->player->scale)))
	{
		game->player->x_pos = point_x;
		game->player->y_pos = point_y;
	}
}

void	ft_move_w(t_game *game)
{
	move(game, '+');
	initialise_map(game);
	ray_fov(game);
}

void	ft_move_s(t_game *game)
{
	move(game, '-');
	initialise_map(game);
	ray_fov(game);
}
