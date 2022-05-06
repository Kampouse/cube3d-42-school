NAME = cub3d
 
FLAGS =   -g -Wall -Wextra  -Werror  

SRCS = 	main/main.c \
		utils/get_next_line.c  \
		utils/get_next_line_utils.c  \
		utils/dblink/dblink_utils.c \
		utils/dblink/dblink.c  \
		parsing/verif.c \
		parsing/verif_wall.c	 \
		parsing/mapInit.c	\
		parsing/parsing.c	\
		parsing/map.c	\
		parsing/orientation.c	\
		parsing/resize_map.c	\
		render/graphic_operator.c	\
		render/render.c 	\
		render/raycaster.c 	\
		main/main_init.c \
		main/utils.c	\

HEADER= ./Include/cube.h
FRAMEWORK= -framework Cocoa -framework OpenGL -framework IOKit
LIBS=  ./utils/libft/libft.a ./utils/MLX/libmlx42.a  ./utils/MLX/glfw/lib-x86_64/libglfw3.a

.c.o:
	@gcc  ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@$(MAKE) -s -C ./utils/MLX
		@${CC}  ${FLAGS} ${OBJS} ${LIBS} ${FRAMEWORK}  -o ${NAME}
clean:
		@${RM} ${OBJS}

fclean: clean
	rm -rf cub3d

git:
	@git add ${SRCS} ${HEADER} Makefile

val:
	valgrind   --leak-check=full --track-origins=yes   ./$(NAME) ./map.cub

run: all
	./${NAME} assets/map.cub
	
leak: all
	@echo "\033[92mTEST 1 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map.ber) 
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean

re: fclean all
	
.PHONY: clean fclean re all
