NAME = solong
 
FLAGS =   -g -Wall -Wextra  -framework Cocoa -framework OpenGl -framework IOKit
SRCS = 	main.c \
		utils/get_next_line.c  \
		utils/get_next_line_utils.c  \
		dblink/dblink_utils.c \
		dblink/dblink.c  \
		parsing/verif.c \
	   	parsing/verif_wall.c	 \
		parsing/mapInit.c	\
		parsing/parsing.c	\
		parsing/map.c	\
		parsing/orientation.c	\
		parsing/resize_map.c	\
		operator/find_at.c	\
		operator/graphic_operator.c	\
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
		@${CC}  ${FLAGS} ${OBJS}    ./utils/libft/libft.a -L./MLX -lMLX42  -I ./MLX42/include  ~/.brew/opt/glfw/lib/libglfw.3.3.dylib -o ${NAME}

clean:
	    @${RM} ${OBJS}	

git:
	@git add ${SRCS} cube.h Makefile
val:
	valgrind   --leak-check=full --track-origins=yes   ./$(NAME) ./map.cub
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
