/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/12 15:14:19 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

bool	move_ok(t_game *game, float delta_x, float delta_y)
{
	int	x;
	int	y;

	x = game->player->x_pos + delta_x * 2;
	y = game->player->y_pos + delta_y * 2;
	x /= game->player->scale;
	y /= game->player->scale;
	printf("x = %d && y = %d\n", x, y);
	if (game->map[y][x] != '1')
	{
		game->player->x_map = x;
		game->player->y_map = y;
		return (true);
	}
	return (false);
}
