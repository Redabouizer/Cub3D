/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_pro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:17:20 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 21:23:12 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_game_data *data)
{
	free_all(data, NULL, 1);
	exit(0);
	return (0);
}

int	is_wall_colliding(t_game_data *game_data, double target_x, double target_y)
{
	double	collision_distance;

	return (detect_collision_side(game_data, target_x, \
		target_y, &collision_distance) > 0);
}

int	handle_mouse_enter(t_game_data *data __attribute__((unused)))
{
	return (0);
}

int	handle_mouse_leave(t_game_data *data __attribute__((unused)))
{
	return (0);
}
