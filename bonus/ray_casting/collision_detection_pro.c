/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection_pro.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:57:27 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 06:16:12 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	process_movement(t_game_data *game_data, double move_x, double move_y,
	double speed)
{
	t_point	new_position;
	double	length;

	length = sqrt(move_x * move_x + move_y * move_y);
	if (length < 0.0001)
		return ;
	move_x /= length;
	move_y /= length;
	new_position.x_p = game_data->player.position_x + move_x * speed;
	new_position.y_p = game_data->player.position_y + move_y * speed;
	if (!is_wall_colliding(game_data, new_position.x_p, new_position.y_p))
	{
		game_data->player.position_x = new_position.x_p;
		game_data->player.position_y = new_position.y_p;
	}
}

static void	set_delta_distances(t_ray *ray)
{
	if (ray->ray_direction_x == 0)
		ray->delta_distance_x = 1e30;
	else
		ray->delta_distance_x = fabs(1 / ray->ray_direction_x);
	if (ray->ray_direction_y == 0)
		ray->delta_distance_y = 1e30;
	else
		ray->delta_distance_y = fabs(1 / ray->ray_direction_y);
}

static void	set_step_and_side_x(t_ray *ray, double start_x)
{
	if (ray->ray_direction_x < 0)
	{
		ray->step_x = -1;
		ray->side_distance_x = (start_x - ray->map_x) * ray->delta_distance_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distance_x = (ray->map_x + 1.0 - start_x) \
			* ray->delta_distance_x;
	}
}

static void	set_step_and_side_y(t_ray *ray, double start_y)
{
	if (ray->ray_direction_y < 0)
	{
		ray->step_y = -1;
		ray->side_distance_y = (start_y - ray->map_y) * ray->delta_distance_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_distance_y = (ray->map_y + 1.0 - start_y) \
			* ray->delta_distance_y;
	}
}

void	initialize_collision_ray(t_ray *ray, t_ray_init *init)
{
	ray->ray_direction_x = init->direction_x;
	ray->ray_direction_y = init->direction_y;
	ray->map_x = (int)init->start_x;
	ray->map_y = (int)init->start_y;
	set_delta_distances(ray);
	set_step_and_side_x(ray, init->start_x);
	set_step_and_side_y(ray, init->start_y);
}
