/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:39:44 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/11 21:36:09 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_array_text(t_game_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx, data->textures[i].img);
		i++;
	}
}

void	display_destruction(t_game_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
}

void	free_worldmap(t_game_data *data)
{
	int	i;

	if (!data->level_map)
		return ;
	i = 0;
	while (i < data->map_height)
	{
		free(data->level_map[i]);
		i++;
	}
	free(data->level_map);
	data->level_map = NULL;
}

void	free_all(t_game_data *data, t_map *map, int flag)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (i < 4)
	{
		if (data->textures[i].img)
		{
			mlx_destroy_image(data->mlx, data->textures[i].img);
			data->textures[i].img = NULL;
		}
		i++;
	}
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->level_map)
	{
		i = 0;
		while (i < data->map_height)
		{
			free(data->level_map[i]);
			i++;
		}
		free(data->level_map);
		data->level_map = NULL;
	}
	if (map && flag)
		free_map_resources(map);
	if (data->mlx)
	{
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_path(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (i < 5)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
