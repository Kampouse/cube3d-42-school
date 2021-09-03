/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:49:51 by jean-phil         #+#    #+#             */
/*   Updated: 2021/09/03 17:57:50 by jemartel         ###   ########.fr       */
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
