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
typedef struct s_point
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
}			t_point;

char		**get_map(char *str);
int			check_map(char **map);
int			does_include(char *str, char c);
t_img		*render_map(char **map, t_mlx *mlx);
#endif
