/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/01 14:38:52 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	player_direction(t_game *game)
{
	if (game->player->orientation == 'E')
	{
		game->player->direction = (degToRad(356));
		game->ray->dx = -1;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'N')
	{
		game->player->direction = (degToRad(86));
		game->ray->dx = 0;
		game->ray->dy = -1;
	}
	else if (game->player->orientation == 'W')
	{
		game->player->direction = (degToRad(176));
		game->ray->dx = -1;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'S')
	{
		game->player->direction = (degToRad(266));
		game->ray->dx = 0;
		game->ray->dy = 1;
	}
}
