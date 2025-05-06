/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:09:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/06 11:42:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/utils.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_parser {
	int		map_on;
	int		map_ended;
	int		empty_lines;
	char	*first_line;
	char	*last_line;
}	t_parser;

typedef struct s_mem
{
	void			*ptr;
	struct s_mem	*next;
}				t_mem;

typedef struct s_map
{
	char			player_direction;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**file_content;
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
}	t_map;

int		open_fd(const char *file);
char	*read_fd(int fd);
int		close_fd(int fd);

t_map	*init_map(t_mem **manager);
char	*ft_allocat(int fd);
void	*my_malloc(t_mem **manager, size_t size);
void	cleanup(t_mem **manager);

int		create_trgb(int t, int r, int g, int b);
int		fd_line(char *file);
int		ft_count(char **strs, char c);

int		validate_map(t_mem **mm, const char *file);

char	*ft_strjoin_mm(t_mem **manager, char const *s1, char const *s2);
char	**ft_split_mm(t_mem **manager, char const *s, char c);

/*   ft_check.c                                         :+:      :+:    :+:   */
int		validate_map_section_wrapper(char *trim, int *mp_end, char **lst_mp_l);
int		validate_final_map_state(char *first_map_line, char *last_map_line);

/*   ft_utils.c                                         :+:      :+:    :+:   */
int		check_map(const char *str);
int		check_ext(char *file);
int		validate_continuous_ones(const char *line);
int		check_player_count(char *trimmed, int *ply_count);
int		check_trailing_newlines(int fd);

/*   ft_node.c                                          :+:      :+:    :+:   */
void	cleanup_map_lines(char *first_map_line, char *last_map_line);
int		free_values(char **values);
void	add_map_line(t_mem **m, char ***lines, char *trimmed, int *count);

/*   ft_map.c                                           :+:      :+:    :+:   */
t_map	*parse_map_file(t_mem **manager, const char *file);

/*   ft_process.c                                       :+:      :+:    :+:   */
int		process_file(const char *file);
void	process_line(t_mem **manager, t_map *map, char *line,
			int *map_started, char ***map_lines, int *map_line_count);

/*   ft_color.c                                         :+:      :+:    :+:   */
int		get_color(const char *color, unsigned int *result);
int		process_meta_line(char *trimmed, int *tab);

/*   ft_color.c                                         :+:      :+:    :+:   */
void	pad_map_line(t_mem **m, t_map *map, char **lines, int i);

/*   ft_data.c                                          :+:      :+:    :+:   */

void	process_metadata_line(t_mem **manager, t_map *map, char *trimmed,
			int *map_started, char ***map_lines, int *map_line_count);

void	print_map_data(t_map *map);

#endif
