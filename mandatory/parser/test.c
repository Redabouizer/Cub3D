// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/06 00:15:30 by marvin            #+#    #+#             */
// /*   Updated: 2025/05/06 00:15:30 by marvin           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cub3d.h"

// void print_texture(const char *name, const char *texture)
// {
//     if (texture)
//         printf("%-8s: %s\n", name, texture);
//     else
//         printf("%-8s: (null)\n", name);
// }

// void print_color(const char *name, unsigned int color)
// {
//     printf("%-8s: %u (0x%06X)\n", name, color, color & 0xFFFFFF);
// }

// void print_map_grid(char **map, int height)
// {
//     int i;

//     printf("\nMap Grid:\n");
//     printf("---------\n");
//     i = 0;
//     while (i < height)
//     {
//         printf("%s\n", map[i]);
//         i++;
//     }
//     printf("---------\n");
// }

// void print_player_info(t_map *map)
// {
//     printf("\nPlayer Info:\n");
//     printf("-----------\n");
//     printf("Position: (%d, %d)\n", map->player_x, map->player_y);
//     printf("Direction: %c\n", map->player_direction);
//     printf("-----------\n");
// }

// void print_map_dimensions(t_map *map)
// {
//     printf("\nMap Dimensions:\n");
//     printf("--------------\n");
//     printf("Width: %d\n", map->map_width);
//     printf("Height: %d\n", map->map_height);
//     printf("--------------\n");
// }

// void print_file_content(t_map *map)
// {
//     if (!map->file_content)
//     {
//         printf("\nFile Content: (null)\n");
//         return;
//     }

//     printf("\nFile Content:\n");
//     printf("-------------\n");
//     for (int i = 0; map->file_content[i]; i++)
//     {
//         printf("%s\n", map->file_content[i]);
//     }
//     printf("-------------\n");
// }

// void print_map_data(t_map *map)
// {
//     if (!map)
//     {
//         printf("Error: Map is NULL\n");
//         return;
//     }

//     printf("\nMap Data Summary:\n");
//     printf("================\n");

//     // Print texture paths
//     printf("\nTextures:\n");
//     printf("---------\n");
//     print_texture("North", map->north_texture);
//     print_texture("South", map->south_texture);
//     print_texture("West", map->west_texture);
//     print_texture("East", map->east_texture);

//     // Print colors
//     printf("\nColors:\n");
//     printf("-------\n");
//     print_color("Floor", map->floor_color);
//     print_color("Ceiling", map->ceiling_color);

//     // Print map dimensions
//     print_map_dimensions(map);

//     // Print player info
//     print_player_info(map);

//     // Print the actual map grid
//     if (map->map && map->map_height > 0)
//         print_map_grid(map->map, map->map_height);
//     else
//         printf("\nNo map data available\n");

//     // Print file content if available
//     print_file_content(map);

//     printf("\n================\n");
// }