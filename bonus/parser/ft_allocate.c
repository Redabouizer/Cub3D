/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:18:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 13:08:53 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**allocate_texture_paths(t_game_data *data, t_map *map)
{
	char	**paths;
	int		i;

	paths = malloc(sizeof(char *) * 5);
	if (!paths)
	{
		free_all(data, map, 0);
		exit(EXIT_FAILURE);
	}
	paths[0] = ft_strdup(map->north_texture);
	paths[1] = ft_strdup(map->south_texture);
	paths[2] = ft_strdup(map->east_texture);
	paths[3] = ft_strdup(map->west_texture);
	(1) && (i = -1, paths[4] = ft_strdup("bonus/textures/door.xpm"));
	while (++i < 5)
	{
		if (!paths[i])
		{
			free_path(paths);
			free_all(data, map, 0);
			perror("Error: Texture failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (paths);
}

void	cleanup_textures(t_game_data *data, size_t loaded_count)
{
	while (loaded_count-- > 0)
		mlx_destroy_image(data->mlx, data->textures[loaded_count].img);
}
