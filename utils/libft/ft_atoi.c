/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 07:58:55 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/08 11:22:00 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_atoi(const char *value)
{
	int			base;
	int			nbr;
	const char	*ptr;

	nbr = 0;
	base = 1;
	ptr = value;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{	
		if (*ptr == '-')
			base *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		nbr *= 10;
		nbr += (int)(*ptr - '0');
		ptr++;
	}
	return (nbr * base);
}
