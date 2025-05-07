#include "../includes/cub3d.h"

int handle_mouse_enter(t_game_data *data __attribute__ ((unused)))
{
    return (0);
}

int handle_mouse_leave(t_game_data *data __attribute__ ((unused)))
{
    return (0);
}
void	refresh_image(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	render_scene(data);
}

void adjust_fov(t_game_data *data, int delta_x)
{
    double angle;
    double previous_dir_x;
    double previous_plane_x;

    angle = delta_x * 0.003;
    previous_dir_x = data->player.direction_x;
    data->player.direction_x = data->player.direction_x * cos(-angle) - data->player.direction_y * sin(-angle);
    data->player.direction_y = previous_dir_x * sin(-angle) + data->player.direction_y * cos(-angle);
    
    previous_plane_x = data->player.plane_x;
    data->player.plane_x = data->player.plane_x * cos(-angle) - data->player.plane_y * sin(-angle);
    data->player.plane_y = previous_plane_x * sin(-angle) + data->player.plane_y * cos(-angle);
    
    refresh_image(data);
}

int handle_mouse_move(int x, int y, t_game_data *data)
{
    static int last_x;
    int delta_x;

    last_x = -1;
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

int handle_key_press(int keycode, t_game_data *data)
{
    t_event event;

    if (keycode == 53 || keycode == 65307)
    {
        free_all(data, NULL, 1);
        exit(0);
    }

    if (keycode == 49)
        interact_with_door(data);
    
    event.movement_speed = PLAYER_MOVE_SPEED;
    if (keycode == 13 || keycode == 126)
        move_forward(data, event);
    if (keycode == 1 || keycode == 125)
        move_backward(data, event);
    if (keycode == 2)
        move_rightward(data, event);
    if (keycode == 0)
        move_leftward(data, event);
    if (keycode == 123)
        turn_left(data, &event);
    if (keycode == 124)
        turn_right(data, &event);
    refresh_image(data);
    return (0);
}
