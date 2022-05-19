/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/19 14:19:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

int	line_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '1' || str[i] == '0' || str[i] == 'E'))
		i++;
	return (i);
}

void	resize_map(t_game *game)
{
	char	**new_map;
	int		len;
	int		iter;
	int		width;

	iter = game->map_data->start;
	len = 0;
	width = 0;
	while (game->map[iter] && !(only_space(game->map[iter])))
	{
		iter++;
		len++;
	}
	game->map_data->last = len;
	new_map = ft_calloc(len + 1,sizeof(new_map));
	iter = game->map_data->start;
	len = 0;
	while (game->map[iter] && !(only_space(game->map[iter])))
	{
		new_map[len] = ft_strdup(game->map[iter]);
		if (width < line_size(new_map[len]))
			width = line_size(new_map[len]);
		iter++;
		len++;
	}
	game->map_heigth = len;
	game->map_width = width;
	freelist(game->map);
	game->map = new_map;
}
