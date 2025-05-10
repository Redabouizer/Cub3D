/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:19:47 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/10 03:22:50 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1024

typedef struct s_gnl
{
    char    *buffer;
    int     fd;
}   t_gnl;

char    *get_next_line(int fd);
t_gnl   *gnl_init(int fd);
void    gnl_cleanup(t_gnl **gnl_data);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif