#include "cube3d.h"

void compute_wall_x(t_ray *ray_info, t_wall *wall, t_game_data *data)
{
    if (ray_info->side == 0)
        wall->wall_x = data->player.position_y + wall->distance_to_wall * ray_info->ray_direction_y;
    else
        wall->wall_x = data->player.position_x + wall->distance_to_wall * ray_info->ray_direction_x;
    wall->wall_x -= floor(wall->wall_x);
}

void render_floor_and_ceiling(t_game_data *data)
{
    size_t row;
    size_t col;
    unsigned int ceiling_color;
    unsigned int floor_color;

    row = 0;
    while (row < SCREEN_HEIGHT / 2)
    {
        col = 0;
        while (col < SCREEN_WIDTH)
        {
            put_pixel_to_mlx(data, col, row, data->ceiling_color);
            put_pixel_to_mlx(data, col, SCREEN_HEIGHT - row - 1, data->floor_color);
            col++;
        }
        row++;
    }
}

void setup_player_direction(t_game_data *data, t_map *map)
{
    if (map->player_direction == 'E')
    {
        data->player.direction_x = 1;
        data->player.direction_y = 0;
        data->player.plane_x = 0;
        data->player.plane_y = -0.66;
    }
    else if (map->player_direction == 'W')
    {
        data->player.direction_x = -1;
        data->player.direction_y = 0;
        data->player.plane_x = 0;
        data->player.plane_y = 0.66;
    }
}

void release_textures(char **file_paths)
{
    int index;

    index = 0;
    while (index < 5)
    {
        free(file_paths[index]);
        index++;
    }
    free(file_paths);
}

void free_map_resources(t_map *map)
{
    int index;

    index = 0;
    while (index < map->map_height)
    {
        free(map->map[index]);
        index++;
    }
    index = 0;
    if (map->file_content)
    {
        while (map->file_content[index])
        {
            free(map->file_content[index]);
            index++;
        }
        free(map->file_content);
        map->file_content = NULL;
    }
    free(map->map);
    map->map = NULL;
//release the texture
}
