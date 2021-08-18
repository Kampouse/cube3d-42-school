NAME = solong

FLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit 
SRCS = main.c get_next_line.c get_next_line_utils.c dblink.c dblink_utils.c
OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./libft
		@$(MAKE) -C ./minilibx
		@${CC} ${OBJS} ${FLAGS} ./libft/libft.a ./minilibx/libmlx.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

run: all
	./${NAME}
	


fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C minilibx fclean
	@$(MAKE) -C libft fclean
re: fclean all
	
.PHONY: clean fclean re all
