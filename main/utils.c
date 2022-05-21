/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/21 14:32:07 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "../utils/libft/libft.h"

void	free_list(t_dlist *head) // sexy
{
	t_dlist	*next;

	if (head != NULL)
	{
		next = head->next;
		free(head->content);
		free(head);
		free_list(next);
	}
}

void	hook(void *param)
{
	t_mlx	*mlx;
	t_game	*state;

	state = param;
	const float delta_y = cos(state->player->direction);
	const float delta_x = sin( state->player->direction);
	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		initialise_map(state);
		state->player->direction += 0.1;
		ray_fov(state, state->player->direction, 0);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W) && move_ok(state, delta_x, delta_y))
	{
		initialise_map(state);
		ray_fov(state, state->player->direction, 0);
		state->player->x_pos += delta_x * 2;
		state->player->y_pos += delta_y * 2;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S) && move_ok(state, -delta_x, -delta_y))
	{
		initialise_map(state);
		ray_fov(state, state->player->direction, 0);
		state->player->x_pos -= delta_x * 2;
		state->player->y_pos -= delta_y * 2;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		initialise_map(state);
		state->player->direction -= 0.1;
		if(state->player->direction <= 0)
			state->player->direction = PI * 2;
		ray_fov(state, state->player->direction, 0);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_M))
	{
		draw_map(state, state->image, state->player->scale);
		put_player_2d(state);
	}
}

char	freelist(char **list)
{
	int	inc;

	inc = 0;
	while (list && list[inc])
	{
		free(list[inc]);
		inc++;
	}
	free(list);
	return (0);
}

bool	move_ok(t_game *game, float delta_x, float delta_y)
{
	int	x;
	int	y;

	x = game->player->x_pos + delta_x * 2;
	y = game->player->y_pos + delta_y * 2;
	x /= game->player->scale;
	y /= game->player->scale;
	if (game->map[y][x] != '1')
	{
		game->player->x_map = x + 1;
		game->player->y_map = y + 1;
		return (true);
	}
	return (false);
}

int	was_in_set(char *str,char *set)
{
	int inc;
	int cin;
	int temp;
	int was_in_set;
		cin = 0;
	was_in_set = 1;
		inc  = 0;
		while (str[inc])
		{
			temp = inc;
			while(set[cin])
			{
				if (set[cin] == str[inc])
				{
					was_in_set = 0;
					cin = 0;
					break ;
				}
				cin++;
			}
			if (was_in_set != 0)
				return (1);
			was_in_set = 1;
			inc++;
		}
	return(0);
}
