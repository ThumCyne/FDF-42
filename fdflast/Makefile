# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbentouy <sbentouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 03:50:32 by sbentouy          #+#    #+#              #
#    Updated: 2021/11/19 04:26:54 by sbentouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = minilibx_macos/libmlx.a 

SRC = Fdf_/exit_hook.c \
		Fdf_/fdf.c \
		Fdf_/parser_and_hooks.c \
		utils/atoi_base.c \
		utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_memcpy.c \
		utils/ft_memset.c \
		utils/ft_strdup.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		utils/ft_strsplit.c \
		utils/ft_wdcounter.c \
		utils/gnl.c \
		utils/utils.c 

SRC_BONUS = Fdf_bonus/exit_hook.c \
		Fdf_bonus/fdf.c \
		Fdf_bonus/parser_and_hooks.c \
		utils/atoi_base.c \
		utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_memcpy.c \
		utils/ft_memset.c \
		utils/ft_strdup.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		utils/ft_strsplit.c \
		utils/ft_wdcounter.c \
		utils/gnl.c \
		utils/utils.c 


CC = gcc -Wall -Wextra -Werror #-g3 -fsanitize=address

all	:	$(NAME)

$(MLX) :
	@make -C minilibx_macos/  

$(NAME) :	$(SRC) $(MLX)
	@$(CC) -o $(NAME) $(SRC) $(MLX) -framework OpenGL -framework AppKit 

bonus :	$(SRC_BONUS) $(MLX)
	@$(CC) -o $(NAME) $(SRC_BONUS) $(MLX) -framework OpenGL -framework AppKit 

clean : 
	@rm fdf
	@make clean -C minilibx_macos/
fclean :
	@rm -rf fdf
	
re : clean all
