/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:39:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/05 23:26:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// int fd_line(char *file)
// {
//     char *str;
//     int fd;
//     int i;

//     i = 0;
//     fd = open_fd(file);
//     if (fd < 0)
//         return (-1);
//     str = read_fd(fd);
//     while (str != NULL)
//     {
//         free(str);
//         str = read_fd(fd);
//         i++;
//     }
//     if (close_fd(fd) < 0)
//         return (-1);
//     return i;
// }

// int ft_count (char **strs, char c)
// {
// 	int i;
// 	int nbr;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	while (strs[i])
// 	{
// 		nbr = 0;
// 		while (strs[i][nbr])
// 		{
// 			if(strs[i][nbr] == c)
// 				count++;
// 			nbr++;
// 		}
// 		i++;
// 	}
// 	return count;
// }

// char *ft_allocat(t_mem **mm, int fd )
// {
//     int i;
// 	char *str;
// 	char *str1;

// 	str1 = NULL;
// 	str = read_fd(fd);
//     while (str != NULL)
//     {
//         i = 0;
//         while(str[i]  == ' ' &&  str[i]  != '\n')
//             i++;
//         if(str[i]  == '\n')
//             return (cleanup(&mm), free(str), NULL);
// 		str1 = ft_strjoin_mm(mm, str1, str);
//         free(str);
//         str = read_fd(fd);
//     }
//     return str1;
// }