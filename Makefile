# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 20:10:05 by rbouizer          #+#    #+#              #
#    Updated: 2025/05/05 22:32:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/get_next_line/get_next_line.c\
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
	mandatory/parser/test.c\
	mandatory/main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
CC = cc
RM = rm -rf
NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c mandatory/includes/cub3d.h  mandatory/get_next_line/get_next_line.h mandatory/utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all