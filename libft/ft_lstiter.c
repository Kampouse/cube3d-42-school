/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:49:51 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/11 13:56:59 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *currlist, void (*f) (void *))
{
	if (!f)
		return ;
	while (currlist)
	{
		 (*f)(currlist->content);
		currlist = currlist->next;
	}
}
