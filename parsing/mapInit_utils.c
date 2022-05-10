/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/09 22:09:00 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

void	ft_poll_color(char *str,t_map *map,int inc)
{
	char	*temp;

	temp = NULL;
	// this function could be improved 
	if (str && ft_strlen(str) > 1)
	{
		if (ft_strncmp(str,"F",1) == 0)
		{
			temp = ft_strtrim(str + 1," \n\t\v");
			if(temp)
			{
				map->floor_color = get_color(temp);
				map->iterator = inc;
			}
		}
		if (ft_strncmp(str, "C", 1) == 0)
		{
			temp = ft_strtrim(str + 1," \n\t\v");
			if (temp)
			{
				map->ceiling_color = get_color(temp);
				map->iterator = inc;
			}
		}
		free(str);
	}
}

/* 
	should make another function that check that no null one
	Note : Add ./path validation
	+ 1
*/
void	ft_poll_texture(char *str,t_map *map)
{
	char	*temp;

	temp = NULL;
	if(str && map)
	{
		if (ft_strncmp(str,"NO",2) == 0 && ft_strlen(str) > 2)
			map->norh_texture = ft_strtrim(str + 2," \n\t\v");
		else if (ft_strncmp(str,"SO",2) == 0 && ft_strlen(str) > 2)
			map->south_texture = ft_strtrim(str + 2," \n\t\v");
		else if (ft_strncmp(str,"WE",2) == 0 && ft_strlen(str) > 2)
			map->west_texture = ft_strtrim(str + 2," \n\t\v");
		else if (ft_strncmp(str,"EA",2) == 0 && ft_strlen(str) > 2)
			map->est_texture = ft_strtrim(str + 2," \n\t\v");
		free(str);
	}
}

int	delete_texture(t_map *map)	// c'est dans parsing ou ini ? (aucun des deux s'est pour clean up J-p)
{
	if(map)
	{
		map->ceiling_color = ft_free(map->ceiling_color);
		map->south_texture = ft_free(map->south_texture);
		map->norh_texture = ft_free(map->norh_texture);
		map->west_texture = ft_free(map->west_texture);
		map->est_texture = ft_free(map->est_texture);
		map->floor_color = ft_free(map->floor_color);
		free(map);	
	}
	return (0);
}
