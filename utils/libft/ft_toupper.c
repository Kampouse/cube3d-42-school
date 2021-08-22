/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:48:11 by jean-phil         #+#    #+#             */
/*   Updated: 2021/06/07 16:48:46 by jean-phil        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"
#include "string.h"

int 	ft_toupper(int str)
{
	if (str >= 'a' && str <= 'z')
		return (str - 32);
	return (str);
}
