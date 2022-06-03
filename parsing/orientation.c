/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/03 16:12:50 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	player_direction(t_game *game)
{
	if (game->player->orientation == 'E')
	{
		game->player->direction = degToRad(0);
		game->ray->dx = 0;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'N')
	{
		game->player->direction = degToRad(90);
		game->ray->dx = 0;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'W')
	{
		game->player->direction = degToRad(180);
		game->ray->dx = 0;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'S')
	{
		game->player->direction = degToRad(270);
		game->ray->dx = 0;
		game->ray->dy = 0;
	}
}
