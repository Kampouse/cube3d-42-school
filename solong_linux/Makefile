NAME = solong
 
FLAGS  =  -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
-fsanitize=address -fsanitize=leak
SRCS = main.c utils/get_next_line.c utils/get_next_line_utils.c  dblink/dblink_utils.c utils/verif.c \
	   utils/util.c dblink/dblink.c mapInit.c render.c player.c main_init.c
OBJS = ${SRCS:.c=.o}
CC = clang 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@$(MAKE) -C ./mlx
		@${CC} ${OBJS} ${FLAGS} ./utils/libft/libft.a ./mlx/libmlx.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

run: all
	./${NAME}
	


fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean
re: fclean all
	
.PHONY: clean fclean re all
