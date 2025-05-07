#include "cube3d.h"

void compute_ray_data(t_game_data *data, t_ray *ray_info, int x)
{
    ray_info->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
    ray_info->ray_direction_x = data->player.direction_x + data->player.plane_x * ray_info->camera_x;
    ray_info->ray_direction_y = data->player.direction_y + data->player.plane_y * ray_info->camera_x;
    ray_info->map_x = (int)data->player.position_x;
    ray_info->map_y = (int)data->player.position_y;

    ray_info->delta_distance_x = (ray_info->ray_direction_x != 0) ? fabs(1 / ray_info->ray_direction_x) : 1e30;
    ray_info->delta_distance_y = (ray_info->ray_direction_y != 0) ? fabs(1 / ray_info->ray_direction_y) : 1e30;
}

void compute_steps(t_game_data *data, t_ray *ray_info)
{
    if (ray_info->ray_direction_x < 0)
    {
        ray_info->step_x = -1;
        ray_info->side_distance_x = (data->player.position_x - ray_info->map_x) * ray_info->delta_distance_x;
    }
    else
    {
        ray_info->step_x = 1;
        ray_info->side_distance_x = (ray_info->map_x + 1.0 - data->player.position_x) * ray_info->delta_distance_x;
    }

    if (ray_info->ray_direction_y < 0)
    {
        ray_info->step_y = -1;
        ray_info->side_distance_y = (data->player.position_y - ray_info->map_y) * ray_info->delta_distance_y;
    }
    else
    {
        ray_info->step_y = 1;
        ray_info->side_distance_y = (ray_info->map_y + 1.0 - data->player.position_y) * ray_info->delta_distance_y;
    }
}

// void determine_texture(int *is_door, int *texture_num, t_ray *ray_info)
// {
//     if (*is_door)
//         *texture_num = 4;
//     else if (ray_info->side == 0)
//     {
//         *texture_num = (ray_info->ray_dir_x > 0) ? 2 : 3;
//     }
//     else
//     {
//         *texture_num = (ray_info->ray_dir_y > 0) ? 1 : 0;
//     }
// }

void execute_dda(t_game_data *data, t_ray *ray_info)
{
    int x = 0;
    int hit = 0;
    int is_door = 0;
    t_wall wall;

    while (x < SCREEN_WIDTH)
    {
        compute_ray_data(data, ray_info, x);
        compute_steps(data, ray_info);
        
        hit = 0;
        is_door = 0;
        process_wall_hit(data, ray_info, &hit, &is_door);
        calculate_wall_distance(ray_info, &wall, data);
        compute_line_height(&wall);
// here you should determine the texture Bro
// You can verify the function commented before and use it
        compute_wall_x(ray_info, &wall, data);
// and here you should render it Bro   
// check the fuction in the file game_r_casting_helper.c it should helping you     
        x++;
    }
}

int render_scene(t_game_data *data)
{
    t_ray *ray_info = &data->raycaster;

    render_floor_and_ceiling(data);
    execute_dda(data, ray_info);
    mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
    
    return (0);
}
