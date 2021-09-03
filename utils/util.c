#include "libft/libft.h"
#include "stdio.h"

int	ft_between(char *string, char comp)
{
	int	len;

	if (string[0] != comp)
		return (-1);
	len = ft_strlen(string);
	if (string[len - 1] != comp)
		return (-1);
	return (0);
}

int	ft_all(char *string, char comp)
{
	int	inc;

	inc = 0;
	while (string[inc])
	{
		if (string[inc] != comp)
			return (-1);
		inc++;
	}
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
