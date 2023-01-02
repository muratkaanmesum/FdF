#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*img;

	if (argc < 2)
	{
		ft_printf("Error: no file specified\n");
		exit(0);
	}
	mlx = malloc(sizeof(t_mlx));
	map = get_map(argv[1]);
	if (map == NULL)
		exit(0);
	mlx->mlx = mlx_init();
	img = render_map(map, mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	mlx_loop(mlx->mlx);
	free_all(map, mlx);
	return (0);
}
