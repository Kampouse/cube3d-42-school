/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:57:56 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/13 15:12:18 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	
#include "stdlib.h"	

char	*ft_strrchr(const char *str, int compared)
{
	int		value;
	char	*last;

	last = (char *)str;
	value = ft_strlen(str);
	while (value >= 0)
	{
		if (str[value] == (unsigned char)compared)
			return (&last[value]);
		value--;
	}
	return (NULL);
}
