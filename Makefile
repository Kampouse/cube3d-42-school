NAME = solong
 
FLAGS =  -g -Wall -Wextra -Werror -framework OpenGL -framework AppKit -lmlx
SRCS = main.c utils/get_next_line.c utils/get_next_line_utils.c  dblink/dblink_utils.c utils/verif.c \
	   utils/util.c dblink/dblink.c mapInit.c render.c player.c main_init.c
OBJS = ${SRCS:.c=.o}
CC = gcc 
all: ${NAME}

${NAME}:${OBJS} 
		@$(MAKE) -C ./utils/libft
		@${CC}  ${FLAGS} ${OBJS}  ./utils/libft/libft.a -o ${NAME}

clean:
	    @${RM} ${OBJS}	

git:
	@git add ${SRCS} solong.h

run: all
	./${NAME} ./assets/map.ber
	
leak: all
	@echo "\033[92mTEST 1 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map.ber) 
	@echo "\033[92mTEST 2 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map2.ber)
	@echo "\033[92mTEST 3 \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map3.ber)
	@echo "\033[92mTEST 4  no args \n \033[0m"
	@cat ./assets/map4.ber
	 ./${NAME} ./assets/map4.ber
	@echo "\033[92mTEST 4  bad args \n \033[0m"
	@cat ./assets/map4v2.ber
	 ./${NAME} ./assets/map4.ber
	@echo "\033[92mTEST 5-wrong len \n \033[0m"
	@cat ./assets/map5.ber
	 ./${NAME} ./assets/map5.ber
	@echo "\033[92mTEST 5-wrong len v2 \n \033[0m"
	@cat ./assets/map5part2.ber
	 ./${NAME} ./assets/map5part2.ber
	@echo "\033[92mTEST 6-wrong len v2 \n \033[0m"
	@cat ./assets/map6.ber
	./${NAME} ./assets/map6.ber
	@echo "\033[92mTEST 7-wrong NO map \n \033[0m"
	./${NAME} ./assets/map100.ber
	@echo "\033[92mTEST 7-wrong memcheck map \n \033[0m"
	@(leaks --atExit --  ./${NAME} ./assets/map6.ber)
	@echo "\033[92mtest ended \n \033[0m"
	@norminette ${SRCS}
	@norminette ./utils/libft

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ./utils/minilibx fclean
	@$(MAKE) -C ./utils/libft fclean
re: fclean all
	
.PHONY: clean fclean re all
