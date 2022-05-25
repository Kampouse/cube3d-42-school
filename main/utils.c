/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/24 09:42:00 by jemartel         ###   ########.fr       */
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

	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		initialise_map(state);
		state->player->direction -= 0.1;
		ray_fov(state);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		ft_move_w(state);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		ft_move_s(state);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		initialise_map(state);
		state->player->direction += 0.1;
		ray_fov(state);
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

bool	move_ok(t_game *game, float dx, float dy)
{
	int	x_pos;
	int	y_pos;

	x_pos = ((game->player->x_pos + dx) / game->player->scale) + 1;
	y_pos = ((game->player->y_pos + dy) / game->player->scale) + 1;
	if (game->map[y_pos][x_pos] != '1')
		return (true);
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
