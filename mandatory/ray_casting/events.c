/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:50:48 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/16 12:51:48 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	refresh_image(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	render_scene(data);
}

void	adjust_fov(t_game_data *data, int delta_x)
{
	double	angle;
	double	previous_dir_x;
	double	previous_plane_x;

	angle = delta_x * 0.003;
	previous_dir_x = data->player.direction_x;
	data->player.direction_x = data->player.direction_x
		* cos(-angle) - data->player.direction_y * sin(-angle);
	data->player.direction_y = previous_dir_x
		* sin(-angle) + data->player.direction_y * cos(-angle);
	previous_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-angle)
		- data->player.plane_y * sin(-angle);
	data->player.plane_y = previous_plane_x * sin(-angle)
		+ data->player.plane_y * cos(-angle);
	refresh_image(data);
}

int	handle_mouse_move(int x, int y, t_game_data *data)
{
	static int	last_x;
	int			delta_x;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		last_x = -1;
		return (0);
	}
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if (abs(delta_x) > 0)
		adjust_fov(data, delta_x);
	last_x = x;
	return (0);
}

int	handle_key_press(int keycode, t_game_data *data)
{
	t_event	event;

	if (!data)
		return (0);
	ft_memset(&event, 0, sizeof(t_event));
	event.movement_speed = PLAYER_MOVE_SPEED;
	if (keycode == ESC_MAC)
		close_window(data);
	else
	{
		if (keycode == W || keycode == UP_MAC)
			move_forward(data, event);
		else if (keycode == S || keycode == DOWN_MAC)
			move_backward(data, event);
		else if (keycode == D || keycode == RIGHT_MAC)
			move_rightward(data, event);
		else if (keycode == A || keycode == LEFT_MAC)
			move_leftward(data, event);
		if (keycode == LEFT_MAC)
			turn_left(data, &event);
		else if (keycode == RIGHT_MAC)
			turn_right(data, &event);
	}
	return (refresh_image(data), 0);
}

int	close_window(t_game_data *data)
{
	free_all(data, NULL, 1);
	exit(0);
	return (0);
}
