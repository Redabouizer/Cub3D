#include "../includes/cub3d.h"

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
    if (texture->endian == 1) // Big endian
        return ((unsigned int)dst[0] << 24) | ((unsigned int)dst[1] << 16) | 
               ((unsigned int)dst[2] << 8) | (unsigned int)dst[3];
    else // Little endian (most common)
        return ((unsigned int)dst[3] << 24) | ((unsigned int)dst[2] << 16) | 
               ((unsigned int)dst[1] << 8) | (unsigned int)dst[0];
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

void calculate_wall_distance(t_ray *ray_info, t_wall *wall, t_game_data *data __attribute__ ((unused)))
{
    if (ray_info->side == 0)
        wall->distance_to_wall = (ray_info->side_distance_x - ray_info->delta_distance_x);
    else
        wall->distance_to_wall = (ray_info->side_distance_y - ray_info->delta_distance_y);
}

void compute_line_height(t_wall *wall)
{
    wall->line_height = (int)(SCREEN_HEIGHT / wall->distance_to_wall);
    wall->draw_start = -wall->line_height / 2 + SCREEN_HEIGHT / 2;

    if (wall->draw_start < 0)
        wall->draw_start = 0;

    wall->draw_end = wall->line_height / 2 + SCREEN_HEIGHT / 2;
    if (wall->draw_end >= SCREEN_HEIGHT)
        wall->draw_end = SCREEN_HEIGHT - 1;
}

void verify_door_hit(t_game_data *data, t_ray *ray_info, int *hit, int *is_door)
{
    if (data->level_map[ray_info->map_y][ray_info->map_x] == 1)
        *hit = 1;
    else if (data->level_map[ray_info->map_y][ray_info->map_x] == 2)
    {
        *hit = 1;
        *is_door = 1;
    }
}

void process_wall_hit(t_game_data *data, t_ray *ray_info, int *hit, int *is_door)
{
    while (*hit == 0)
    {
        if (ray_info->side_distance_x < ray_info->side_distance_y)
        {
            ray_info->side_distance_x += ray_info->delta_distance_x;
            ray_info->map_x += ray_info->step_x;
            ray_info->side = 0;
        }
        else
        {
            ray_info->side_distance_y += ray_info->delta_distance_y;
            ray_info->map_y += ray_info->step_y;
            ray_info->side = 1;
        }

        if (ray_info->map_x < 0 || ray_info->map_x >= data->map_width ||
            ray_info->map_y < 0 || ray_info->map_y >= data->map_height)
        {
            *hit = 1;
            ray_info->side_distance_x = INFINITY;
            ray_info->side_distance_y = INFINITY;
        }
        else if (data->level_map[ray_info->map_y][ray_info->map_x] == 1)
        {
            *hit = 1;
        }
        else if (data->level_map[ray_info->map_y][ray_info->map_x] == 2)
        {
            *hit = 1;
            *is_door = 1;
        }
    }
}
