/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_r_casting_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:09:39 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 06:02:01 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_wall_distance(t_ray *ray_info, t_wall *wall,
			t_game_data *data __attribute__ ((unused)))
{
	if (ray_info->side == 0)
		wall->distance_to_wall = (ray_info->side_distance_x
				- ray_info->delta_distance_x);
	else
		wall->distance_to_wall = (ray_info->side_distance_y
				- ray_info->delta_distance_y);
}

void	compute_line_height(t_wall *wall)
{
	wall->line_height = (int)(SCREEN_HEIGHT / wall->distance_to_wall);
	wall->draw_start = -wall->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->draw_end >= SCREEN_HEIGHT)
		wall->draw_end = SCREEN_HEIGHT - 1;
}

void	verify_door_hit(t_game_data *data, t_ray *ray_info,
		int *hit, int *is_door)
{
	if (data->level_map[ray_info->map_y][ray_info->map_x] == 1)
		*hit = 1;
	else if (data->level_map[ray_info->map_y][ray_info->map_x] == 2)
	{
		*hit = 1;
		*is_door = 1;
	}
}

void	process_wall_hit(t_game_data *data, t_ray *ray_info, \
		int *hit, int *is_door)
{
	while (*hit == 0)
	{
		if (ray_info->side_distance_x < ray_info->side_distance_y)
		{
			ray_info->side_distance_x += ray_info->delta_distance_x;
			(1) && (ray_info->map_x += ray_info->step_x, ray_info->side = 0);
		}
		else
		{
			ray_info->side_distance_y += ray_info->delta_distance_y;
			ray_info->map_y += ray_info->step_y;
			ray_info->side = 1;
		}
		if (ray_info->map_x < 0 || ray_info->map_x >= data->map_width \
				|| ray_info->map_y < 0 || ray_info->map_y >= data->map_height)
			(3) && (*hit = 1, ray_info->side_distance_x = INFINITY, \
				ray_info->side_distance_y = INFINITY);
		else if (data->level_map[ray_info->map_y][ray_info->map_x] == 1)
			*hit = 1;
		else if (data->level_map[ray_info->map_y][ray_info->map_x] == 2)
		{
			*hit = 1;
			*is_door = 1;
		}
	}
}
