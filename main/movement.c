/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/24 10:41:56 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	move(t_game *game, char c)
{
	float	point_x;
	float	point_y;

	if (c == '+')
	{
		point_x = game->player->x_pos + game->player->delta_x;
		point_y = game->player->y_pos + game->player->delta_y;
	}
	else
	{
		point_x = game->player->x_pos - game->player->delta_x;
		point_y = game->player->y_pos - game->player->delta_y;
	}
	if (point_x < 0 || point_y < 0)
		return;
	game->player->x_pos = point_x;
	game->player->y_pos = point_y;
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
