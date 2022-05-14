/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2022/05/14 13:07:32 by aguay            ###   ########.fr       */
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
	printf("x_map\t\t= %d\n", game->player->x_map);
	printf("y_map\t\t= %d\n", game->player->y_map);
	printf("dy\t\t= %f\n", game->ray->dy);			// Ne s'update pas
	printf("dx\t\t= %f\n", game->ray->dx);			// Ne s'update pas
	printf("dir\t\t= %f\n", game->ray->dir);
	printf("plane_x\t\t= %f\n", game->ray->plane_x);
	printf("plane_y\t\t= %f\n", game->ray->plane_y);
	printf("delta_x\t\t= %f\n", game->ray->delta_x);
	printf("delta_y\t\t= %f\n", game->ray->delta_y);
	printf("angle\t\t= %f\n", game->ray->angle);
	printf("max_value\t= %f\n", game->ray->max_value);
	printf("diff\t\t= %f\n\n\n", game->ray->diff);
}