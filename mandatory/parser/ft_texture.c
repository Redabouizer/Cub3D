/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:28 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 20:49:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int check_texture(const char *path)
{
    int fd;

    if (!path || !*path)
        return (0);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

int set_texture(char **texture, char *line)
{
    char *path;

    path = ft_strtrim(line + 3, " \t\n\r\f\v");
    if (!path)
        return (printf("Error : Memory allocation failed\n"), 0);
    if (!check_texture(path))
    {
        free(path);
        return (printf("Error : Texture not found\n"), 0);
    }
    *texture = path;
    return (1);
}

unsigned int retrieve_texture_color(t_texture *texture, int y, int x)
{
    char *destination;

    destination = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    return (*(unsigned int *)destination);
}

static char **allocate_texture_paths(t_game_data *data, t_map *map)
{
    char **paths;

    paths = malloc(sizeof(char *) * 5);
    if (!paths)
    {
        free_all(data, map, 0);
        printf("Error: Memory allocation for texture paths failed\n");
        exit(EXIT_FAILURE);
    }
    paths[0] = ft_strdup(map->north_texture);
    paths[1] = ft_strdup(map->south_texture);
    paths[2] = ft_strdup(map->east_texture);
    paths[3] = ft_strdup(map->west_texture);
    // paths[4] = ft_strdup("./textures/ou_dr.xpm");
    return (paths);
}

void load_textures(t_game_data *data, t_map *map)
{
    char **paths;
    size_t index;
    int width;
    int height;

    index = 0;
    paths = allocate_texture_paths(data, map);
    while (index < 4)
    {
        data->textures[index].img = mlx_xpm_file_to_image(data->mlx, paths[index], &width, &height);
        if (!data->textures[index].img)
        {
            printf("Error loading texture from %s\n", paths[index]);
            exit(EXIT_FAILURE);
        }
        data->textures[index].addr = mlx_get_data_addr(data->textures[index].img, 
                                                         &data->textures[index].bits_per_pixel, 
                                                         &data->textures[index].line_length, 
                                                         &data->textures[index].endian);
        index++;
    }
    free_path(paths);
    free_map_resources(map);
}
