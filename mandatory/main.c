/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:28:17 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 13:28:30 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void check_leaks()
{
    system("leaks cub3d");
}

int	main(int argc, char *argv[])
{
	t_mem	*mm;
	char	*file;
	int		ext_valid;

	atexit(check_leaks);
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
