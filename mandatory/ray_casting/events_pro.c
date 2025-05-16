/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_pro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:46 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 02:17:39 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
