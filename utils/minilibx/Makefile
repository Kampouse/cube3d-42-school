CC			= gcc
RM			= rm -f
NAME		= libmlx.a
CFLAGS		+= -O2
INCLUDES	= -I .
SRCS		= mlx_shaders.c  mlx_xpm.c mlx_int_str_to_wordtab.c \
			  mlx_new_window.m mlx_init_loop.m mlx_new_image.m

OBJ1		= $(SRCS:.c=.o)
OBJECTS		= $(OBJ1:.m=.o)

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

%.o: %.m
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@$(RM) mlx_app

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# EOF #
