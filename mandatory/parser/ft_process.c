/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:36:42 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 12:59:23 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	proc_init(char *trim, int *tab, int *map_on, char **fst_map_l)
{
	if (process_meta_line(trim, tab))
		return (1);
	if (check_map(trim))
	{
		*map_on = 1;
		*fst_map_l = ft_strdup(trim);
		if (!*fst_map_l)
			return (perror("Error: Memory allocation failed\n"), 0);
		if (!validate_continuous_ones(*fst_map_l))
		{
			free(*fst_map_l);
			*fst_map_l = NULL;
			return (perror("Error: First line invalid\n"), 0);
		}
		return (1);
	}
	return (0);
}

int	process_line_content(char **line, t_line_content *cnt, int *tab)
{
	char	*trim;

	trim = ft_strtrim(*line, " \t\n\r");
	free(*line);
	*line = NULL;
	if (!trim)
		return (perror("Error: Memory allocation failed\n"), 0);
	if (trim[0] == '\0')
	{
		if (cnt->map_on)
			cnt->map_end = 1;
		return (free(trim), 1);
	}
	if (!cnt->map_on)
	{
		if (!proc_init(trim, tab, &cnt->map_on, &cnt->first_mp_l))
			return (free(trim), 0);
	}
	else
	{
		if (!validate_wrapper(trim, &cnt->map_end, &cnt->last_mp_l))
			return (free(trim), 0);
		check_player_count(trim, cnt->ply_count);
	}
	return (free(trim), 1);
}

int	process_file_lines(t_file_lines *fl)
{
	char	*line;

	fl->content.map_on = 0;
	fl->content.map_end = 0;
	fl->content.first_mp_l = NULL;
	fl->content.last_mp_l = NULL;
	line = read_fd(fl->fd);
	while (line != NULL)
	{
		if (!process_line_content(&line, &fl->content, fl->tab))
		{
			free(line);
			free(fl->content.first_mp_l);
			free(fl->content.last_mp_l);
			return (0);
		}
		line = read_fd(fl->fd);
	}
	return (validate_state(fl->content.first_mp_l, fl->content.last_mp_l));
}

int	process_file(const char *file)
{
	int				tab[6];
	int				ply_count;
	int				fd;
	t_file_lines	fl;

	ft_bzero(tab, sizeof(tab));
	ply_count = 0;
	fd = open_fd(file);
	if (fd < 0)
		return (-1);
	fl.fd = fd;
	fl.tab = tab;
	fl.content.ply_count = &ply_count;
	if (!process_file_lines(&fl))
		return (perror("Validation failed\n"), close_fd(fd), -1);
	if (close_fd(fd) < 0)
		return (-1);
	if (tab[0] != 1 || tab[1] != 1 || tab[2] != 1 || tab[3] != 1
		|| tab[4] != 1 || tab[5] != 1 || ply_count != 1)
		return (perror("Validation failed\n"), -1);
	return (0);
}

int	process_line(t_mem **manager, char *line, t_line_proc *proc)
{
	char	*trimmed;

	if (!line)
		return (1);
	trimmed = ft_strtrim(line, "\t\n\r");
	free(line);
	if (!trimmed)
		return (1);
	if (trimmed[0] == '\0' && !(*proc->map_started))
		return (free(trimmed), 1);
	if (!(*proc->map_started))
		return (process_metadata_line(manager, trimmed, proc));
	else if (check_map(trimmed))
	{
		if (!add_map_line(manager, proc->map_lines,
				trimmed, proc->map_line_count))
			return (free(trimmed), 0);
		free(trimmed);
	}
	else
	{
		perror("Error: Invalid line in map section\n");
		return (free(trimmed), 0);
	}
	return (1);
}
