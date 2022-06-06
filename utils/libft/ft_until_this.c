

#include "libft.h"

int	ft_until_this(char *str, char *this)
{
	int	inc;

	inc = -1;
	if (!str)
		return (-1);
	while (str[++inc])
	{
		if (ft_strchr(this, str[inc]))
			return (inc);
	}
	return (-1);
}
