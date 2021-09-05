/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:23:43 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 09:22:24 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **currlist, t_list *new)
{
	t_list	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = ft_lstlast(*currlist);
			last->next = new;
		}
		else
			*currlist = new;
	}
}
