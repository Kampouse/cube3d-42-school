/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_second.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:58:33 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/08 15:07:02 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/cube.h"

int	last_seen_at(char *str, char elem)
{
	int	index;

	if (str)
	{
		index = ft_strlen(str);
		while (index >= 0)
		{
			if (str[index] == elem)
				return (index);
			index--;
		}
	}
	return (-1);
}

int	any_before_after(char **map, int current_line)
{
	int			pos;
	int			temp;
	const int	start_at = ft_until_this(map[current_line], "1");

	pos = ft_until_this(map[current_line] + start_at, " ");
	temp = pos;
	if (pos < 0)
		return (0);
	while (pos > 0 && ft_strlen(map[current_line] + temp) > 0)
	{
		if ((map[current_line][temp + 1] != '1') || (
				map[current_line][temp - 1] != '1'))
		{
			if (!(last_seen_at(map[current_line], ' ') > last_seen_at
					(map[current_line], '1')))
				return (assert(1, "broken wall\n"));
		}
		pos = ft_until_this(map[current_line] + temp, "0");
		temp += pos;
	}
	return (0);
}

int	only_space(char *str)
{
	if (str)
	{
		if (str && ft_strlen(str) == 0)
			return (1);
		if (str && was_in_set(str, " \n\t\v") == 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	parser_helper(t_game *game, int temp, int inc)
{
	if (ft_until_this(game->map[temp], "NEWS") != -1)
	{
		game->player->x_pos = ft_until_this(game->map[temp], "NEWS");
		if (ft_until_this(game->map[temp] + ft_ftoi
				(game->player->x_pos) + 1, "NEWS") > 0)
			return (assert(2, "two player one same line\n"));
		game->player->orientation = game->map[temp][ft_ftoi
			(game->player->x_pos)];
		game->player->y_pos = inc;
		return (1);
	}
	return (0);
}
