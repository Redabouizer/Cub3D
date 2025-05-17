/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:39:44 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 02:29:28 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	free_textures_pro(t_game_data *data)
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
}

void	free_images(t_game_data *data)
{
	if (!data)
		return ;
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
}

void	free_all(t_game_data *data, t_map *map, int flag)
{
	if (!data)
		return ;
	free_textures_pro(data);
	free_images(data);
	free_worldmap(data);
	if (map && flag)
		free_map_resources(map);
}
