/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:39:13 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/27 17:08:55 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "stdio.h"

int	ft_between(char *string, char comp)
{
	int	len;

	const 	char *str = ft_strtrim(string," \t\n\v");
	if(ft_strlen(str) == 0)
	{
		free((void *)str);
		return (0);
	}
	if (str[0] != comp)
	{
		return (1);
	}
	len = ft_strlen(str);
	if (str[len - 1] != comp)
	{
		free((void *)str);
		return (1);
	}
	free((void *)str);
	return (0);
}

int	ft_all(char *string, char comp)
{
			int	inc;
	const 	char *str = ft_strtrim(string,"  \t\n\v");
	inc = 0;
	while (str[inc])
	{
		if (str[inc] != comp)
		{
			free((void *)str);
			return (1);
		}
		inc++;
	}
	if(ft_strlen(str) == 0)
		return (1);
	free((void *)str);
	return (0);
}

int	ft_char_count(char *str, char cmp)
{
	int	inc;
	int	count;

	count = 0;
	inc = 0;
	while (str[inc])
	{
		if (str[inc] == cmp)
			count++;
		inc++;
	}
	return (count);
}

int	ft_count_all(char **str, char cmp)

{
	int	inc;
	int	cin;
	int	count;

	count = 0;
	inc = 0;
	cin = 0;
	while (str[cin])
	{
		inc = 0;
		while (str[cin][inc])
		{
			if (str[cin][inc] == cmp)
				count++;
			inc++;
		}
		cin++;
	}
	return (count);
}
