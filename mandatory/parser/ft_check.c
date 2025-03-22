/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:35:08 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/22 21:11:09 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ex_ber(char *str, int i)
{
	if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b' && str[i + 4] == '\0')
	{
		return 0; 
	}
	return 1; 
}

int ft_one(char *str, int len)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
            return (ft_putendl_fd("Error : First and last lines must contain only '1'", 2), 1);
        i++;
    }
    if (i == len)
        return (0);
    return (ft_putendl_fd("Error : Line length must be consistent", 2), 1);
}

int ft_ml(char *str, int len)
{
    int i;
    int l;

    l = ft_strlen(str);
    i = 0;
    if (str[0] != '1' || str[l - 1] != '1')
        return (ft_putendl_fd("Error : Lines must start and end with '1'", 2), 1);
    while (str[i])
    {
        if (!ft_is_elem(str[i]))
            return (ft_putendl_fd("Error : Invalid character in the map", 2), 1);
        i++;
    }
    if (i == len)
        return (0);
    return (ft_putendl_fd("Error : Line length must be consistent", 2), 1);
}

int ft_check(char **str, int len)
{
    int i;
    int l;

    l = ft_strlen(str[0]);
    i = -1;
    while (str[++i])
    {
        if (i == 0 || i == (len - 1))
        {
            if (ft_one(str[i], l) == 1)
                return (1);
        }
        else
        {
            if (ft_ml(str[i], l) == 1)
                return (1);
        }
    }
    if ((ft_count(str, 'C') == 0) || (ft_count(str, 'E') != 1) || (ft_count(str, 'P') != 1))
        return (ft_putendl_fd("Error : There must be exactly one 'E', one 'P', and at least one 'C'", 2), 1);
    return (0);
}

int ft_stack(t_mem **mm, char *file)
{
    int i;
    char **str;
    char *s;
    int fd;
    int len;

    str = NULL;
    i = 0;
    len = fd_line(file);
    if (len < 0)
        return (-1);
    // fd = open_fd(file);
    // if (fd < 0)
    //     return (-1);
    // s = ft_allocat(mm ,fd);
    // str = ft_split_mm(mm, s, '\n');
    // if (!str || !s)
    //     return (ft_putendl_fd("Error : Empty place in file", 2), close(fd), -1);
    // if (ft_check(str, len) == 1)
    //     return (cleanup(&mm), close(fd), -1);
    // close(fd);
    return (0);
}