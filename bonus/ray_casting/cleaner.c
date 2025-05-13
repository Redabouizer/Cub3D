/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:39:44 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 04:40:12 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_images(t_game_data *data)
{
	if (!data)
		return ;
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
}

void	free_window(t_game_data *data)
{
	if (!data)
		return ;
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
}

void	free_level_map(t_game_data *data)
{
	int	i;

	if (!data || !data->level_map)
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

void	free_mlx(t_game_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
	{
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_all(t_game_data *data, t_map *map, int flag)
{
	if (!data)
		return ;
	free_textures(data);
	free_images(data);
	free_window(data);
	free_level_map(data);
	if (map && flag)
		free_map_resources(map);
	free_mlx(data);
}
