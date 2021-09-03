NAME = solong
 
FLAGS =  -g -Wall -Wextra -Werror -framework OpenGL -framework AppKit 
SRCS = main.c utils/get_next_line.c utils/get_next_line_utils.c  dblink/dblink_utils.c utils/verif.c \
	   utils/util.c dblink/dblink.c mapInit.c render.c player.c main_init.c
OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@$(MAKE) -C ./utils/minilibx
		@${CC} ${OBJS} ${FLAGS} ./utils/libft/libft.a ./utils/minilibx/libmlx.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

run: all
	./${NAME}
	
leak: all

	@(leaks --atExit --  ./${NAME})
	

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean
re: fclean all
	
.PHONY: clean fclean re all
