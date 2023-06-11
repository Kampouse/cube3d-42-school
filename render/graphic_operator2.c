/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_operator2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by aguay             #+#    #+#             */
/*   Updated: 2023/06/10 22:37:45 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "stdio.h"

#include <sys/_types/_u_int16_t.h>
#include <sys/_types/_u_int64_t.h>

void	paint_in_black(t_game *game)
{
	 (void)game;

}

void	initialise_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT )
		{

			
			mlx_putpixel(game->image.image, x, y, color_to_rgb(
					 y %  WIDTH / 4,
					(int)game->player->y_pos  >> 31,
					game->map_data->ceiling_color[0]));
					y++;
		}
		 
		x++;
	}
}

void	fix_it_hihi(t_game *game)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
		mlx_putpixel(game->image.image, 0, y++, 0x000000);
}
