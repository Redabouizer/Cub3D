/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:40:42 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 11:30:48 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap_cell(t_game_data *data, int x, int y, int color)
{
	t_cell	cell;

	cell.x = x;
	cell.y = y;
	cell.color = color;
	cell.size = 10;
	cell.offset_x = 20;
	cell.offset_y = 20;
	draw_cell_pixels(data, &cell);
}

static int	get_cell_color(int cell_value)
{
	if (cell_value == 1)
		return (0x000000);
	if (cell_value == 0)
		return (0xFFFFFF);
	if (cell_value == 2 || cell_value == 3)
		return (0x964B00);
	return (0xAAAAAA);
}

static void	draw_map_row(t_game_data *data, int y)
{
	int	x;
	int	color;

	x = 0;
	while (x < data->map_width)
	{
		color = get_cell_color(data->level_map[y][x]);
		draw_minimap_cell(data, x, y, color);
		x++;
	}
}

void	draw_player_on_minimap(t_game_data *data)
{
	t_point	player_pos;
	t_point	player_dir;
	int		i;
	int		j;

	player_pos.x_p = 20 + (int)(data->player.position_x * 10);
	player_pos.y_p = 20 + (int)(data->player.position_y * 10);
	player_dir.x_p = player_pos.x_p + (int)(data->player.direction_x * 20);
	player_dir.y_p = player_pos.y_p + (int)(data->player.direction_y * 20);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (i * i + j * j <= 4)
				put_pixel_to_mlx(data, player_pos.x_p + i,
					player_pos.y_p + j, 0xFF0000);
			j++;
		}
		i++;
	}
	draw_line(data, player_pos, player_dir, 0xFF0000);
}

void	draw_minimap(t_game_data *data)
{
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		draw_map_row(data, y);
		y++;
	}
	draw_player_on_minimap(data);
}
