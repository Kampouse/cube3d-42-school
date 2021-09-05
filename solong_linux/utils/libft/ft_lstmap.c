/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:58:52 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 10:53:12 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *currlst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*inst;
	t_list	*instnode;

	inst = NULL;
	while (currlst)
	{
		instnode = ft_lstnew(f(currlst->content));
		 if (!instnode)
		{
			 ft_lstclear(&inst, del);
			 return (NULL);
		}
		ft_lstadd_back(&inst, instnode);
		currlst = currlst->next;
	}
	return (inst);
}
