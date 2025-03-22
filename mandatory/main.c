/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:00 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/22 20:42:48 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char *av[])
{
    char    *file;
    int     i;
    int     e;
    t_mem	*mm;

    if (ac == 2)
    {
        file = av[1]; 
        i = 0;
        e = 1;
        while (file[i])
        {
            if ((e = ex_ber(file, i)) == 0)
                break;
            i++;
        }
        if (e == 1)
           return (ft_putendl_fd("Error : INCORRECT EXTENTION", 2), 1);
        else if(ft_stack(&mm ,file) == -1)
            return (1);
    }
    else
        return (ft_putendl_fd("Error : ARGUMENT INCORRECT", 2), 1);
    return (0);
}
