// #include "../includes/cub3d.h"

// unsigned int retrieve_texture_color(t_texture *texture, int y, int x)
// {
//     char *destination;

//     destination = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
//     return (*(unsigned int *)destination);
// }

// static char **allocate_texture_paths(t_game_data *data, t_map *map)
// {
//     char **paths;

//     paths = malloc(sizeof(char *) * 5);
//     if (!paths)
//     {
//         free_all(data, map, 0);
//         printf("Error: Memory allocation for texture paths failed\n");
//         exit(EXIT_FAILURE);
//     }
//     paths[0] = ft_strdup(map->no_texture);
//     paths[1] = ft_strdup(map->so_texture);
//     paths[2] = ft_strdup(map->ea_texture);
//     paths[3] = ft_strdup(map->we_texture);
//     paths[4] = ft_strdup("./textures/ou_dr.xpm");
//     return (paths);
// }

// void load_textures(t_game_data *data, t_map *map)
// {
//     char **paths;
//     size_t index;
//     int width;
//     int height;

//     index = 0;
//     paths = allocate_texture_paths(data, map);
//     while (index < 5)
//     {
//         data->textures[index].img = mlx_xpm_file_to_image(data->mlx, paths[index], &width, &height);
//         if (!data->textures[index].img)
//         {
//             printf("Error loading texture from %s\n", paths[index]);
//             exit(EXIT_FAILURE);
//         }
//         data->textures[index].addr = mlx_get_game_data_addr(data->textures[index].img, 
//                                                          &data->textures[index].bits_per_pixel, 
//                                                          &data->textures[index].line_length, 
//                                                          &data->textures[index].endian);
//         index++;
//     }
//     free_textures(paths);
//     free_map_ressources(map);
// }
