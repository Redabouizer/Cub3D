#include "../includes/cub3d.h"

int	is_door_accessible(t_game_data *game_data, int x_coord, int y_coord)
{
	if (x_coord < 0 || x_coord >= game_data->map_width || 
		y_coord < 0 || y_coord >= game_data->map_height)
		return (0);
		
	return (game_data->level_map[y_coord][x_coord] == 3);
}

void	initialize_collision_ray(t_ray *collision_ray, double start_x, double start_y,
								double direction_x, double direction_y)
{
	collision_ray->ray_direction_x = direction_x;
	collision_ray->ray_direction_y = direction_y;
	collision_ray->map_x = (int)start_x;
	collision_ray->map_y = (int)start_y;
	collision_ray->delta_distance_x = (collision_ray->ray_direction_x == 0) ? 1e30 : fabs(1 / collision_ray->ray_direction_x);
	collision_ray->delta_distance_y = (collision_ray->ray_direction_y == 0) ? 1e30 : fabs(1 / collision_ray->ray_direction_y);
	if (collision_ray->ray_direction_x < 0)
	{
		collision_ray->step_x = -1;
		collision_ray->side_distance_x = (start_x - collision_ray->map_x) * collision_ray->delta_distance_x;
	}
	else
	{
		collision_ray->step_x = 1;
		collision_ray->side_distance_x = (collision_ray->map_x + 1.0 - start_x) * collision_ray->delta_distance_x;
	}
	if (collision_ray->ray_direction_y < 0)
	{
		collision_ray->step_y = -1;
		collision_ray->side_distance_y = (start_y - collision_ray->map_y) * collision_ray->delta_distance_y;
	}
	else
	{
		collision_ray->step_y = 1;
		collision_ray->side_distance_y = (collision_ray->map_y + 1.0 - start_y) * collision_ray->delta_distance_y;
	}
}

int	detect_collision_side(t_game_data *game_data, double target_x, double target_y, double *collision_distance)
{
	t_ray collision_ray;
	double direction_x;
	double direction_y;
	double movement_distance;
	int collision_found;
	int max_iterations;
	int collision_side;

	direction_x = target_x - game_data->player.position_x;
	direction_y = target_y - game_data->player.position_y;
	movement_distance = sqrt(direction_x * direction_x + direction_y * direction_y);
	
	if (movement_distance < 0.0001)
	{
		*collision_distance = 0;
		return (0);
	}
	
	direction_x /= movement_distance;
	direction_y /= movement_distance;
	
	initialize_collision_ray(&collision_ray, game_data->player.position_x, game_data->player.position_y, direction_x, direction_y);
	collision_found = 0;
	max_iterations = 20;
	collision_side = 0;

	while (collision_found == 0 && max_iterations > 0)
	{
		if (collision_ray.side_distance_x < collision_ray.side_distance_y)
		{
			collision_ray.side_distance_x += collision_ray.delta_distance_x;
			collision_ray.map_x += collision_ray.step_x;
			collision_ray.side = 0;
		}
		else
		{
			collision_ray.side_distance_y += collision_ray.delta_distance_y;
			collision_ray.map_y += collision_ray.step_y;
			collision_ray.side = 1;
		}
		
		if (collision_ray.map_x < 0 || collision_ray.map_x >= game_data->map_width
			|| collision_ray.map_y < 0 || collision_ray.map_y >= game_data->map_height)
		{
			collision_found = 1;
			collision_side = collision_ray.side + 1;
		}
		else if (game_data->level_map[collision_ray.map_y][collision_ray.map_x] == 1)
		{
			collision_found = 1;
			collision_side = collision_ray.side + 1;
		}
		else if (game_data->level_map[collision_ray.map_y][collision_ray.map_x] == 2 && !is_door_accessible(game_data, collision_ray.map_x, collision_ray.map_y))
		{
			collision_found = 1;
			collision_side = collision_ray.side + 1;
		}
		max_iterations--;
	}
	
	if (collision_ray.side == 0)
		*collision_distance = (collision_ray.map_x - game_data->player.position_x + (1 - collision_ray.step_x) / 2) / collision_ray.ray_direction_x;
	else
		*collision_distance = (collision_ray.map_y - game_data->player.position_y + (1 - collision_ray.step_y) / 2) / collision_ray.ray_direction_y;
	
	if (*collision_distance > movement_distance + 0.3)
		return (0);
	
	return (collision_side);
}

int	is_wall_colliding(t_game_data *game_data, double target_x, double target_y)
{
	double collision_distance;

	return (detect_collision_side(game_data, target_x, target_y, &collision_distance) > 0);
}

void	process_movement(t_game_data *game_data, double move_x, double move_y,
	double speed)
{
	t_point new_position;
	double length;

	length = sqrt(move_x * move_x + move_y * move_y);
	if (length < 0.0001)
		return;
		
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
