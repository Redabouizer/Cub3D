/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:33:40 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/11 17:08:26 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*init_map(t_mem **manager)
{
	t_map	*map;

	map = (t_map *)my_malloc(manager, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->player_direction = '\0';
	map->map_width = 0;
	map->map_height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->file_content = NULL;
	map->map = NULL;
	map->mm = manager;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	return (map);
}

int	add_map_line(t_mem **manager, char ***lines, char *trimmed, int *count)
{
	char	**new_lines;
	int		i;

	if (!manager || !lines || !trimmed || !count)
		return (0);
	new_lines = my_malloc(manager, sizeof(char *) * (*count + 2));
	if (!new_lines)
		return (0);
	i = 0;
	while (i < *count)
	{
		new_lines[i] = (*lines)[i];
		i++;
	}
	new_lines[*count] = my_malloc(manager, ft_strlen(trimmed) + 1);
	if (!new_lines[*count])
		return (free(new_lines), 0);
	ft_strlcpy(new_lines[*count], trimmed, ft_strlen(trimmed) + 1);
	(*count)++;
	new_lines[*count] = NULL;
	*lines = new_lines;
	return (1);
}

int	free_values(char **values)
{
	int	i;

	if (!values)
		return (0);
	i = 0;
	while (values && values[i])
		free(values[i++]);
	free(values);
	return (0);
}

void	cleanup_map_lines(char *first_map_line, char *last_map_line)
{
	if (first_map_line)
		free(first_map_line);
	if (last_map_line)
		free(last_map_line);
}
