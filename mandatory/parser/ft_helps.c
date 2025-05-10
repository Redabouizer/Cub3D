/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:39:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/10 05:53:28 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int is_valid_position(char **map, t_point pos)
{
    int x = (int)pos.x_p;
    int y = (int)pos.y_p;
        if (x < 0 || map[x] == NULL)
        return 0;
    if (y < 0 || y >= (int)strlen(map[x]))
        return 0;
    return 1;
}

void set_position(t_point *point, double x, double y)
{
    point->x_p = x;
    point->y_p = y;
}

int check_adjacent(char **map, t_point pos)
{
    int x = (int)pos.x_p;
    int y = (int)pos.y_p;
    
    if (!is_valid_position(map, pos))
        return 0;
    
    return (map[x][y] == ' ');
}

int zero_space(char **map, int i, int j)
{
    t_point up, down, right, left;

    set_position(&up, i - 1, j);
    set_position(&down, i + 1, j);
    set_position(&right, i, j + 1);
    set_position(&left, i, j - 1);

    if (check_adjacent(map, up) ||
        check_adjacent(map, down) ||
        check_adjacent(map, right) ||
        check_adjacent(map, left))
    {
        return 0;
    }
    return 1;
}

int check_zero_space(char **map)
{
    int i = 0;
    int j;
    
    if (map == NULL)
        return 1;
    
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == '0' && !zero_space(map, i, j))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}