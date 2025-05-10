#include "../includes/cub3d.h"

//init_game_data
//init data
void setup_data(t_game_data *data, t_map *map)
{
    ft_memset(data, 0, sizeof(t_game_data));
    
    data->mlx = mlx_init();
    if (!data->mlx) {
        printf("Failed to initialize MLX!\n");
        free_map_resources(map);
        exit(EXIT_FAILURE);
    }
    data->window = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycaster");
    if (!data->window)
    {
        printf("Failed to create new window!\n");
        free_map_resources(map);
        exit(EXIT_FAILURE);
    }
    data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!data->img)
    {
        printf("Failed to create new image!\n");
        mlx_destroy_window(data->mlx, data->window);
        free_map_resources(map);
        exit(EXIT_FAILURE);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}


//init world map

void setup_world_map(t_game_data *data, t_map *map)
{
    int row;
    int col;

    row = 0;
    data->level_map = (int **)malloc(sizeof(int *) * data->map_height);
    if (!data->level_map)
        (printf("Memory allocation error\n"), free_map_resources(map), display_destruction(data), exit(EXIT_FAILURE));
    
    while (row < data->map_height)
    {
        col = 0;
        data->level_map[row] = (int *)malloc(sizeof(int) * data->map_width);
        if (!data->level_map[row])
            (printf("Memory allocation error\n"), free_map_resources(map), display_destruction(data), exit(EXIT_FAILURE));
        
        while (col < data->map_width)
        {
            if (map->map[row][col] == ' ' || map->map[row][col] == '1')
                data->level_map[row][col] = 1;
            else
                data->level_map[row][col] = 0;
            col++;
        }
        row++;
    }
}
//init plan dir
void setup_player_direction(t_game_data *data, t_map *map)
{
    if (map->player_direction == 'N')
    {
        data->player.direction_x = 0;
        data->player.direction_y = -1;
        data->player.plane_x = -0.66;
        data->player.plane_y = 0;
    }
    else if (map->player_direction == 'S')
    {
        data->player.direction_x = 0;
        data->player.direction_y = 1;
        data->player.plane_x = 0.66;
        data->player.plane_y = 0;
    }
    else if (map->player_direction == 'E')
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
//add doors to map
// void insert_doors_into_map(t_game_data *data)
// {
//     int row;
//     int col;

//     row = 1;
//     while (row < data->map_height - 1)
//     {
//         col = 1;
//         while (col < data->map_width - 1)
//         {
//             if (data->level_map[row][col] == 0)
//             {
//                 if (data->level_map[row][col - 1] == 1 && data->level_map[row][col + 1] == 1)
//                     data->level_map[row][col] = 2;
//                 else if (data->level_map[row - 1][col] == 1 && data->level_map[row + 1][col] == 1)
//                     data->level_map[row][col] = 2;
//             }
//             col++;
//         }
//         row++;
//     }
// }
//creat world map
void generate_world_map(t_game_data *data, t_map *map)
{
    data->map_width = map->map_width;
    data->map_height = map->map_height;
    map->map[map->player_y][map->player_x] = '0';
    setup_world_map(data, map);
    // insert_doors_into_map(data);
    data->player.position_x = map->player_x + 0.5;
    data->player.position_y = map->player_y + 0.5;
    setup_player_direction(data, map);
    data->floor_color = map->floor_color;
    data->ceiling_color = map->ceiling_color;
}
// my mlx pixel put
void put_pixel_to_mlx(t_game_data *data, int x, int y, int color)
{
    char *destination;

    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        destination = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)destination = color;
    }
}
