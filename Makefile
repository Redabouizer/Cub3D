# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 20:10:05 by rbouizer          #+#    #+#              #
#    Updated: 2025/05/13 05:39:13 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
B_NAME = cub3d_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address,leak,undefined

# Linux MLX configuration (updated paths)
MLX_DIR = ./mlx_linux
MLX_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Readline support
LDFLAGS = -lreadline
INCLUDES = -I$(MLX_DIR) -I mandatory/includes
B_INCLUDES = -I$(MLX_DIR) -I bonus/includes

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
	mandatory/utils/ft_isdigit.c\
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
	mandatory/parser/ft_check_pro.c\
	mandatory/parser/ft_node.c\
	mandatory/parser/ft_color.c\
	mandatory/parser/ft_data.c\
	mandatory/parser/ft_map.c\
	mandatory/parser/ft_player.c\
	mandatory/parser/ft_process.c\
	mandatory/parser/ft_utils.c\
	mandatory/parser/ft_texture.c\
	mandatory/parser/test.c\
	mandatory/ray_casting/cleaner.c\
	mandatory/ray_casting/cleaner_pro.c\
	mandatory/ray_casting/collision_detection.c\
	mandatory/ray_casting/collision_detection_pro.c\
	mandatory/ray_casting/door_interaction.c\
	mandatory/ray_casting/events.c\
	mandatory/ray_casting/events_pro.c\
	mandatory/ray_casting/game_r_casting_helper.c\
	mandatory/ray_casting/game_ray_casting.c\
	mandatory/ray_casting/player_rotate_and_texture.c\
	mandatory/ray_casting/setuping.c\
	mandatory/ray_casting/utils1.c\
	mandatory/ray_casting/utils2.c\
	mandatory/main.c

B_SRCS = \
	bonus/get_next_line/get_next_line.c\
	bonus/get_next_line/get_next_line_utils.c\
	bonus/utils/ft_split.c\
	bonus/utils/ft_strlcpy.c\
	bonus/utils/ft_putendl_fd.c\
	bonus/utils/ft_putstr_fd.c\
	bonus/utils/ft_putchar_fd.c\
	bonus/utils/ft_strcmp.c\
	bonus/utils/ft_strncmp.c\
	bonus/utils/ft_strjoin_mm.c\
	bonus/utils/ft_split_mm.c\
	bonus/utils/ft_isdigit.c\
	bonus/utils/ft_atoi.c\
	bonus/utils/ft_strtrim.c\
	bonus/utils/ft_substr.c\
	bonus/utils/ft_bzero.c\
	bonus/utils/ft_calloc.c\
	bonus/utils/ft_memset.c\
	bonus/utils/ft_memcpy.c\
	bonus/parser/ft_fd.c\
	bonus/parser/ft_helps.c\
	bonus/parser/mem.c\
	bonus/parser/ft_check.c\
	bonus/parser/ft_check_pro.c\
	bonus/parser/ft_node.c\
	bonus/parser/ft_color.c\
	bonus/parser/ft_data.c\
	bonus/parser/ft_map.c\
	bonus/parser/ft_player.c\
	bonus/parser/ft_process.c\
	bonus/parser/ft_utils.c\
	bonus/parser/ft_texture.c\
	bonus/parser/test.c\
	bonus/parser/ft_allocate.c\
	bonus/ray_casting/cleaner.c\
	bonus/ray_casting/cleaner_pro.c\
	bonus/ray_casting/collision_detection.c\
	bonus/ray_casting/collision_detection_pro.c\
	bonus/ray_casting/door_interaction.c\
	bonus/ray_casting/events_pro.c\
	bonus/ray_casting/events.c\
	bonus/ray_casting/game_r_casting_helper.c\
	bonus/ray_casting/game_ray_casting.c\
	bonus/ray_casting/player_rotate_and_texture.c\
	bonus/ray_casting/setuping.c\
	bonus/ray_casting/utils1.c\
	bonus/ray_casting/utils2.c\
	bonus/ray_casting/move.c\
	bonus/main.c

OBJ_DIR = objects
B_OBJ_DIR = bonus_objects

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
B_OBJS = $(addprefix $(B_OBJ_DIR)/, $(B_SRCS:.c=.o))

HEADER = mandatory/includes/cub3d.h mandatory/includes/get_next_line.h mandatory/includes/utils.h
B_HEADER = bonus/includes/cub3d.h bonus/includes/get_next_line.h bonus/includes/utils.h

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LINUX) $(LDFLAGS) -o $(NAME)

$(B_NAME): $(B_OBJS)
	@echo "🔗 Linking $(B_NAME)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(MLX_LINUX) $(LDFLAGS) -o $(B_NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo "🔨 Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

$(B_OBJ_DIR)/%.o: %.c $(B_HEADER)
	@mkdir -p $(dir $@)
	@echo "🔨 Compiling $< (bonus)"
	@$(CC) $(CFLAGS) $(B_INCLUDES) -g -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

fclean: clean
	@echo "🗑️  Removing executables..."
	@rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re