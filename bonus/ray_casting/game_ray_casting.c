/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:06:52 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 11:35:07 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	compute_ray_data(t_game_data *data, t_ray *ray_info, int x)
{
	ray_info->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray_info->ray_direction_x = data->player.direction_x
		+ data->player.plane_x * ray_info->camera_x;
	ray_info->ray_direction_y = data->player.direction_y
		+ data->player.plane_y * ray_info->camera_x;
	ray_info->map_x = (int)data->player.position_x;
	ray_info->map_y = (int)data->player.position_y;
	if (ray_info->ray_direction_x != 0)
		ray_info->delta_distance_x = fabs(1 / ray_info->ray_direction_x);
	else
		ray_info->delta_distance_x = 1e30;
	if (ray_info->ray_direction_y != 0)
		ray_info->delta_distance_y = fabs(1 / ray_info->ray_direction_y);
	else
		ray_info->delta_distance_y = 1e30;
}

void	compute_steps(t_game_data *data, t_ray *ray_info)
{
	if (ray_info->ray_direction_x < 0)
	{
		ray_info->step_x = -1;
		ray_info->side_distance_x = (data->player.position_x
				- ray_info->map_x) * ray_info->delta_distance_x;
	}
	else
	{
		ray_info->step_x = 1;
		ray_info->side_distance_x = (ray_info->map_x + 1.0
				- data->player.position_x) * ray_info->delta_distance_x;
	}
	if (ray_info->ray_direction_y < 0)
	{
		ray_info->step_y = -1;
		ray_info->side_distance_y = (data->player.position_y
				- ray_info->map_y) * ray_info->delta_distance_y;
	}
	else
	{
		ray_info->step_y = 1;
		ray_info->side_distance_y = (ray_info->map_y + 1.0
				- data->player.position_y) * ray_info->delta_distance_y;
	}
}

void	determine_texture(int *is_door, int *texture_num, t_ray *ray_info)
{
	if (*is_door)
	{
		*texture_num = 4;
	}
	else if (ray_info->side == 0)
	{
		if (ray_info->ray_direction_x > 0)
			*texture_num = 2;
		else
			*texture_num = 3;
	}
	else
	{
		if (ray_info->ray_direction_y > 0)
			*texture_num = 1;
		else
			*texture_num = 0;
	}
}

void	execute_dda(t_game_data *data, t_ray *ray_info)
{
	int		x;
	int		hit;
	int		is_door;
	t_wall	wall;

	1 && (x = 0, hit = 0, is_door = 0);
	while (x < SCREEN_WIDTH)
	{
		compute_ray_data(data, ray_info, x);
		compute_steps(data, ray_info);
		hit = 0;
		is_door = 0;
		process_wall_hit(data, ray_info, &hit, &is_door);
		calculate_wall_distance(ray_info, &wall, data);
		compute_line_height(&wall);
		determine_texture(&is_door, &wall.texture_number, ray_info);
		compute_wall_x(ray_info, &wall, data);
		render_texture(ray_info, x, &wall, data);
		x++;
	}
}

int	render_scene(t_game_data *data)
{
	t_ray	*ray_info;

	ray_info = &data->raycaster;
	render_floor_and_ceiling(data);
	execute_dda(data, ray_info);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}
