/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:27:10 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/11 16:27:13 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	open_fd(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nTHIS FILE DOES NOT EXIST", 2), -1);
	return (fd);
}

char	*read_fd(int fd)
{
	char	*str;

	str = get_next_line(fd, false);
	return (str);
}

int	close_fd(int fd)
{
	if (close(fd) == -1)
		return (ft_putendl_fd("Error\nPROBLEM ON CLOSING", 2), -1);
	return (0);
}
