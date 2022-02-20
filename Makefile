NAME = solong
 
FLAGS =   -g -Wall -Wextra  -framework OpenGL -framework AppKit -lmlx 
SRCS = 	main.c \
		utils/get_next_line.c  \
		utils/get_next_line_utils.c  \
		dblink/dblink_utils.c \
		dblink/dblink.c  \
		parsing/verif.c \
	   	parsing/verif_wall.c	 \
		parsing/mapInit.c	\
		parsing/parsing.c	\
		render/render.c 	\
		player.c	\
		init/main_init.c

.c.o:
	@gcc  ${FLAGS}  -c $< -o ${<:.c=.o}
OBJS = ${SRCS:.c=.o}

CC = gcc


OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@${CC}  ${FLAGS} ${OBJS}  ./utils/libft/libft.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

git:
	@git add ${SRCS} cube.h Makefile
val:
	valgrind      ./$(NAME) ./assets/map.ber
run: all
	./${NAME} map.cub
	
leak: all
	@echo "\033[92mTEST 1 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map.ber) 
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean
re: fclean all
	
.PHONY: clean fclean re all
