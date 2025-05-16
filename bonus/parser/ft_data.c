/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:20:24 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/12 11:34:56 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	retrieve_texture_color(t_texture *texture, int y, int x)
{
	char	*destination;

	if (!texture || !texture->addr)
		return (0xFF0000);
	destination = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)destination);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	validate_map_borders(const char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (line[0] != '1' || line[len - 1] != '1'))
		return (0);
	return (1);
}

int	process_metadata(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (set_texture(&map->north_texture, line));
	else if (!ft_strncmp(line, "SO ", 3))
		return (set_texture(&map->south_texture, line));
	else if (!ft_strncmp(line, "WE ", 3))
		return (set_texture(&map->west_texture, line));
	else if (!ft_strncmp(line, "EA ", 3))
		return (set_texture(&map->east_texture, line));
	else if (!ft_strncmp(line, "F ", 2))
		return (get_color(line + 2, &map->floor_color));
	else if (!ft_strncmp(line, "C ", 2))
		return (get_color(line + 2, &map->ceiling_color));
	else if (!check_texture("bonus/textures/door.xpm"))
		return (printf("Error: Texture Door not found"), 0);
	return (1);
}

int	process_metadata_line(t_mem **manager, char *trim, t_line_proc *proc)
{
	int	result;

	if (!process_metadata(proc->map, trim))
		return (free(trim), 0);
	if (check_map(trim))
	{
		*(proc->map_started) = 1;
		result = add_map_line(manager, proc->map_lines,
				trim, proc->map_line_count);
	}
	else
		result = 1;
	free(trim);
	return (result);
}
