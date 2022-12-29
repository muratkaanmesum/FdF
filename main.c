#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	t_mlx	*mlx;
	int		j;

	mlx = malloc(sizeof(t_mlx));
	map = get_map(argv[1]);
	i = 0;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, render_map(map, mlx)->img,
			0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
