/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:09:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/22 20:39:53 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../utils/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_mem
{
	void			*ptr;
	struct s_mem	*next;
}				t_mem;

int open_fd(char *file);
char *read_fd(int fd);
int close_fd(int fd);

char *ft_allocat(int fd);
void	*my_malloc(t_mem **manager, size_t size);
void	cleanup(t_mem **manager);

int ex_ber(char *str, int i);
int fd_line(char *file);
int ft_count (char **strs, char c);

int ft_stack(char *file);

#endif
