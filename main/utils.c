/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:38:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 05:15:37 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Include/cube.h"
#include "../utils/libft/libft.h"

void	free_list(t_dlist *head)
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
	int	inc;
	int	cin;
	int	was_in_set;
	
	cin = 0;
	was_in_set = 1;
	inc  = 0;
	while (str[inc])
	{
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
