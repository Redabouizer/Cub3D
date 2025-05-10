/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:00 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/10 21:02:27 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_mem	*mm;
	char	*file;
	int		ext_valid;

	mm = NULL;
	if (argc != 2)
	{
		ft_putendl_fd("Error: Incorrect arguments. Usage: ./cub3d", 2);
		return (1);
	}
	file = argv[1];
	ext_valid = check_ext(file);
	if (ext_valid == 1)
	{
		ft_putendl_fd("Error: Incorrect file extension. Expected .cub", 2);
		return (1);
	}
	if (validate_map(&mm, file) == -1)
		return (1);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	char * str;
// 	if (argc == 2)
// 	{
// 		printf("ascsa");
// 		int fd  = open_fd(argv[1]);
// 		str = read_fd(fd);
// 		while (str)
// 		{
// 			printf("%s", str);
// 			free(str);
// 			exit (0);
// 			str = read_fd(fd);
// 		}
// 		close_fd(fd);
// 		return (0);
// 	}
// }
