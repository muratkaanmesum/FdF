#include "fdf.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	map = get_map(argv[1]);
	// t_data	img;
	// x = 5;
	// y = 5;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// &img.line_length,
	// 		&img.endian);
	// print_triangle(&img, 0, 0, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_hook(mlx_win, 2, 1L << 0, key_press, &img);
	// mlx_loop(mlx);
}
