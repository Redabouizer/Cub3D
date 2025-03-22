# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 20:10:05 by rbouizer          #+#    #+#              #
#    Updated: 2025/03/22 20:28:00 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/get_next_line/get_next_line.c\
	mandatory/get_next_line/get_next_line_utils.c\
	mandatory/utils/ft_split.c\
	mandatory/utils/ft_strlcpy.c\
	mandatory/utils/ft_putendl_fd.c\
	mandatory/utils/ft_putstr_fd.c\
	mandatory/utils/ft_putchar_fd.c\
	mandatory/parser/ft_fd.c\
	mandatory/parser/ft_helps.c\
	mandatory/parser/mem.c\
	mandatory/parser/ft_check.c\
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