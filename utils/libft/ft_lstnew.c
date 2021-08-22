/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:42:25 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 13:36:32 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	 *link;

	link = (t_list *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}
