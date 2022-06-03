/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/03 15:39:46 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

float	ft_wrap_angle(float angle)
{
	if (angle < 0.0)
		return (angle + 2.0 * PI);
	if (angle > 2.0 * PI)
		return (angle - 2.0 * PI);
	return (angle);
}

void	ft_fishey(t_game *game, t_ray *ray, int i)
{
	float	theta;

	theta = ft_wrap_angle(game->player->direction - atan(ray->dy / ray->dx));
	// printf("Angle from player to ray %d is = %f\n", i, RadToDeg(theta));
	// ray->len = ft_fabs(ray->len * (cos(theta)));
}