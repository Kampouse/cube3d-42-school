/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/05 14:24:28 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	player_direction(t_game *game)
{
	if (game->player->orientation == 'E')
		game->player->direction = degToRad(1);
	else if (game->player->orientation == 'N')
		game->player->direction = degToRad(271);
	else if (game->player->orientation == 'W')
		game->player->direction = degToRad(181);
	else if (game->player->orientation == 'S')
		game->player->direction = degToRad(91);
}
