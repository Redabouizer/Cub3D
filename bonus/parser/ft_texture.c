/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:42:02 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/12 11:31:56 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	load_single_texture(t_game_data *data, char *path, size_t index)
{
	int	dummy_width_height;

	data->textures[index].img = mlx_xpm_file_to_image(
			data->mlx, path, &dummy_width_height, &dummy_width_height);
	if (!data->textures[index].img)
	{
		printf("Error: Failed to load texture from '%s'\n", path);
		return (0);
	}
	data->textures[index].addr = mlx_get_data_addr(
			data->textures[index].img,
			&data->textures[index].bits_per_pixel,
			&data->textures[index].line_length,
			&data->textures[index].endian);
	if (!data->textures[index].addr)
	{
		printf("Error: Failed to get texture data address\n");
		mlx_destroy_image(data->mlx, data->textures[index].img);
		return (0);
	}
	return (1);
}

int	load_textures(t_game_data *data, t_map *map)
{
	char	**paths;
	size_t	index;

	paths = allocate_texture_paths(data, map);
	if (!paths)
		return (1);
	index = 0;
	while (index < 5)
	{
		if (!load_single_texture(data, paths[index], index))
		{
			cleanup_textures(data, index);
			free_path(paths);
			return (1);
		}
		index++;
	}
	free_path(paths);
	return (0);
}

static void	calculate_texture_x(t_ray *ray_info, t_wall *wall)
{
	if (wall->texture_number < 0 || wall->texture_number >= 5)
		return ;
	wall->texture_x = (int)(wall->wall_x * (double)TEXTURE_HEIGHT);
	if (ray_info->side == 0 && ray_info->ray_direction_x > 0)
		wall->texture_x = TEXTURE_SIZE - wall->texture_x - 1;
	if (ray_info->side == 1 && ray_info->ray_direction_y < 0)
		wall->texture_x = TEXTURE_SIZE - wall->texture_x - 1;
}

void	render_wall_stripe(t_ray *ray_info, int x,
	t_wall *wall, t_game_data *data)
{
	double			texture_step;
	double			texture_position;
	unsigned int	pixel_color;
	int				pixel_y;

	texture_step = 1.0 * TEXTURE_HEIGHT / wall->line_height;
	texture_position = (wall->draw_start - SCREEN_HEIGHT / 2
			+ wall->line_height / 2) * texture_step;
	pixel_y = wall->draw_start;
	while (pixel_y < wall->draw_end)
	{
		wall->texture_y = (int)texture_position & (TEXTURE_HEIGHT - 1);
		texture_position += texture_step;
		pixel_color = get_texture_color(data->textures + wall->texture_number,
				wall->texture_y, wall->texture_x);
		if (ray_info->side == 1)
			pixel_color = (pixel_color >> 1) & 8355711;
		put_pixel_to_mlx(data, x, pixel_y, pixel_color);
		pixel_y++;
	}
}

void	render_texture(t_ray *ray_info, int x, t_wall *wall, t_game_data *data)
{
	calculate_texture_x(ray_info, wall);
	render_wall_stripe(ray_info, x, wall, data);
}
