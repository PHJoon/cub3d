# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 12:22:24 by hyungjpa          #+#    #+#              #
#    Updated: 2023/08/23 10:03:10 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = free.c \
	gnl_utils.c \
	gnl.c \
	info_init.c \
	var_init_utils.c \
	var_init.c \
	info_parse_1.c \
	info_parse_2.c \
	info_valid_1.c \
	info_valid_2.c \
	main.c \
	utils.c \
	arg_check.c \
	mlx_main.c \
	mlx_raycasting.c \
	mlx_draw_wall.c \
	mlx_draw_fc.c \
	mlx_key_hook.c \
	mlx_events_1.c \
	mlx_events_2.c \
	mlx_texture.c


OBJ = $(SRC:.c=.o)

NAME = cub3D

INCLUDE_MLX = -I .mlx -Lmlx -lmlx -framework OpenGL -framework Appkit

INCLUDE_LIBFT = -L ./libft -lft

INCLUDE = -I ./

MLX_DIR = ./mlx/

LIBFT_DIR = ./libft/

CC = cc

CFLAGS = -O3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		make -C $(MLX_DIR) all
		make -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $(INCLUDE_MLX) $(INCLUDE_LIBFT) $(INCLUDE) $^ -o $@

%.o : %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
		make -C $(MLX_DIR) clean
		make -C $(LIBFT_DIR) clean
		rm -rf $(OBJ)

fclean : clean
		make -C $(MLX_DIR) clean
		make -C $(LIBFT_DIR) fclean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re