/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/12 10:31:10 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	show_player_info(t_game *game)
{
	printf("Player info :\n");
	printf("x_pos\t\t= %d\n", game->player->x_pos);
	printf("y_pos\t\t= %d\n", game->player->y_pos);
	printf("orientation\t= %d\n", game->player->orientation);
	printf("Radiant\t\t= %f\n", game->player->direction);
	printf("Delta_x\t\t= %f\n", game->ray->delta_x);
	printf("Delta_y\t\t= %f\n\n\n", game->ray->delta_y);
}