/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/06/06 11:17:26 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

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

void	ft_move_a(t_game *game)
{
	move(game, 'l');
	initialise_map(game);
	ray_fov(game);
}

void	ft_move_d(t_game *game)
{
	move(game, 'r');
	initialise_map(game);
	ray_fov(game);
}

bool	is_in_wall(t_game *game, int point_x, int point_y)
{
	if (game->map[point_y][point_x] && game->map[point_y][point_x] != '1')
		return (true);
	return (false);
}
