/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:14:18 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 14:14:20 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "../utils/libft/libft.h"

static void	exit_routine(t_game *game)
{
	mlx_delete_image(game->mlx, game->image.image);
	mlx_terminate(game->mlx);
	freelist(game->map);
	exit(0);
	return ;
}

void	hook(void *param)
{
	t_mlx	*mlx;
	t_game	*state;

	state = param;
	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit_routine(state);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		ft_rotate_left(state);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		ft_rotate_right(state);
	hook_second(param);
}

void	hook_second(void *param)
{
	t_mlx	*mlx;
	t_game	*state;

	state = param;
	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		ft_move_w(state);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		ft_move_s(state);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		ft_move_d(state);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		ft_move_a(state);
	if (mlx_is_key_down(mlx, MLX_KEY_M))
	{
		draw_map(state, state->image, state->player->scale);
		put_player_2d(state);
	}
}
