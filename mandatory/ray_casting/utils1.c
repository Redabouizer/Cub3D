#include "../includes/cub3d.h"

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
    // unsigned int ceiling_color;
    // unsigned int floor_color;

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
    int i;

    get_next_line(-1, true);
    if (!map)  
        return;

    if (map->map)
    {
        i = 0;
        while (i < map->map_height)
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
        map->map = NULL;
    }
    if (map->file_content)
    {
        i = 0;
        while (map->file_content[i]) {
            free(map->file_content[i]);
            i++;
        }
        free(map->file_content);
        map->file_content = NULL;
    }

    if (map->north_texture)
    {
        free(map->north_texture);
        map->north_texture = NULL;
    }
    if (map->south_texture)
    {
        free(map->south_texture);
        map->south_texture = NULL;
    }
    if (map->east_texture)
    {
        free(map->east_texture);
        map->east_texture = NULL;
    }
    if (map->west_texture)
    {
        free(map->west_texture);
        map->west_texture = NULL;
    }
    if (map->mm)
        cleanup(map->mm);
}
