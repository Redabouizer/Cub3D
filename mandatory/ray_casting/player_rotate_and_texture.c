#include "../includes/cub3d.h"

void	turn_left(t_game_data *game_data, t_event *event)
{
	event->previous_direction_x = game_data->player.direction_x;
	game_data->player.direction_x = game_data->player.direction_x * cos(PLAYER_ROTATION_SPEED) - 
		game_data->player.direction_y * sin(PLAYER_ROTATION_SPEED);
	game_data->player.direction_y = event->previous_direction_x * sin(PLAYER_ROTATION_SPEED) + 
		game_data->player.direction_y * cos(PLAYER_ROTATION_SPEED);
	event->previous_plane_x = game_data->player.plane_x;
	game_data->player.plane_x = game_data->player.plane_x * cos(PLAYER_ROTATION_SPEED) - 
		game_data->player.plane_y * sin(PLAYER_ROTATION_SPEED);
	game_data->player.plane_y = event->previous_plane_x * sin(PLAYER_ROTATION_SPEED) + 
		game_data->player.plane_y * cos(PLAYER_ROTATION_SPEED);
}

void	turn_right(t_game_data *game_data, t_event *event)
{
	event->previous_direction_x = game_data->player.direction_x;
	game_data->player.direction_x = game_data->player.direction_x * cos(-PLAYER_ROTATION_SPEED) - 
		game_data->player.direction_y * sin(-PLAYER_ROTATION_SPEED);
	game_data->player.direction_y = event->previous_direction_x * sin(-PLAYER_ROTATION_SPEED) + 
		game_data->player.direction_y * cos(-PLAYER_ROTATION_SPEED);
	event->previous_plane_x = game_data->player.plane_x;
	game_data->player.plane_x = game_data->player.plane_x * cos(-PLAYER_ROTATION_SPEED) - 
		game_data->player.plane_y * sin(-PLAYER_ROTATION_SPEED);
	game_data->player.plane_y = event->previous_plane_x * sin(-PLAYER_ROTATION_SPEED) + 
		game_data->player.plane_y * cos(-PLAYER_ROTATION_SPEED);
}

// void	release_texture_resources(t_map *map)
// {
// 	free(map->north_texture);
// 	map->north_texture = NULL;
// 	free(map->south_texture);
// 	map->south_texture = NULL;
// 	free(map->east_texture);
// 	map->east_texture = NULL;
// 	free(map->west_texture);
// 	map->west_texture = NULL;
// }
