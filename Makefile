# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamita <mamita@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 17:04:25 by ageiser           #+#    #+#              #
#    Updated: 2023/08/13 19:20:15 by mamita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
NO_COLOR = \033[0m

NAME = fdf

SRC_DIR = src/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

SRC_FILES = main.c \
			fdf_error.c \
			fdf_filopmapsize.c \
			fdf_map.c \
			fdf_atoi.c \
			fdf_findrange.c \
			fdf_free_all.c \
			fdf_colorgradient.c \
			fdf_colormap.c \
			fdf_default.c \
			fdf_clear_img.c \
			fdf_map_to_screen.c \
			fdf_map_fill.c \
			fdf_fill_img.c \
			fdf_put_pixel.c \
			fdf_bresenham.c \
			fdf_color.c \
			fdf_bresenham_else.c \
			fdf_bresenham_if.c \
			fdf_keypressed.c \
			fdf_mouseclick.c 
			




DEP = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.d))

TMP_SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC_FILES:.c=.o)

TMP_OBJ = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDE = -I ./include/ -I ./libft/

MLXLINK = -L resources/minilibx_macos
MINILIBX = -I resources/minilibx_macos

OPENGL = -lmlx -framework OpenGL -framework AppKit

LIB_DIR = ./libft/
LIB = $(LIB_DIR)libft.a

all: makelib $(OBJ_DIR) $(NAME)

makelib:
		make -C $(LIB_DIR)

$(OBJ_DIR)%.o  : $(SRC_DIR)%.c Makefile
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)file compiled$(NO_COLOR)"

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(NAME): $(TMP_OBJ) $(LIB)
		make -C resources/minilibx_macos
		$(CC) $(CFLAGS) $(TMP_OBJ) $(MLXLINK) -L $(LIB_DIR) -lft $(OPENGL) -o $(NAME)
		@echo "$(GREEN)librairy compiled and executable generated$(NO_COLOR)" 
					
clean: 
		$(RM) $(OBJ_DIR)
		$(MAKE) clean -C $(LIB_DIR)
		@echo "$(RED)objects directory removed$(NO_COLOR)"

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIB)
		@echo "$(RED)full clean$(NO_COLOR)"

re: fclean all
	@echo "$(GREEN)Make fclean and make all$(NO_COLOR)"


-include $(DEP)
.PHONY: all clean fclean re