/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:09:49 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/07 14:49:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/utils.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

//********************Struct parser*********************************//
typedef struct s_parser
{
	int		map_on;
	int		map_ended;
	int		empty_lines;
	char	*first_line;
	char	*last_line;
}					t_parser;

typedef struct s_line_content
{
	int		map_on;
	int		map_end;
	int		*ply_count;
	char	*first_mp_l;
	char	*last_mp_l;
}					t_line_content;

typedef struct s_file_lines
{
	int				fd;
	int				*tab;
	t_line_content	content;
}					t_file_lines;

typedef struct s_mem
{
	void			*ptr;
	struct s_mem	*next;
}					t_mem;

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
}						t_map;

typedef struct s_line_proc
{
	int		*map_started;
	char	***map_lines;
	int		*map_line_count;
	t_map	*map;
}				t_line_proc;


//********************Struct Ray Casting*********************************//

typedef struct s_wall_collision
{
	double	radius;
	int		point_count;
	double	angle;
	double	check_x;
	double	check_y;
}	t_wall_collision;

typedef struct s_slide_movement
{
	double	slide_x;
	double	slide_y;
	double	reduced_movement;
	double	factor;
	double	test_x;
	double	test_y;
}	t_slide_movement;

typedef struct s_player
{
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_direction_x;
	double	ray_direction_y;
	int		map_x;
	int		map_y;
	double	delta_distance_x;
	double	delta_distance_y;
	double	side_distance_x;
	double	side_distance_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_wall
{
	int		texture_number;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_x;
	int		texture_y;
	double	wall_x;
	double	distance_to_wall;
}	t_wall;

typedef struct s_event
{
	double	previous_direction_x;
	double	previous_plane_x;
	double	movement_speed;
}	t_event;

// typedef struct s_texture
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_texture;

typedef struct s_map
{
	char			player_direction;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	unsigned int	floor_color;
	unsigned int ceiling_color;
	char			**file_content;
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
}	t_map;

typedef struct s_game_data
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				map_width;
	int				map_height;
	unsigned int	floor_color;
	unsigned int ceiling_color;
	void			*mlx;
	void			*window;
	void			*img;
	char			*addr;
	int				**level_map;
	//texture
	t_player		player;
	t_ray		raycaster;
}	t_game_data;

typedef struct s_point
{
	double	x_p;
	double	y_p;
}	t_point;


// typedef struct s_wall_col
// {
// 	double	radius;
// 	int		num_points;
// 	double	angle;
// 	double	check_x;
// 	double	check_y;
// }	t_wall_col;

// typedef struct s_slide
// {
// 	double	slide_x;
// 	double	slide_y;
// 	double	reduced_move;
// 	double	factor;
// 	double	test_x;
// 	double	test_y;
// }	t_slide;

// typedef struct s_player
// {
// 	double	pos_x;
// 	double	pos_y;
// 	double	dir_x;
// 	double	dir_y;
// 	double	plane_x;
// 	double	plane_y;
// }	t_player;

// typedef struct s_raycaster
// {
// 	double	camera_x;
// 	double	ray_dir_x;
// 	double	ray_dir_y;
// 	int		map_x;
// 	int		map_y;
// 	double	delta_dist_x;
// 	double	delta_dist_y;
// 	double	side_dist_x;
// 	double	side_dist_y;
// 	int		step_x;
// 	int		step_y;
// 	int		side;
// }	t_raycaster;

// typedef struct s_wall
// {
// 	int		textnum;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;
// 	int		textx;
// 	int		texty;
// 	double	wall_x;
// 	double	wall_dist;
// }	t_wall;


// typedef struct s_event
// {
// 	double	old_dirx;
// 	double	old_planex;
// 	double	move_speed;
// }	t_event;

// // typedef struct s_texture
// // {
// // 	void	*img;
// // 	char	*addr;
// // 	int		bits_per_pixel;
// // 	int		line_length;
// // 	int		endian;
// // }	t_texture;

// typedef struct s_map
// {
// 	char			player_dir;
// 	int				m_width;
// 	int				m_height;
// 	int				player_x;
// 	int				player_y;
// 	unsigned int	f_color;
// 	unsigned int	c_color;
// 	char			**file_content;
// 	char			**map;
// 	char			*no_texture;
// 	char			*so_texture;
// 	char			*we_texture;
// 	char			*ea_texture;
// }	t_map;

// typedef struct s_data
// {
// 	int				bits_per_pixel;
// 	int				line_length;
// 	int				endian;
// 	int				map_width;
// 	int				map_height;
// 	unsigned int	f_color;
// 	unsigned int	c_color;
// 	void			*mlx;
// 	void			*win;
// 	void			*img;
// 	char			*addr;
// 	int				**world_map;
// 	t_texture		textures[9];
// 	t_player		player;
// 	t_raycaster		raycaster;
// }	t_data;

// typedef struct s_point
// {
// 	double	new_x;
// 	double	new_y;
// }	t_point;

//********************Prototype parser*********************************//


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
int		validate_wrapper(char *trim, int *mp_end, char **lst_mp_l);
int		validate_state(char *first_map_line, char *last_map_line);
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
void	process_line(t_mem **manager, char *line, t_line_proc *proc);

/*   ft_color.c                                         :+:      :+:    :+:   */
int		get_color(const char *color, unsigned int *result);
int		process_meta_line(char *trimmed, int *tab);

/*   ft_color.c                                         :+:      :+:    :+:   */
void	pad_map_line(t_mem **m, t_map *map, char **lines, int i);

/*   ft_data.c                                          :+:      :+:    :+:   */
void	process_metadata_line(t_mem **manager, char *trim, t_line_proc *proc);

void	print_map_data(t_map *map);

//********************Prototype Ray Casting*********************************//


#endif
