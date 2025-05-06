/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:31:53 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 11:37:22 by marvin           ###   ########.fr       */
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
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	return (map);
}

void add_map_line(t_mem **m, char ***lines, char *trimmed, int *count)
{
    char **new_lines;
    int i;

    new_lines = my_malloc(m, sizeof(char *) * (*count + 1));
    if (*count > 0 && *lines)
    {
        for (i = 0; i < *count; i++)
            new_lines[i] = (*lines)[i];
        free(*lines);
    }
    new_lines[*count] = ft_strdup(trimmed);
    (*count)++;
    *lines = new_lines;
}

int	free_values(char **values)
{
	int	i;

	i = 0;
	while (values && values[i])
		free(values[i++]);
	free(values);
	return (0);
}

void	cleanup_map_lines(char *first_map_line, char *last_map_line)
{
	free(first_map_line);
	free(last_map_line);
}
