/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:27:42 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/12 02:21:08 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_position(char **map, t_point pos)
{
	int	x;
	int	y;

	x = (int)pos.x_p;
	y = (int)pos.y_p;
	if (x < 0 || map[x] == NULL)
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

int	check_adjacent(char **map, t_point pos)
{
	int	x;
	int	y;

	x = (int)pos.x_p;
	y = (int)pos.y_p;
	if (!is_valid_position(map, pos))
		return (0);
	return (map[x][y] == ' ');
}

int	zero_space(char **map, int i, int j)
{
	t_point	up;
	t_point	down;
	t_point	right;
	t_point	left;

	set_position(&up, i - 1, j);
	set_position(&down, i + 1, j);
	set_position(&right, i, j + 1);
	set_position(&left, i, j - 1);
	if (check_adjacent(map, up)
		|| check_adjacent(map, down)
		||check_adjacent(map, right)
		||check_adjacent(map, left))
	{
		return (0);
	}
	return (1);
}

int	check_zero_space(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (map == NULL)
		return (1);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W') && !zero_space(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
