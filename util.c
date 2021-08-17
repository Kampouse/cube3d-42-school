#include "stdio.h"
#include "libft/libft.h"
int ft_between(char *string, char comp)
{
	int len;

if(string[0] != comp) 
	return (-1);
len = ft_strlen(string);
if(string[len - 1] != comp) 
	return (-1);
return 0;
}

int ft_all(char *string,char comp)
{
	int inc;

	inc = 0;
while(string[inc])
{
	if(string[inc] != comp)
		return(-1);
	inc++;
}
return (0);
}


//int main()
//{
//char *str = "aaafaaa";
//ft_between(str,'h');
//ft_all(str,'a');
//}
