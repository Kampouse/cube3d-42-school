/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/09 12:14:18 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

//	Me gusta
void	resize_map(t_game *game)
{
	char	**new_map;
	int		len;
	int		iter;

	iter = game->map_data->start;
	len = 0;
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
		iter++;
		len++;
	}
	freelist(game->map);
	game->map = new_map;
}

