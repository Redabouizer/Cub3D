#include "../includes/cub3d.h"

t_map	*init_map(t_mem **manager)
{
	t_map	*map;
    int i;

    i = 0;
	map = (t_map *)my_malloc(manager, sizeof(t_map));
	if (map == NULL)
		return (NULL);

	map->map = NULL;
	map->pre_map = NULL;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;

    while(i < 3)
    {
        map->f_rgb[i] = -1;
        map->c_rgb[i] = -1;
        i++;
    }
	map->height = 0;
	map->width = 0;

	return (map);
}

