/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:11:15 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/28 16:07:34 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
#include "stdio.h"
#include "stdlib.h"
#include "../utils/libft/libft.h"

int	assert(int value, char *str)
{
	if (value != 0)
		ft_putstr_fd(str, 1);
	return (value);
}

t_dlist	*mapcreator(char *map_link)
{
	t_dlist	*list;
	char	*str;
	const int		fd = open(map_link, R_OK);
	(void)list;
	if (fd < 0)
		return (NULL);
	if (read(fd, &str, 0) < 0)
		return (NULL);
	get_next_line(fd, &str);
	 list = ft_lstnewl(str);
	while (get_next_line(fd, &str))
		ft_lst_add_backd(&list, node_init(str));
	close(fd);	
	return (list);
}

char **map_init(t_dlist *map)
{
	int	len;
	char **lines;
	t_dlist *temp; 

	temp = map;
	lines = NULL;
	len = ft_lst_lenght(map);
	lines = ft_calloc( len + 1,sizeof(char *));
	len = 0;
	if (!map)
		return(NULL);
	while (map)
	{

		lines[len] = ft_strdup(map->content);
		len++;
		map = map->next;
	}
	free_list(temp);
	return(lines);
}
