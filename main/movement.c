/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/24 08:47:59 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	move(t_game *game, char c)
{
	float	point_x;
	float	point_y;

	if (c == '+')
	{
		point_x = game->player->x_pos + (game->player->dx * 2);
		point_y = game->player->y_pos + (game->player->dx * 2);
	}
	else
	{
		point_x = game->player->x_pos - (game->player->dx * 2);
		point_y = game->player->y_pos - (game->player->dx * 2);
	}
	if (game->map[(int)(point_x / game->player->scale)][(int)(point_y / game->player->scale)] != '1')
	{
		printf("Move from\t(%f,%f) to (%f,%f)\n", game->player->x_pos, game->player->y_pos, point_x, point_y);
		game->player->x_pos = point_x;
		game->player->y_pos = point_y;
	}
}

void	ft_move_w(t_game *game)
{
	game->command_on = true;
	ray_fov(game);
	move(game, '+');
	initialise_map(game);
	ray_fov(game);
	game->command_on = false;
}

void	ft_move_s(t_game *game)
{
	game->command_on = true;
	ray_fov(game);
	move(game, '-');
	initialise_map(game);
	ray_fov(game);
	game->command_on = false;
}
