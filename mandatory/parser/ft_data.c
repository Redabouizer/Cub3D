/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:08:17 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 11:10:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	process_metadata(t_map *map, char *trimmed)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		map->north_texture = ft_strtrim(trimmed + 3, " \t\n\r\f\v");
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		map->south_texture = ft_strtrim(trimmed + 3, " \t\n\r\f\v");
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		map->west_texture = ft_strtrim(trimmed + 3, " \t\n\r\f\v");
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		map->east_texture = ft_strtrim(trimmed + 3, " \t\n\r\f\v");
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
		get_color(trimmed + 2, &map->floor_color);
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
		get_color(trimmed + 2, &map->ceiling_color);
}

void	process_metadata_line(t_mem **manager, char *trim, t_line_proc *proc)
{
	process_metadata(proc->map, trim);
	if (check_map(trim))
	{
		*(proc->map_started) = 1;
		add_map_line(manager, proc->map_lines, trim, proc->map_line_count);
	}
}
