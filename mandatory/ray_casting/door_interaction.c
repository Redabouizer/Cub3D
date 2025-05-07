#include "../includes/cub3d.h"

void	interact_with_door(t_game_data *game_data)
{
	// int		door_x;
	// int		door_y;
	double	direct_x;
	double	direct_y;
	// double	door_distance;
	
	// Cast a ray in the player's view direction to locate a door
	direct_x = game_data->player.direction_x;
	direct_y = game_data->player.direction_y;
	
	// Initialize the ray for door detection
	t_ray ray;
	initialize_collision_ray(&ray, game_data->player.position_x, game_data->player.position_y, direct_x, direct_y);
	
	int door_found = 0;
	int max_iterations = 10;  // Limited range for door interaction
	
	// Locate the door using raycasting
	while (!door_found && max_iterations > 0)
	{
		if (ray.side_distance_x < ray.side_distance_y)
		{
			ray.side_distance_x += ray.delta_distance_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_distance_y += ray.delta_distance_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		
		if (ray.map_x < 0 || ray.map_x >= game_data->map_width ||
			ray.map_y < 0 || ray.map_y >= game_data->map_height)
			break;
			
		// Check if a door was found
		if (game_data->level_map[ray.map_y][ray.map_x] == 2)  // Closed door
		{
			game_data->level_map[ray.map_y][ray.map_x] = 3;  // Open the door
			door_found = 1;
		}
		else if (game_data->level_map[ray.map_y][ray.map_x] == 3)  // Open door
		{
			game_data->level_map[ray.map_y][ray.map_x] = 2;  // Close the door
			door_found = 1;
		}
		else if (game_data->level_map[ray.map_y][ray.map_x] == 1)  // Wall
			break;
			
		max_iterations--;
	}
}

void	move_forward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.direction_x, game_data->player.direction_y, event.movement_speed);
}

void	move_backward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.direction_x, -game_data->player.direction_y, event.movement_speed);
}

void	move_rightward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.plane_x, game_data->player.plane_y, event.movement_speed);
}

void	move_leftward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.plane_x, -game_data->player.plane_y, event.movement_speed);
}