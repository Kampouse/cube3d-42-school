/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:11:15 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/10 16:02:39 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "stdio.h"
#include "stdlib.h"
#include "../utils/libft/libft.h"

int	assert(int value, char *str)
{
	if (value != 0)
		ft_putstr_fd(str, 1);
	return (value);
}

//	A.G : Clever la facon que tu creer ta liste
t_dlist	*mapcreator(char *map_link)
{
	t_dlist	*list;
	char	*str;
	int		fd;

	fd = open(map_link, R_OK);
	(void)list;
	if (fd < 0)
	{
		return (NULL);
	}
	if (read(fd, &str, 0) < 0)
		return (NULL);
	get_next_line(fd, &str);	//	A.G : C'est ton get_next_line ? J-p oui  s'est un GNL qui lit le file descriptor et le met dans str
	list = ft_lstnewl(str);
	while (get_next_line(fd, &str))
		ft_lst_add_backd(&list, node_init(str));
	close(fd);
	return (list);
}

char **map_init(t_dlist *map)
{
	int		len;
	char	**lines;
	t_dlist	*temp; 

	temp = map;
	lines = NULL;
	if(map == NULL) 
		return (NULL);
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
