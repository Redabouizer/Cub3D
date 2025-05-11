/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:28 by marvin            #+#    #+#             */
/*   Updated: 2025/05/11 02:37:09 by rbouizer         ###   ########.fr       */
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
        return (printf("Error: Memory allocation failed\n"), 0);
    if (!check_texture(path))
    {
        free(path);
        return (printf("Error: Texture not found\n"), 0);
    }
    if (*texture)  
        free(*texture);
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

int load_textures(t_game_data *data, t_map *map)
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
            free_path(paths);
            return (1);
        }
        data->textures[index].addr = mlx_get_data_addr(data->textures[index].img, 
                                                     &data->textures[index].bits_per_pixel, 
                                                     &data->textures[index].line_length, 
                                                     &data->textures[index].endian);
        index++;
    }
    free_path(paths);
    return (0);
}

unsigned int get_texture_color(t_texture *texture, int y, int x)
{
    char *dst;
    int tex_width = TEXTURE_SIZE;
    int tex_height = TEXTURE_SIZE;
    
    // Safety checks
    if (!texture || !texture->addr)
        return 0xFF0000; // Bright red as error color
    
    // Clamp texture coordinates to prevent out-of-bounds access
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= tex_width) x = tex_width - 1;
    if (y >= tex_height) y = tex_height - 1;
    
    // Calculate memory address of the pixel
    dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    
    // Return the color (endian-aware)
    return *(unsigned int *) dst;
}

void render_texture(t_ray *ray_info, int x, t_wall *wall, t_game_data *data)
{
    int pixel_y;
    double texture_step;
    double texture_position;
    unsigned int pixel_color;

    wall->texture_x = (int)(wall->wall_x * (double)TEXTURE_HEIGHT);
    if (ray_info->side == 0 && ray_info->ray_direction_x > 0)
        wall->texture_x = TEXTURE_SIZE - wall->texture_x - 1;
    if (ray_info->side == 1 && ray_info->ray_direction_y < 0)
        wall->texture_x = TEXTURE_SIZE - wall->texture_x - 1;

    texture_step = 1.0 * TEXTURE_HEIGHT / wall->line_height;
    texture_position = (wall->draw_start - SCREEN_HEIGHT / 2 + wall->line_height / 2) * texture_step;
    pixel_y = wall->draw_start;

    while (pixel_y < wall->draw_end)
    {
        wall->texture_y = (int)texture_position & (TEXTURE_HEIGHT - 1);
        texture_position += texture_step;
        pixel_color = get_texture_color(data->textures + wall->texture_number, wall->texture_y, wall->texture_x);
        if (ray_info->side == 1)
            pixel_color = (pixel_color >> 1) & 8355711;
        put_pixel_to_mlx(data, x, pixel_y, pixel_color);
        pixel_y++;
    }
}
