/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:43:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 02:57:15 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_delta_distances(t_ray *collision_ray)
{
	if (collision_ray->ray_direction_x == 0)
		collision_ray->delta_distance_x = 1e30;
	else
		collision_ray->delta_distance_x = fabs(1
				/ collision_ray->ray_direction_x);
	if (collision_ray->ray_direction_y == 0)
		collision_ray->delta_distance_y = 1e30;
	else
		collision_ray->delta_distance_y = fabs(1
				/ collision_ray->ray_direction_y);
}

static void	calculate_collision_distance(t_game_data *game_data,
	t_ray *collision_ray, double *collision_distance)
{
	if (collision_ray->side == 0)
		*collision_distance = (collision_ray->map_x \
				- game_data->player.position_x \
				+ (1 - collision_ray->step_x) / 2) \
			/ collision_ray->ray_direction_x;
	else
		*collision_distance = (collision_ray->map_y \
				- game_data->player.position_y \
				+ (1 - collision_ray->step_y) / 2) \
			/ collision_ray->ray_direction_y;
}

int	init_collision_vars(t_game_data *game_data, double target_x,
	double target_y, t_ray *collision_ray)
{
	t_ray_init	init_data;
	double		direction_x;
	double		direction_y;
	double		movement_distance;

	direction_x = target_x - game_data->player.position_x;
	direction_y = target_y - game_data->player.position_y;
	movement_distance = sqrt(direction_x \
		* direction_x + direction_y * direction_y);
	if (movement_distance < 0.0001)
		return (0);
	direction_x /= movement_distance;
	direction_y /= movement_distance;
	init_data.start_x = game_data->player.position_x;
	init_data.start_y = game_data->player.position_y;
	init_data.direction_x = direction_x;
	init_data.direction_y = direction_y;
	initialize_collision_ray(collision_ray, &init_data);
	return (1);
}

int	detect_collision_side(t_game_data *game_data, double target_x,
	double target_y, double *collision_distance)
{
	t_ray	collision_ray;
	int		collision_found;
	int		max_iterations;
	int		collision_side;

	if (!init_collision_vars(game_data, target_x, target_y, &collision_ray))
		return (*collision_distance = 0, 0);
	collision_found = 0;
	max_iterations = 20;
	collision_side = 0;
	while (collision_found == 0 && max_iterations > 0)
	{
		update_ray_position(&collision_ray);
		collision_found = check_collision(game_data, &collision_ray);
		if (collision_found)
			collision_side = collision_ray.side + 1;
		max_iterations--;
	}
	calculate_collision_distance(game_data, &collision_ray, collision_distance);
	if (*collision_distance > sqrt(pow(target_x \
				- game_data->player.position_x, 2) \
				+ pow(target_y - game_data->player.position_y, 2)) + 0.3)
		return (0);
	return (collision_side);
}

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
