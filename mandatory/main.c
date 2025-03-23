/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:00 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/23 07:20:40 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char *argv[]) {
    t_mem *mm = NULL;
    char *file;
    int ext_valid;

    if (argc != 2) {
        ft_putendl_fd("Error: Incorrect arguments. Usage: ./cub3d <map_file>", 2);
        return 1;
    }

    file = argv[1];
    ext_valid = check_ext(file);

    if (ext_valid == 1) {
        ft_putendl_fd("Error: Incorrect file extension. Expected .cub", 2);
        return 1;
    }

    if (validate_map(&mm, file) == -1) {
        return 1;
    }

    return 0;
}