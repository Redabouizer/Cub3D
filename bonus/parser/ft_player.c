/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:35:04 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/14 01:28:26 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_strings(char **values)
{
	int	count;

	count = 0;
	if (!values)
		return (0);
	while (values[count])
		count++;
	return (count);
}

void	process_player_pos(t_map *map, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (ft_strchr("NSEW", line[x]))
		{
			map->player_x = x;
			map->player_y = y;
			map->player_direction = line[x];
			map->map[y][x] = '0';
		}
		x++;
	}
}

void	space_to_one(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	pad_map_line(t_mem **m, t_map *map, char **lines, int i)
{
	char	*padded;
	int		j;

	padded = my_malloc(m, map->map_width + 1);
	j = 0;
	while (j < (int)ft_strlen(lines[i]))
	{
		if (lines[i][j] == ' ')
			padded[j] = ' ';
		else
			padded[j] = lines[i][j];
		j++;
	}
	while (j < map->map_width)
		padded[j++] = ' ';
	padded[map->map_width] = '\0';
	map->map[i] = padded;
	process_player_pos(map, lines[i], i);
}
