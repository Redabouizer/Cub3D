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
		// Remove the free(map_lines[i]) since cleanup will handle it
		i++;
	}
	free(map_lines); // This is okay since it's not managed by the memory manager
}

void space_to_one(t_map *map)
{
    int i;
    int j;

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