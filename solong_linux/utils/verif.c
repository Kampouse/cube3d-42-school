/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:48 by jemartel          #+#    #+#             */
/*   Updated: 2021/09/03 17:39:06 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"
#include "libft/libft.h"
#include "stdio.h"

int	verif_len(t_dlist map)
{
	t_dlist	*temp;
	int		len;

	temp = NULL;
	temp = &map;
	len = ft_strlen((char *)temp->content);
	while (temp->next)
	{
		if (len != ft_strlen((char *)temp->content))
			return (1);
		len = ft_strlen((char *)temp->content);
		temp = ft_lst_nextnode(temp);
	}
	if (len != ft_strlen((char *)temp->content))
		return (1);
	return (0);
}

int	verif_wall(t_dlist map)
{
	t_dlist	*temp;

	temp = &map;
	if (ft_all((char *)temp->content, '1'))
		return (1);
	temp = ft_lst_nextnode(temp);
	while (temp->next)
	{
		if (ft_between((char *)temp->content, '1'))
			return (1);
		temp = ft_lst_nextnode(temp);
	}
	if (ft_all((char *)temp->content, '1'))
		return (1);
	return (0);
}

int	verif_param(t_dlist map, char param)
{
	  t_dlist	*temp;
	  int		counter;

	counter = 0;
	temp = &map;
	while (temp->next)
	{
		counter += ft_char_count((char *)temp->content, param);
		temp = ft_lst_nextnode(temp);
	}
	if (counter != 1 && param == 'P')
		return (1);
	if (counter < 1 && param != 'P')
		return (1);
	return (0);
}

int	legalchars(char *str)
{
	int			inc;
	const char	*comparator = "PE01C";

	inc = 0;
	while (str[inc])
	{
		if (!ft_strchr(comparator, str[inc]))
			return (1);
		inc++;
	}
	return (0);
}

int	verif_map_content(t_dlist map)
{
	  t_dlist	*temp;

	temp = &map;
	while (temp->next)
	{
		if (legalchars((char *)temp->content) != 0)
			return (1);
		temp = temp->next;
	}
	if (legalchars((char *)temp->content) != 0)
	{
		printf("missing a element");
		return (1);
	}
	return (0);
}
