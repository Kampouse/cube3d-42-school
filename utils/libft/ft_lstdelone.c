/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:33:23 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 09:05:27 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	ft_lstdelone(t_list *currlist, void (*del)(void *))
{
	if (currlist)
	{
		(*del)(currlist->content);
		free(currlist);
	}
}
