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

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
typedef struct s_img
{
	void	*img;
	int		bpp;
	int		line_length;
	void	*address;
	int		endian;
}			t_img;
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;
typedef struct s_line_point
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		delta_x;
	int		delta_y;
	int		error;
	int		delta_error;
	int		color;
	int		x_sign;
	int		y_sign;
}			t_line_point;
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;
typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;

}			t_map;

t_map		*get_map(char *file_name);
int			check_map(char **map);
int			does_include(char *str, char c);
t_img		*render_map(t_map *map, t_mlx *mlx);
t_point		**get_points(char **map);
int			get_map_length(char **map);
t_point		*multipy_matrix_proj(t_point *matrix1, t_point matrix2);
t_point		*get_rotation_matrix_x(double angle);
t_point		*get_projection_matrix(void);
t_point		*multply_rot(t_point *matrix1, t_point matrix2);
t_point		**get_modified_points(t_map *map, double angle);

#endif
