/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:32:42 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/14 01:27:33 by rbouizer         ###   ########.fr       */
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
		i++;
	}
	free(map_lines);
}

int	process_map_lines(t_mem **manager, int fd, t_map *map)
{
	char		*line;
	t_line_proc	proc;
	char		**map_lines;
	int			map_started;
	int			map_line_count;

	map_lines = NULL;
	map_started = 0;
	map_line_count = 0;
	proc.map = map;
	proc.map_started = &map_started;
	proc.map_lines = &map_lines;
	proc.map_line_count = &map_line_count;
	line = read_fd(fd);
	while (line != NULL)
	{	
		if (!process_line(manager, line, &proc))
			return (0);
		line = read_fd(fd);
	}
	finalize_map(manager, map, map_lines, map_line_count);
	if (map->map && !check_zero_space(map))
		return (ft_putendl_fd("Error: Invalid zero in map", 2), 0);
	space_to_one(map);
	return (1);
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
		return (free_map_resources(map), NULL);
	if (!process_map_lines(manager, fd, map))
		return (free_map_resources(map), NULL);
	map->mm = manager;
	if (close_fd(fd) < 0)
		return (free_map_resources(map), NULL);
	return (map);
}
