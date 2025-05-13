/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:26:29 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/13 06:31:47 by rbouizer         ###   ########.fr       */
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

void	insert_doors_into_map(t_game_data *data)
{
	int	row;
	int	col;

	row = 1;
	while (row < data->map_height - 1)
	{
		col = 1;
		while (col < data->map_width - 1)
		{
			if (data->level_map[row][col] == 0)
			{
				if (data->level_map[row][col - 1] == 1 \
						&& data->level_map[row][col + 1] == 1)
					data->level_map[row][col] = 2;
				else if (data->level_map[row - 1][col] == 1 \
						&& data->level_map[row + 1][col] == 1)
					data->level_map[row][col] = 2;
			}
			col++;
		}
		row++;
	}
}

void	update_ray_position(t_ray *ray)
{
	if (ray->side_distance_x < ray->side_distance_y)
	{
		ray->side_distance_x += ray->delta_distance_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_distance_y += ray->delta_distance_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

int	check_door_status(t_game_data *game_data, t_ray *ray)
{
	if (game_data->level_map[ray->map_y][ray->map_x] == 2)
	{
		game_data->level_map[ray->map_y][ray->map_x] = 3;
		return (1);
	}
	else if (game_data->level_map[ray->map_y][ray->map_x] == 3)
	{
		game_data->level_map[ray->map_y][ray->map_x] = 2;
		return (1);
	}
	return (0);
}

void	interact_with_door(t_game_data *game_data)
{
	t_ray		ray;
	int			door_found;
	int			max_iterations;
	t_ray_init	init;

	init.start_x = game_data->player.position_x;
	init.start_y = game_data->player.position_y;
	init.direction_x = game_data->player.direction_x;
	init.direction_y = game_data->player.direction_y;
	initialize_collision_ray(&ray, &init);
	door_found = 0;
	max_iterations = 10;
	while (!door_found && max_iterations-- > 0)
	{
		update_ray_position(&ray);
		if (ray.map_x < 0 || ray.map_x >= game_data->map_width \
			|| ray.map_y < 0 || ray.map_y >= game_data->map_height)
			break ;
		door_found = check_door_status(game_data, &ray);
		if (game_data->level_map[ray.map_y][ray.map_x] == 1)
			break ;
	}
}
