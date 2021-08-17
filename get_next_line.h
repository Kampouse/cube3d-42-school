#ifndef  GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# include "stdlib.h"
# include "fcntl.h"
# include "sys/stat.h"
# include "sys/types.h"
# include "unistd.h"

# include "libft/libft.h"
# include "stdio.h"
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strchrr(char *head, int comp);
char	*ft_strjoin(const char *first, const char *second);
int		get_next_line(int fd, char **line);
# define BUFFSIZE 42

#endif
