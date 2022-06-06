/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:26:04 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 10:38:13 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "../utils/libft/libft.h"

void	hook_second(void *param);

void	hook(void *param)
{
	t_mlx	*mlx;
	t_game	*state;

	state = param;
	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(mlx, state->image.image);
		mlx_terminate(mlx);
		freelist(state->map);
		exit(0);
		return ;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		initialise_map(state);
		state->player->direction -= 0.05;
		if (state->player->direction < 0)
			state->player->direction += 6.283;
		ray_fov(state);
	}
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
	{
		initialise_map(state);
		state->player->direction += 0.05;
		if (state->player->direction > 6.283)
			state->player->direction -= 6.283;
		ray_fov(state);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_M))
	{
		draw_map(state, state->image, state->player->scale);
		put_player_2d(state);
	}
}
