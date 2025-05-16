/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:43:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 06:43:28 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_collision(t_game_data *data, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= data->map_width
		|| ray->map_y < 0 || ray->map_y >= data->map_height)
		return (1);
	if (data->level_map[ray->map_y][ray->map_x] == 1)
		return (1);
	if (data->level_map[ray->map_y][ray->map_x] == 2
		&& !is_door_accessible(data, ray->map_x, ray->map_y))
		return (1);
	return (0);
}

static void	update_ray_position(t_ray *ray)
{
	if (ray->side_distance_x < ray->side_distance_y)
	{
		ray->side_distance_x += ray->delta_distance_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_distance_y += ray->delta_distance_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static void	calculate_collision_distance(t_game_data *data, t_ray *ray, \
			double *dist)
{
	if (ray->side == 0)
		*dist = (ray->map_x - data->player.position_x
				+ (1 - ray->step_x) / 2) / ray->ray_direction_x;
	else
		*dist = (ray->map_y - data->player.position_y
				+ (1 - ray->step_y) / 2) / ray->ray_direction_y;
}

void	init_direction(t_dir_data *dir, t_game_data *data, \
						double target_x, double target_y)
{
	dir->dir_x = target_x - data->player.position_x;
	dir->dir_y = target_y - data->player.position_y;
	dir->move_dist = sqrt(dir->dir_x * dir->dir_x + dir->dir_y * dir->dir_y);
	if (dir->move_dist >= 0.0001)
	{
		dir->dir_x /= dir->move_dist;
		dir->dir_y /= dir->move_dist;
	}
}

int	detect_collision_side(t_game_data *data, double target_x, double target_y,
						double *collision_dist)
{
	t_ray		ray;
	t_dir_data	dir;
	t_ray_init	init;
	int			iterations;

	dir.dir_x = target_x - data->player.position_x;
	dir.dir_y = target_y - data->player.position_y;
	dir.move_dist = sqrt(dir.dir_x * dir.dir_x + dir.dir_y * dir.dir_y);
	if (dir.move_dist < 0.0001)
		return (*collision_dist = 0, 0);
	if (dir.move_dist >= 0.0001)
		(1) && (dir.dir_x /= dir.move_dist, dir.dir_y /= dir.move_dist);
	init.start_x = data->player.position_x;
	init.start_y = data->player.position_y;
	(1) && (init.direction_x = dir.dir_x, init.direction_y = dir.dir_y);
	initialize_collision_ray(&ray, &init);
	iterations = 20;
	while (iterations-- > 0 && !check_collision(data, &ray))
		update_ray_position(&ray);
	calculate_collision_distance(data, &ray, collision_dist);
	if (*collision_dist > dir.move_dist + 0.3)
		return (0);
	return (ray.side + 1);
}
