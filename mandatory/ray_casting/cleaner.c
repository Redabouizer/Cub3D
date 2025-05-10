#include "../includes/cub3d.h"


void free_array_text(t_game_data *data)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (data->textures[i].img)
            mlx_destroy_image(data->mlx, data->textures[i].img);
        i++;
    }
}

void display_destruction(t_game_data *data)
{
    if (data->img)
        mlx_destroy_image(data->mlx, data->img);
    if (data->window)
        mlx_destroy_window(data->mlx, data->window);
}

void free_worldmap(t_game_data *data)
{
    int i;

    if (!data->level_map)
        return;
        
    i = 0;
    while (i < data->map_height)
    {
        free(data->level_map[i]);
        i++;
    }
    free(data->level_map);
    data->level_map = NULL;
}

void free_all(t_game_data *data, t_map *map, int flag)
{
    if (!data)
        return;

    if (flag == 1)
        free_array_text(data);
        
    display_destruction(data);
    free_worldmap(data);
    
    if (map && flag && map->mm)
        cleanup(map->mm);
}


void free_path(char **paths)
{
    int i;

    if (!paths)
        return;
        
    i = 0;
    while (i < 4)
    {
        free(paths[i]);
        i++;
    }
    free(paths);
}
