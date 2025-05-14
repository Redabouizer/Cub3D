/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:30:04 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/14 01:25:35 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils.h"
# include "../../mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define PLAYER_ROTATION_SPEED 0.1
# define PLAYER_MOVE_SPEED 0.1
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 512
# define MAX_BUFFER_SIZE 20
# define TEXTURE_HEIGHT 64
# define TEXTURE_SIZE 64
# define COLLISION_MARGIN 0.2

# define ESC_LINUX 65307
# define SPACE_LINUX  32
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_LINUX 65362
# define DOWN_LINUX 65364
# define LEFT_LINUX 65361
# define RIGHT_LINUX 65363
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
	t_mem			**mm;
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

typedef struct s_texture {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

//********************Struct Ray Casting*********************************//

typedef struct s_dir_data
{
	double	dir_x;
	double	dir_y;
	double	move_dist;
}	t_dir_data;

typedef struct s_ray_init
{
	double	start_x;
	double	start_y;
	double	direction_x;
	double	direction_y;
}	t_ray_init;

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

typedef struct s_game_data
{
	int				bits_per_pixel;
	int				**world_map;
	int				line_length;
	int				endian;
	int				map_width;
	int				map_height;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	void			*mlx;
	void			*window;
	void			*img;
	char			*addr;
	int				**level_map;
	t_texture		textures[5];
	t_player		player;
	t_ray			raycaster;
}	t_game_data;

typedef struct s_point
{
	double	x_p;
	double	y_p;
}	t_point;

//********************Prototype parser*********************************//

int		open_fd(const char *file);
char	*read_fd(int fd);
int		close_fd(int fd);
t_map	*init_map(t_mem **manager);
void	*my_malloc(t_mem **manager, size_t size);
void	cleanup(t_mem **manager);
int		create_trgb(int t, int r, int g, int b);
int		check_zero_space(t_map *map);
int		validate_map(t_mem **mm, const char *file);
char	*ft_strjoin_mm(t_mem **manager, char const *s1, char const *s2);
char	**ft_split_mm(t_mem **manager, char const *s, char c);
int		validate_wrapper(char *trim, int *mp_end, char **lst_mp_l);
int		validate_state(char *first_map_line, char *last_map_line);
int		check_texture(const char *path);
int		has_trailing_comma(const char *trimmed);
int		validate_color_components(char **values, int vals[3]);
int		check_map(const char *str);
int		check_ext(char *file);
int		validate_continuous_ones(const char *line);
int		check_player_count(char *trimmed, int *ply_count);
void	cleanup_map_lines(char *first_map_line, char *last_map_line);
int		free_values(char **values);
int		add_map_line(t_mem **manager, char ***lines, char *trimmed, int *count);
t_map	*parse_map_file(t_mem **manager, const char *file);
int		process_file(const char *file);
int		process_line(t_mem **manager, char *line, t_line_proc *proc);
int		get_color(const char *color, unsigned int *result);
int		process_meta_line(char *trimmed, int *tab);
void	pad_map_line(t_mem **m, t_map *map, char **lines, int i);
int		count_strings(char **values);
int		process_metadata_line(t_mem **manager, char *trim, t_line_proc *proc);
int		set_texture(char **texture, char *line);
int		validate_map_borders(const char *line);
int		load_textures(t_game_data *data, t_map *map);
int		get_texture_color(t_texture *texture, int y, int x);
int		retrieve_texture_color(t_texture *texture, int y, int x);
char	**allocate_texture_paths(t_game_data *data, t_map *map);
void	cleanup_textures(t_game_data *data, size_t loaded_count);
void	space_to_one(t_map *map);

//********************Prototype Ray Casting*********************************//
int		is_door_accessible(t_game_data *game_data, int x_coord, int y_coord);
void	initialize_collision_ray(t_ray *ray, t_ray_init *init);
int		detect_collision_side(t_game_data *game_data, double target_x,
			double target_y, double *collision_distance);
int		is_wall_colliding(t_game_data *game_data,
			double target_x, double target_y);
void	process_movement(t_game_data *game_data, double move_x,
			double move_y, double speed);
void	interact_with_door(t_game_data *game_data);
void	move_forward(t_game_data *game_data, t_event event);
void	move_backward(t_game_data *game_data, t_event event);
void	move_rightward(t_game_data *game_data, t_event event);
void	move_leftward(t_game_data *game_data, t_event event);
int		handle_mouse_enter(t_game_data *data);
int		handle_mouse_leave(t_game_data *data);
void	refresh_image(t_game_data *data);
int		handle_mouse_move(int x, int y, t_game_data *data);
int		handle_key_press(int keycode, t_game_data *data);
int		handle_mouse_enter(t_game_data *data);
int		handle_mouse_leave(t_game_data *data);
void	refresh_image(t_game_data *data);
void	adjust_fov(t_game_data *data, int delta_x);
int		close_window(t_game_data *data);
void	calculate_wall_distance(t_ray *ray_info,
			t_wall *wall, t_game_data *data);
void	compute_line_height(t_wall *wall);
void	verify_door_hit(t_game_data *data,
			t_ray *ray_info, int *hit, int *is_door);
void	process_wall_hit(t_game_data *data,
			t_ray *ray_info, int *hit, int *is_door);
void	compute_ray_data(t_game_data *data, t_ray *ray_info, int x);
void	compute_steps(t_game_data *data, t_ray *ray_info);
void	execute_dda(t_game_data *data, t_ray *ray_info);
int		render_scene(t_game_data *data);
void	turn_left(t_game_data *game_data, t_event *event);
void	turn_right(t_game_data *game_data, t_event *event);
void	refresh_image(t_game_data *game_data);
void	setup_data(t_game_data *data, t_map *map);
void	setup_world_map(t_game_data *data, t_map *map);
void	setup_player_direction(t_game_data *data, t_map *map);
void	insert_doors_into_map(t_game_data *data);
void	generate_world_map(t_game_data *data, t_map *map);
void	put_pixel_to_mlx(t_game_data *data, int x, int y, int color);
void	compute_wall_x(t_ray *ray_info, t_wall *wall, t_game_data *data);
void	render_floor_and_ceiling(t_game_data *data);
void	release_textures(char **file_paths);
void	render_texture(t_ray *ray_info, int x, t_wall *wall, t_game_data *data);
void	free_map_resources(t_map *map);
void	display_destruction(t_game_data *data);
void	free_all(t_game_data *data, t_map *map, int flag);
void	free_path(char **paths);
void	free_textures(t_game_data *data);
void	free_gnl(void);

#endif
