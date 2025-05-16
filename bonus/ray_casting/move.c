/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:01:19 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 05:06:35 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.direction_x, \
		game_data->player.direction_y, event.movement_speed);
}

void	move_backward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.direction_x, \
		-game_data->player.direction_y, event.movement_speed);
}

void	move_rightward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, game_data->player.plane_x, \
		game_data->player.plane_y, event.movement_speed);
}

void	move_leftward(t_game_data *game_data, t_event event)
{
	process_movement(game_data, -game_data->player.plane_x, \
		-game_data->player.plane_y, event.movement_speed);
}
