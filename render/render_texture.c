/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by anthony           #+#    #+#             */
/*   Updated: 2022/06/05 15:38:58 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	render_texture(t_game *game, int i, double hauteur)
{
	t_mlx_image		*img = textur_to_draw(game);
	float			asset_height;
	float			asset_width;
	int				iterator;
	int				until;
	int				x;

	x = 1;
	iterator = (HEIGHT / 2) + hauteur;
	until = (HEIGHT / 2) - hauteur;
	if (game->ray->last_hit == 'x')
		asset_width = (fmod(game->ray->pos_rayy, (double)game->player->scale) * img->width) / game->player->scale;
	if (game->ray->last_hit == 'y')
		asset_width = (fmod(game->ray->pos_rayx, game->player->scale) * img->width) / game->player->scale;
	while (iterator >= until)
	{
		asset_height = (x++ * (img->height - 1)) / (hauteur * 2);
		draw_pixel(game->image.image, i, iterator--, pixel_to_color(img, (int)asset_width, (int)asset_height));
	}
		
}
