NAME 	=  so_long

ifeq ($(shell uname -s), Linux)
	MLX_DIR		=	minilibx_linux
	MLX			=	libmlx_Linux.a
	LINK_MLX	=	-I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
endif

ifeq ($(shell uname -s), Darwin)
	MLX_DIR		=	minilibx_mac
	MLX			=	libmlx.a
	LINK_MLX	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

SRCS 	=	check_map.c destroy.c draw.c error.c gnl.c init.c load_map.c main.c steps.c utils1.c utils2.c

CC 		= 	@gcc

OBJS 	= 	$(SRCS:.c=.o)

FLAGS 	= 	-Wall -Werror -Wextra -Imlx

.c.o	:
			$(CC) $(FLAGS) -Iincludes -c $< -o $(<:.c=.o)

$(NAME)	: 	$(OBJS)
			@make -C $(MLX_DIR) all
			$(CC) $(FLAGS) $(OBJS) $(LINK_MLX) -o $(NAME)

all		: 	$(NAME)

clean	:
			@make -C $(MLX_DIR) clean
			@rm -rf $(OBJS)

fclean	: 	clean
			@make -C $(MLX_DIR) clean
			@rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	clean fclean re all
