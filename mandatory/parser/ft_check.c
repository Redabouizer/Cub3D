/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:47:27 by marvin            #+#    #+#             */
/*   Updated: 2025/05/11 15:43:47 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_map_borders(const char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (line[0] != '1' || line[len - 1] != '1'))
		return (0);
	return (1);
}

int validate_map_section(char *trimmed, int *map_ended, char **last_line)
{
    if (!check_map(trimmed))
        return (printf("Error: Non-map line detected\n"), 0);
    if (*map_ended)
        return (printf("Error: Double map detected\n"), 0);
    if (!validate_map_borders(trimmed))
        return (printf("Error: Invalid map borders\n"), 0);
    
    if (*last_line)
        free(*last_line);
    *last_line = ft_strdup(trimmed);
    if (!*last_line)  // Add check for strdup failure
        return (printf("Error: Memory allocation failed\n"), 0);
    return (1);
}

int	validate_wrapper(char *trim, int *mp_end, char **lst_mp_l)
{
	if (*mp_end)
		return (printf("Error: Map content after empty line\n"), 0);
	return (validate_map_section(trim, mp_end, lst_mp_l));
}

int validate_state(char *first_map_line, char *last_map_line)
{
    if (last_map_line && !validate_continuous_ones(last_map_line))
    {
        cleanup_map_lines(first_map_line, last_map_line);
        return (printf("Error: Last line invalid\n"), 0);
    }
    cleanup_map_lines(first_map_line, last_map_line);
    return (1);
}

int play_rey(t_map *map)
{
	t_game_data data;
	t_ray raycaster;
    
    raycaster = (t_ray){0};
	setup_data(&data, map);
    data.raycaster = raycaster;
    generate_world_map(&data, map);
    if (load_textures(&data, map) != 0)
	{
        free_all(&data, map, 1);
        return (0);
    }
	    // Setup hooks and start game loop
	mlx_hook(data.window, 2, 1L << 0, handle_key_press, &data);
	mlx_hook(data.window, 6, 1L << 6, handle_mouse_move, &data);
	mlx_hook(data.window, 7, 1L << 4, handle_mouse_enter, &data);
	mlx_hook(data.window, 8, 1L << 5, handle_mouse_leave, &data);
	mlx_hook(data.window, 17, 1L << 1, close_window, &data);
		
	render_scene(&data);
	mlx_loop(data.mlx);
	free_all(&data, map, 1);
	return (1);
}
int validate_map(t_mem **mm, const char *file)
{
    t_map *map;

    if (process_file(file) != 0)
        return (get_next_line(-1, true),-1);
    map = parse_map_file(mm, file);
    if (!map)
        return (-1);
    
    if (!play_rey(map))
        return (-1);
    return (0);
}
