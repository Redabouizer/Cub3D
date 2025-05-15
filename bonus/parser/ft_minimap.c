/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:00:00 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/15 22:50:01 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Bresenham's line algorithm using while loops
void	draw_line(t_game_data *data, t_point start, t_point end, int color)
{
	int dx = (int)fabs(end.x_p - start.x_p);
	int dy = -(int)fabs(end.y_p - start.y_p);
	int sx;
	int sy;
	int err = dx + dy;
	int e2;

	if (start.x_p < end.x_p)
		sx = 1;
	else
		sx = -1;
	
	if (start.y_p < end.y_p)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		put_pixel_to_mlx(data, (int)start.x_p, (int)start.y_p, color);
		if (start.x_p == end.x_p && start.y_p == end.y_p)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			start.x_p += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			start.y_p += sy;
		}
	}
}

void	draw_minimap_cell(t_game_data *data, int x, int y, int color)
{
	int i = 0;
	int j;
	int cell_size = 10;
	int offset_x = 20;
	int offset_y = 20;

	while (i < cell_size)
	{
		j = 0;
		while (j < cell_size)
		{
			put_pixel_to_mlx(data, offset_x + x * cell_size + i, 
						   offset_y + y * cell_size + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game_data *data)
{
	int x;
	int y = 0;
	int color;

	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->level_map[y][x] == 1)
				color = 0x000000;
			else if (data->level_map[y][x] == 0)
				color = 0xFFFFFF;
			else if (data->level_map[y][x] == 2 || data->level_map[y][x] == 3)
				color = 0x964B00;
			else
				color = 0xAAAAAA;
			
			draw_minimap_cell(data, x, y, color);
			x++;
		}
		y++;
	}

	t_point player_pos;
	t_point player_dir;

	player_pos.x_p = 20 + (int)(data->player.position_x * 10);
	player_pos.y_p = 20 + (int)(data->player.position_y * 10);
	
	player_dir.x_p = player_pos.x_p + (int)(data->player.direction_x * 20);
	player_dir.y_p = player_pos.y_p + (int)(data->player.direction_y * 20);

	int i = -2;
	int j;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (i*i + j*j <= 4)
				put_pixel_to_mlx(data, player_pos.x_p + i, player_pos.y_p + j, 0xFF0000);
			j++;
		}
		i++;
	}

	draw_line(data, player_pos, player_dir, 0xFF0000);
}