/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:26:04 by aguay             #+#    #+#             */
/*   Updated: 2022/06/06 14:51:57 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

static void	render_cadre(t_game *game)
{
	int	top;
	int	i;

	top =  HEIGHT - (game->map_data->height * 13);
	i = 0;
	while (i < (game->map_data->width + 1) * 12)
		mlx_putpixel(game->image.image, i++, top, color_to_rgb(0, 183, 135, 39));
}

void	render_map(t_game *game)
{
	render_cadre(game);
	// square_shape(&game->image, 0, HEIGHT - (game->map_data->height), color_to_rgb(0, 0, 0, 0));
}
