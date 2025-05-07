#include "cube3d.h"

static void	initialize_map(t_map *map)
{
	map->file_content = NULL;
	map->map = NULL;
    map->map_width = 0;
	map->map_height = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
    map->ceiling_color = -1;
	map->floor_color = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->player_direction = '\0';
}

int	main(int ac, char **av)
{
	t_game_data		data;
	t_map		map;
	t_ray	raycaster;
	initialize_map(&map);
	// here you should check the function that can read from the file or not
	// Protection issue
	setup_data(&data, &map);
	data.raycaster = raycaster;
	generate_world_map(&data, &map);
	// load_texture(&data, &map);
	mlx_hook(data.window, 2, 1L << 0, handle_key_press, &data);
	mlx_hook(data.window, 6, 1L << 6, handle_mouse_move, &data);
	mlx_hook(data.window, 7, 1L << 4, handle_mouse_enter, &data);
	mlx_hook(data.window, 8, 1L << 5, handle_mouse_leave, &data);
	render_scene(&data);
	mlx_loop(data.mlx);
	free_all(&data, &map, 1);
	return (0);
}

