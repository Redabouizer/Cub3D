#include "../includes/cub3d.h"

int handle_mouse_enter(t_game_data *data __attribute__((unused)))
{
    return (0);
}

int handle_mouse_leave(t_game_data *data __attribute__((unused)))
{
    return (0);
}
void refresh_image(t_game_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
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
    printf("hello %d,%d,%d\n",delta_x, x, last_x);
    if (abs(delta_x) > 0)
    {
        adjust_fov(data, delta_x);
    }
    last_x = x;
    return (0);
}
int handle_key_press(int keycode, t_game_data *data)
{
    t_event event;
    
    if (!data)
        return (0);
    ft_memset(&event, 0, sizeof(t_event));
    event.movement_speed = PLAYER_MOVE_SPEED;
    if (keycode == ESC_LINUX)
    {
        free_all(data, NULL, 1);
        exit(0);
    }
    // else if (keycode == SPACE_LINUX) 
    //     interact_with_door(data);
    else
    {
        if (keycode == W || keycode == UP_LINUX)
            move_forward(data, event);
        else if (keycode == S ||keycode == DOWN_LINUX)
            move_backward(data, event);
        else if (keycode == D ||keycode == RIGHT_LINUX)
            move_rightward(data, event);
        else if (keycode == A ||keycode == LEFT_LINUX)
            move_leftward(data, event);
        if (keycode == LEFT_LINUX)
            turn_left(data, &event);
        else if (keycode == RIGHT_LINUX)
            turn_right(data, &event);
    }
    refresh_image(data);
    return (0);
}
int close_window(t_game_data *data)
{
    free_all(data, NULL, 1);
    exit(0);
    return (0);
}
