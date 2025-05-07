# include "cube3d.h"

void	free_array_text(t_game_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		// destruct the texture based on mlx
		i++;
	}
}

void	display_destruction(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		free(data->mlx);
}

void	free_worldmap(t_game_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->level_map[i]);
		i++;
	}
	free(data->level_map);
	data->level_map = NULL;
}

void	free_all(t_game_data *data, t_map *map, int flag)
{
	if (flag == 1)
		free_array_text(data);
	display_destruction(data);
	free_worldmap(data);
	if (map)
		free_map_resources(map);
}
