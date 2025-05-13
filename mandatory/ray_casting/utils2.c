/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:31:17 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 01:36:24 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map_array(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < map->map_height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}

void	free_file_content(t_map *map)
{
	int	i;

	if (!map || !map->file_content)
		return ;
	i = 0;
	while (map->file_content[i])
	{
		free(map->file_content[i]);
		i++;
	}
	free(map->file_content);
	map->file_content = NULL;
}

void	free_textures(t_map *map)
{
	if (!map)
		return ;
	if (map->north_texture)
	{
		free(map->north_texture);
		map->north_texture = NULL;
	}
	if (map->south_texture)
	{
		free(map->south_texture);
		map->south_texture = NULL;
	}
	if (map->east_texture)
	{
		free(map->east_texture);
		map->east_texture = NULL;
	}
	if (map->west_texture)
	{
		free(map->west_texture);
		map->west_texture = NULL;
	}
}
