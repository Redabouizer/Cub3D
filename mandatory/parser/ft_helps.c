/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:27:42 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/14 01:30:17 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_position(char **map, t_point pos, int map_height)
{
	int	x;
	int	y;

	x = (int)pos.x_p;
	y = (int)pos.y_p;
	if (x < 0 || x >= map_height || map[x] == NULL)
		return (0);
	if (y < 0 || y >= (int)ft_strlen(map[x]))
		return (0);
	return (1);
}

void	set_position(t_point *point, double x, double y)
{
	point->x_p = x;
	point->y_p = y;
}

int	check_adjacent(char **map, t_point pos, int map_height)
{
	int	x;
	int	y;

	x = (int)pos.x_p;
	y = (int)pos.y_p;
	if (!is_valid_position(map, pos, map_height))
		return (0);
	return (map[x][y] == ' ');
}

int	zero_space(char **map, int i, int j, int map_height)
{
	t_point	up;
	t_point	down;
	t_point	right;
	t_point	left;

	set_position(&up, i - 1, j);
	set_position(&down, i + 1, j);
	set_position(&right, i, j + 1);
	set_position(&left, i, j - 1);
	if (check_adjacent(map, up, map_height)
		|| check_adjacent(map, down, map_height)
		|| check_adjacent(map, right, map_height)
		|| check_adjacent(map, left, map_height))
	{
		return (0);
	}
	return (1);
}

int	check_zero_space(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	if (map_data->map == NULL)
		return (1);
	while (i < map_data->map_height)
	{
		j = 0;
		while (map_data->map[i][j] != '\0')
		{
			if ((map_data->map[i][j] == '0' || map_data->map[i][j] == 'N'
				|| map_data->map[i][j] == 'S' || map_data->map[i][j] == 'E'
				|| map_data->map[i][j] == 'W') && \
				!zero_space(map_data->map, i, j, map_data->map_height))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
