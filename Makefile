# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 20:10:05 by rbouizer          #+#    #+#              #
#    Updated: 2025/05/08 12:55:55 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Linux MLX configuration (updated paths)
MLX_DIR = ./mlx_linux
MLX_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Readline support
LDFLAGS = -lreadline
INCLUDES = -I$(MLX_DIR) -I mandatory/includes

SRCS = \
	mandatory/get_next_line/get_next_line.c\
	mandatory/get_next_line/get_next_line_utils.c\
	mandatory/utils/ft_split.c\
	mandatory/utils/ft_strlcpy.c\
	mandatory/utils/ft_putendl_fd.c\
	mandatory/utils/ft_putstr_fd.c\
	mandatory/utils/ft_putchar_fd.c\
	mandatory/utils/ft_strcmp.c\
	mandatory/utils/ft_strncmp.c\
	mandatory/utils/ft_strjoin_mm.c\
	mandatory/utils/ft_split_mm.c\
	mandatory/utils/ft_atoi.c\
	mandatory/utils/ft_strtrim.c\
	mandatory/utils/ft_substr.c\
	mandatory/utils/ft_bzero.c\
	mandatory/utils/ft_calloc.c\
	mandatory/utils/ft_memset.c\
	mandatory/utils/ft_memcpy.c\
	mandatory/parser/ft_fd.c\
	mandatory/parser/ft_helps.c\
	mandatory/parser/mem.c\
	mandatory/parser/ft_check.c\
	mandatory/parser/ft_node.c\
	mandatory/parser/ft_color.c\
	mandatory/parser/ft_data.c\
	mandatory/parser/ft_map.c\
	mandatory/parser/ft_player.c\
	mandatory/parser/ft_process.c\
	mandatory/parser/ft_utils.c\
	mandatory/parser/ft_texture.c\
	mandatory/parser/test.c\
	mandatory/main.c\
	mandatory/ray_casting/cleaner.c\
	mandatory/ray_casting/collision_detection.c\
	mandatory/ray_casting/door_interaction.c\
	mandatory/ray_casting/events.c\
	mandatory/ray_casting/game_r_casting_helper.c\
	mandatory/ray_casting/game_ray_casting.c\
	mandatory/ray_casting/player_rotate_and_texture.c\
	mandatory/ray_casting/setup_data.c\
	mandatory/ray_casting/setuping.c\
	mandatory/ray_casting/utils1.c


OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HEADER = mandatory/includes/cub3d.h mandatory/get_next_line/get_next_line.h mandatory/utils/utils.h

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LINUX) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo "🔨 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️  Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re