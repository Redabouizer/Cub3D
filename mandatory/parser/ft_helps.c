/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:39:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/23 06:42:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// int ft_check()
// {
	
// }

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