/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/23 11:21:23 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	ft_move_w(t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	dx;
	float	dy;

	delta_y = cos(game->player->direction);
	delta_x = sin(game->player->direction);
	dx = cos(degToRad(game->player->direction)) * delta_x -  sin(degToRad(game->player->direction)) * delta_y;
	dy = sin(degToRad(game->player->direction)) * delta_x + cos(degToRad(game->player->direction)) * delta_y;
	if (move_ok(game, dx, dy, '+') == false)
	{
		printf("move invalide\n");
		return;
	}
	game->player->x_pos += dx;
	game->player->y_pos += dy;
	initialise_map(game);
	ray_fov(game);
}

void	ft_move_s(t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	dx;
	float	dy;

	delta_y = cos(game->player->direction);
	delta_x = sin(game->player->direction);
	dx = cos(degToRad(game->player->direction)) * delta_x -  sin(degToRad(game->player->direction)) * delta_y;
	dy = sin(degToRad(game->player->direction)) * delta_x + cos(degToRad(game->player->direction)) * delta_y;
	if (move_ok(game, dx, dy, '-') == false)
	{
		printf("move invalide\n");
		return;
	}
	game->player->x_pos -= dx;
	game->player->y_pos -= dy;
	initialise_map(game);
	ray_fov(game);
}
