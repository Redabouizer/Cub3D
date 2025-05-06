/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:39:07 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 22:39:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	process_initial_line(char *trim, int *tab, int *map_on, char **fst_map_l)
{
	if (process_meta_line(trim, tab))
		return (1);
	if (check_map(trim))
	{
		*map_on = 1;
		*fst_map_l = ft_strdup(trim);
		if (!validate_continuous_ones(*fst_map_l))
			return (printf("Error: First line invalid\n"), 0);
		return (1);
	}
	return (0);
}

int	process_line_content(char **line, int *map_on, int *map_ended, int *tab,
							int *ply_count, char **first_map_line, char **last_mp_l)
{
	char	*trim;

	trim = ft_strtrim(*line, " \t\n\r");
	free(*line);
	if (!trim || trim[0] == '\0')
	{
		if (*map_on)
			*map_ended = 1;
		free(trim);
		return (1);
	}
	if (!*map_on && !process_initial_line(trim, tab, map_on, first_map_line))
		return (printf("Error: Invalid line\n"), free(trim), 0);
	if (*map_on && !validate_map_section_wrapper(trim, map_ended, last_mp_l))
		return (free(trim), 0);
	if (*map_on)
		check_player_count(trim, ply_count);
	free(trim);
	return (1);
}

int	process_file_lines(int fd, int *tab, int *ply_count)
{
	char	*line;
	int		map_on;
	int		map_ended;
	char	*first_map_line;
	char	*last_map_line;

	map_on = 0;
	map_ended = 0;
	first_map_line = NULL;
	last_map_line = NULL;
	line = read_fd(fd);
	while (line != NULL)
	{
		if (!process_line_content(&line, &map_on, &map_ended, tab, ply_count,
				&first_map_line, &last_map_line))
			return (0);
		line = read_fd(fd);
	}
	return (validate_final_map_state(first_map_line, last_map_line));
}

int	process_file(const char *file)
{
	int	tab[6];
	int	ply_count;
	int	fd;

	ft_bzero(tab, sizeof(tab));
	ply_count = 0;
	fd = open_fd(file);
	if (fd < 0)
		return (-1);
	if (!process_file_lines(fd, tab, &ply_count))
		return (close_fd(fd), -1);
	if (close_fd(fd) < 0)
		return (-1);
	if (tab[0] != 1 || tab[1] != 1 || tab[2] != 1 || tab[3] != 1
		|| tab[4] != 1 || tab[5] != 1 || ply_count != 1)
		return (printf("Validation failed\n"), -1);
	return (0);
}

void	process_line(t_mem **manager, t_map *map, char *line,
						int *map_started, char ***map_lines, int *map_line_count)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\t\n\r");
	free(line);
	if (!trimmed)
		return ;
	if (trimmed[0] == '\0' && !(*map_started))
	{
		free(trimmed);
		return ;
	}
	if (!(*map_started))
		process_metadata_line(manager, map, trimmed, map_started, map_lines, map_line_count);
	else if (check_map(trimmed))
		add_map_line(manager, map_lines, trimmed, map_line_count);
	free(trimmed);
}
