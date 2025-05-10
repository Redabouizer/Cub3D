/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:08:17 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 20:32:34 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int process_metadata(t_map *map, char *line)
{
    if (!ft_strncmp(line, "NO ", 3))
        return (set_texture(&map->north_texture, line));
    else if (!ft_strncmp(line, "SO ", 3))
        return (set_texture(&map->south_texture, line));
    else if (!ft_strncmp(line, "WE ", 3))
        return (set_texture(&map->west_texture, line));
    else if (!ft_strncmp(line, "EA ", 3))
        return (set_texture(&map->east_texture, line));
    else if (!ft_strncmp(line, "F ", 2))
        return (get_color(line + 2, &map->floor_color));
    else if (!ft_strncmp(line, "C ", 2))
        return (get_color(line + 2, &map->ceiling_color));
    return (1);
}
int process_metadata_line(t_mem **manager, char *trim, t_line_proc *proc)
{
    int result;

    if (!process_metadata(proc->map, trim))
    {
        free(trim);
        return (0);
    }
    
    if (check_map(trim))
    {
        *(proc->map_started) = 1;
        result = add_map_line(manager, proc->map_lines, trim, proc->map_line_count);
    }
    else
    {
        result = 1;
    }
    
    free(trim); // Always free here
    return (result);
}
