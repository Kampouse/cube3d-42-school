/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:23:43 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/11 10:53:30 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *currlist)
{
	int	lenght;

	lenght = 0;
	while (currlist)
	{
		currlist = currlist->next;
		lenght++;
	}
	return (lenght);
}
