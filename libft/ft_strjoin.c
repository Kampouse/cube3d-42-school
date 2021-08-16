/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:45:18 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/12 09:49:25 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *first, const char *second)
{
	char		*output;
	size_t		len;
	size_t		len2;

	len = ft_strlen(first);
	len2 = ft_strlen(second);
	output = malloc(sizeof(char) * len + len2 + 1);
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2 + 1);
	}
	return (output);
}	
