NAME = cub3d
 

FLAGS = -Wall -Wextra -Werror -O3

SRCS = 	main/main.c					\
		main/main_init.c			\
		main/utils.c				\
		main/movement.c				\
		utils/get_next_line.c		\
		utils/get_next_line_utils.c	\
		utils/dblink/dblink_utils.c	\
		utils/dblink/dblink.c		\
		parsing/verif.c				\
		parsing/verif_wall.c		\
		parsing/mapInit.c			\
		parsing/parsing.c			\
		parsing/map.c				\
		parsing/orientation.c		\
		parsing/resize_map.c		\
		parsing/parsing_utils.c		\
		parsing/mapInit_utils.c		\
		render/graphic_operator.c	\
		render/graphic_operator2.c	\
		render/raycaster.c 			\
		render/raycaster_utils.c	\
		render/raycaster_utils2.c	\
		render/draw.c				\

HEADER = ./Include/cube.h

FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit

LIBS =  ./utils/libft/libft.a ./utils/MLX/libmlx42.a  ./utils/MLX/glfw/lib-x86_64/libglfw3.a

.c.o:
	@gcc ${FLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = gcc

all: ${NAME}
	make clean

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@$(MAKE) -s -C ./utils/MLX
		@${CC} ${FLAGS} ${OBJS} ${LIBS} ${FRAMEWORK}  -o ${NAME}

clean:
		@${RM} ${OBJS}

fclean: clean
	make -C ./utils/libft clean
	rm -rf cub3d

git:
	@git add ${SRCS} ${HEADER} Makefile

val:
	valgrind    --track-origins=yes   ./$(NAME) ./map2.cub

run: all
	./${NAME} ./assets/map.cub

bun: all

leak: all
	@echo "\033[92mTEST 1 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map.ber) 
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean

re: fclean all

.PHONY: clean fclean re all
