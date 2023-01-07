#ifndef FDF_H
# define FDF_H
# include "Get_Next_Line/get_next_line.h"
# include "ft_Printf/ft_printf.h"
# include "ft_Printf/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 1360
# define WINDOW_HEIGHT 768
typedef struct s_img
{
	void		*img;
	int			bpp;
	int			line_length;
	void		*address;
	int			endian;
}				t_img;
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			window_width;
	int			window_height;
}				t_mlx;
typedef struct s_line_point
{
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	int			delta_x;
	int			delta_y;
	int			error;
	int			delta_error;
	int			color;
	int			x_sign;
	int			y_sign;
}				t_line_point;
typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;
typedef struct s_map
{
	t_point		**points;
	int			width;
	int			height;

}				t_map;
typedef struct s_settings
{
	double		angle_x;
	double		angle_y;
	double		scale;
}				t_settings;
typedef struct s_all
{
	t_map		*map;
	t_mlx		*mlx;
	t_img		*img;
	t_settings	*settings;
}				t_all;

t_map			*get_map(char *file_name);
int				check_map(char **map);
int				does_include(char *str, char c);
t_img			*render_map(t_all *all);
t_point			**get_points(char **map);
int				get_map_length(char **map);
void			apply_2x2_matrix(t_point *matrix1, t_point *matrix2);
t_point			*get_rotation_matrix_x(double angle);
t_point			*get_projection_matrix(int scale_x, int scale_y);
void			multply_rot(t_point *matrix1, t_point *matrix2);
t_point			**get_modified_points(t_all *all);
t_point			*get_rotation_matrix_y(double angle);
t_point			*get_2d_rotation_matrix(double angle);
void			free_split(char **split);
void			free_all(t_all *all);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				hex_to_decimal(const char *hex);
void			clear_img(t_all *all);
double			get_scale(t_all *all);
void			draw_map(t_all *all);
#endif
