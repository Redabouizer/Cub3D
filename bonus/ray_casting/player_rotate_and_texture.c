/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate_and_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:02:07 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 05:04:18 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_game_data *game_data, t_event *event)
{
	event->previous_direction_x = game_data->player.direction_x;
	game_data->player.direction_x = game_data->player.direction_x \
		* cos(PLAYER_ROTATION_SPEED) - game_data->player.direction_y \
		* sin(PLAYER_ROTATION_SPEED);
	game_data->player.direction_y = event->previous_direction_x \
		* sin(PLAYER_ROTATION_SPEED) + game_data->player.direction_y \
		* cos(PLAYER_ROTATION_SPEED);
	event->previous_plane_x = game_data->player.plane_x;
	game_data->player.plane_x = game_data->player.plane_x \
		* cos(PLAYER_ROTATION_SPEED) - game_data->player.plane_y \
		* sin(PLAYER_ROTATION_SPEED);
	game_data->player.plane_y = event->previous_plane_x \
		* sin(PLAYER_ROTATION_SPEED) + game_data->player.plane_y \
		* cos(PLAYER_ROTATION_SPEED);
}

void	turn_right(t_game_data *game_data, t_event *event)
{
	event->previous_direction_x = game_data->player.direction_x;
	game_data->player.direction_x = game_data->player.direction_x \
		* cos(-PLAYER_ROTATION_SPEED) - game_data->player.direction_y \
		* sin(-PLAYER_ROTATION_SPEED);
	game_data->player.direction_y = event->previous_direction_x \
		* sin(-PLAYER_ROTATION_SPEED) + game_data->player.direction_y \
		* cos(-PLAYER_ROTATION_SPEED);
	event->previous_plane_x = game_data->player.plane_x;
	game_data->player.plane_x = game_data->player.plane_x \
		* cos(-PLAYER_ROTATION_SPEED) - game_data->player.plane_y \
		* sin(-PLAYER_ROTATION_SPEED);
	game_data->player.plane_y = event->previous_plane_x
		* sin(-PLAYER_ROTATION_SPEED) + game_data->player.plane_y \
		* cos(-PLAYER_ROTATION_SPEED);
}
