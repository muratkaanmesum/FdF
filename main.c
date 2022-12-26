#include "fdf.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	map = get_map(argv[1]);
	check_map(map);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1000, 1000, "Hello world!");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, render_map(map, mlx)->img,
			0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
