/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 04:42:10 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 04:52:36 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	compute_wall_x(t_ray *ray_info, t_wall *wall, t_game_data *data)
{
	if (ray_info->side == 0)
		wall->wall_x = data->player.position_y \
			+ wall->distance_to_wall * ray_info->ray_direction_y;
	else
		wall->wall_x = data->player.position_x \
			+ wall->distance_to_wall * ray_info->ray_direction_x;
	wall->wall_x -= floor(wall->wall_x);
}

void	render_floor_and_ceiling(t_game_data *data)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < SCREEN_HEIGHT / 2)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			put_pixel_to_mlx(data, col, row, data->ceiling_color);
			put_pixel_to_mlx(data, col, SCREEN_HEIGHT \
				- row - 1, data->floor_color);
			col++;
		}
		row++;
	}
}

void	release_textures(char **file_paths)
{
	int	index;

	index = 0;
	while (index < 5)
	{
		free(file_paths[index]);
		index++;
	}
	free(file_paths);
}

void	free_gnl(void)
{
	get_next_line(-1, true);
}
