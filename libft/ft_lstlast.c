/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:23:43 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 13:35:45 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *currlist)
{
	while (currlist)
	{
		if (!currlist->next)
			return (currlist);
		currlist = currlist->next;
	}
	return (currlist);
}
