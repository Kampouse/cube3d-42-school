/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:14:28 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/11 12:19:15 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **currlist, void (*del) (void *))
{
	t_list	*iter;	

	if (!del || !currlist || !*currlist)
	{
		return ;
	}
	while (currlist && *currlist)
	{
		iter = (*currlist)->next;
		ft_lstdelone(*currlist, del);
		*currlist = iter;
	}
}
