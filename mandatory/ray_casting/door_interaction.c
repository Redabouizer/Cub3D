/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:42:37 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 02:17:33 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_door_accessible(t_game_data *game_data, int x_coord, int y_coord)
{
	if (x_coord < 0 || x_coord >= game_data->map_width
		|| y_coord < 0 || y_coord >= game_data->map_height)
		return (0);
	return (game_data->level_map[y_coord][x_coord] == 3);
}

void	move_forward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.direction_x,
		game_data->player.direction_y, event.movement_speed);
}

void	move_backward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.direction_x,
		-game_data->player.direction_y, event.movement_speed);
}

void	move_rightward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.plane_x,
		game_data->player.plane_y, event.movement_speed);
}

void	move_leftward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.plane_x,
		-game_data->player.plane_y, event.movement_speed);
}
