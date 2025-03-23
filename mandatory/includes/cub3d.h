/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:09:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/23 07:20:25 by rbouizer         ###   ########.fr       */
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

typedef struct s_map
{
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;
    int floor_color[3];
    int ceiling_color[3];
    char **map;
    int map_width;
    int map_height;
    int player_x;
    int player_y;
    char player_dir;
}	t_map;

int open_fd(const char *file);
char *read_fd(int fd);
int close_fd(int fd);

t_map	*init_map(t_mem **manager);
char *ft_allocat(int fd);
void	*my_malloc(t_mem **manager, size_t size);
void	cleanup(t_mem **manager);

int check_ext(char *file);
int fd_line(char *file);
int ft_count (char **strs, char c);

int validate_map(t_mem **mm, const char *file) ;

char	*ft_strjoin_mm(t_mem **manager, char const *s1, char const *s2);
char	**ft_split_mm(t_mem **manager, char const *s, char c);


#endif
