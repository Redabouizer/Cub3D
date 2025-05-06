/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:34:07 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 22:34:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	calculate_max_width(char **map_lines, int map_line_count)
{
	int	max_width;
	int	i;
	int	current_len;

	max_width = 0;
	i = 0;
	while (i < map_line_count)
	{
		current_len = ft_strlen(map_lines[i]);
		if (current_len > max_width)
			max_width = current_len;
		i++;
	}
	return (max_width);
}

void	finalize_map(t_mem **mn, t_map *map, char **map_lines, int map_l_count)
{
	int	max_width;
	int	i;

	max_width = calculate_max_width(map_lines, map_l_count);
	map->map = my_malloc(mn, sizeof(char *) * (map_l_count + 1));
	map->map_height = map_l_count;
	map->map_width = max_width;
	i = 0;
	while (i < map_l_count)
	{
		pad_map_line(mn, map, map_lines, i);
		free(map_lines[i]);
		i++;
	}
	free(map_lines);
}

static void	process_map_lines(t_mem **manager, int fd, t_map *map)
{
	char	*line;
	int		map_started;
	char	**map_lines;
	int		map_line_count;

	map_started = 0;
	map_lines = NULL;
	map_line_count = 0;
	line = read_fd(fd);
	while (line != NULL)
	{
		process_line(manager, map, line, &map_started, &map_lines, &map_line_count);
		line = read_fd(fd);
	}
	finalize_map(manager, map, map_lines, map_line_count);
}

t_map	*parse_map_file(t_mem **manager, const char *file)
{
	t_map	*map;
	int		fd;

	map = init_map(manager);
	if (!map)
		return (NULL);
	fd = open_fd(file);
	if (fd < 0)
		return (NULL);
	process_map_lines(manager, fd, map);
	if (close_fd(fd) < 0)
		return (NULL);
	return (map);
}
