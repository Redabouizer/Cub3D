/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:34:08 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/11 18:34:09 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s && fd)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
