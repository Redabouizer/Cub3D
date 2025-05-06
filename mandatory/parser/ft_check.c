/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:47:27 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 01:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_map_borders(const char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (line[0] != '1' || line[len - 1] != '1'))
		return (0);
	return (1);
}

int	validate_map_section(char *trimmed, int *map_ended, char **last_line)
{
	if (!check_map(trimmed))
		return (printf("Error: Non-map line detected\n"), 0);
	if (*map_ended)
		return (printf("Error: Double map detected\n"), 0);
	if (!validate_map_borders(trimmed))
		return (printf("Error: Invalid map borders\n"), 0);
	if (*last_line)
		free(*last_line);
	*last_line = ft_strdup(trimmed);
	return (1);
}

int	validate_map_section_wrapper(char *trim, int *mp_end, char **lst_mp_l)
{
	if (*mp_end)
		return (printf("Error: Map content after empty line\n"), 0);
	return (validate_map_section(trim, mp_end, lst_mp_l));
}

int	validate_final_map_state(char *first_map_line, char *last_map_line)
{
	if (last_map_line && !validate_continuous_ones(last_map_line))
		return (printf("Error: Last line invalid\n"), 0);
	cleanup_map_lines(first_map_line, last_map_line);
	return (1);
}

int	validate_map(t_mem **mm, const char *file)
{
	t_map	*map;

	(void)mm;
	if (process_file(file) != 0)
		return (-1);
	map = parse_map_file(mm, file);
	print_map_data(map);
	return (0);
}