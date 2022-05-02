NAME 	=  so_long

MLX		=	mlx/libmlx.a

MLB		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS 	=	check_map.c destroy.c draw.c error.c gnl.c init.c load_map.c main.c steps.c utils1.c utils2.c

CC 		= 	@gcc

OBJS 	= 	$(SRCS:.c=.o)

FLAGS 	= 	-Wall -Werror -Wextra -Imlx

.c.o	:
			$(CC) $(FLAGS) -Iincludes -c $< -o $(<:.c=.o)

$(NAME)	: 	$(OBJS)
			@make -C ./mlx
			$(CC) $(FLAGS) $(OBJS) $(MLB) -o $(NAME)

all		: 	$(NAME)

clean	:
			@make clean -C ./mlx
			@rm -rf $(OBJS)

fclean	: 	clean
			@make clean -C ./mlx
			@rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	clean fclean re all
