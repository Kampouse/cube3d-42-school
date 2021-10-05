NAME = solong
 
FLAGS =  -g -Wall -Wextra -Werror -framework OpenGL -framework AppKit -lmlx
SRCS = main.c utils/get_next_line.c utils/get_next_line_utils.c  dblink/dblink_utils.c utils/verif.c \
	   utils/util.c dblink/dblink.c mapInit.c render.c player.c main_init.c
OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@${CC} ${OBJS} ${FLAGS}   ./utils/libft/libft.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

git:
	@git add ${SRCS} solong.h

run: all
	./${NAME} ./assets/map.ber
	
leak: all
	@(leaks --atExit --  ./${NAME} ./assets/map.ber)
	

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean
re: fclean all
	
.PHONY: clean fclean re all
