/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection_pro.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:05:15 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 02:57:33 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_x_step_and_side(t_ray *collision_ray, double start_x)
{
	if (collision_ray->ray_direction_x < 0)
	{
		collision_ray->step_x = -1;
		collision_ray->side_distance_x = (start_x - collision_ray->map_x) \
			* collision_ray->delta_distance_x;
	}
	else
	{
		collision_ray->step_x = 1;
		collision_ray->side_distance_x = (collision_ray->map_x + 1.0 - start_x) \
			* collision_ray->delta_distance_x;
	}
}

static void	set_y_step_and_side(t_ray *collision_ray, double start_y)
{
	if (collision_ray->ray_direction_y < 0)
	{
		collision_ray->step_y = -1;
		collision_ray->side_distance_y = (start_y - collision_ray->map_y) \
			* collision_ray->delta_distance_y;
	}
	else
	{
		collision_ray->step_y = 1;
		collision_ray->side_distance_y = (collision_ray->map_y + 1.0 - start_y) \
			* collision_ray->delta_distance_y;
	}
}

void	initialize_collision_ray(t_ray *collision_ray, t_ray_init *init_data)
{
	collision_ray->ray_direction_x = init_data->direction_x;
	collision_ray->ray_direction_y = init_data->direction_y;
	collision_ray->map_x = (int)init_data->start_x;
	collision_ray->map_y = (int)init_data->start_y;
	set_delta_distances(collision_ray);
	set_x_step_and_side(collision_ray, init_data->start_x);
	set_y_step_and_side(collision_ray, init_data->start_y);
}

int	check_collision(t_game_data *game_data, t_ray *collision_ray)
{
	if (collision_ray->map_x < 0 || collision_ray->map_x >= game_data->map_width
		|| collision_ray->map_y < 0 \
		|| collision_ray->map_y >= game_data->map_height)
		return (1);
	if (game_data->level_map[collision_ray->map_y][collision_ray->map_x] == 1)
		return (1);
	if (game_data->level_map[collision_ray->map_y][collision_ray->map_x] == 2
		&& !is_door_accessible(game_data, collision_ray->map_x,
			collision_ray->map_y))
		return (1);
	return (0);
}

void	update_ray_position(t_ray *collision_ray)
{
	if (collision_ray->side_distance_x < collision_ray->side_distance_y)
	{
		collision_ray->side_distance_x += collision_ray->delta_distance_x;
		collision_ray->map_x += collision_ray->step_x;
		collision_ray->side = 0;
	}
	else
	{
		collision_ray->side_distance_y += collision_ray->delta_distance_y;
		collision_ray->map_y += collision_ray->step_y;
		collision_ray->side = 1;
	}
}
