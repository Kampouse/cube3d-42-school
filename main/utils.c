/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/24 09:38:56 by aguay            ###   ########.fr       */
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
	if (mlx_is_key_down(mlx, MLX_KEY_A) && state->command_on == false)
	{
		state->command_on = true;
		initialise_map(state);
		state->player->direction -= 0.1;
		if (state->player->direction < 0)
			state->player->direction = 6.2;
		ray_fov(state);
		state->command_on = false;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W) && state->command_on == false)
		ft_move_w(state);
	if (mlx_is_key_down(mlx, MLX_KEY_S) && state->command_on == false)
		ft_move_s(state);
	if (mlx_is_key_down(mlx, MLX_KEY_D) && state->command_on == false)
	{
		state->command_on = true;
		initialise_map(state);
		state->player->direction += 0.1;
		if (state->player->direction > 6.2)
			state->player->direction = 0;
		ray_fov(state);
		state->command_on = false;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_M) && state->command_on == false)
	{
		state->command_on = true;
		draw_map(state, state->image, state->player->scale);
		put_player_2d(state);
		state->command_on = false;
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
