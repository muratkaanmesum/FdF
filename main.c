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
	// for (int i = 0; i < 11; i++)
	// {
	// 	for (int j = 0; j < 19; j++)
	// 	{
	// 		printf("x: %f, y: %f, z: %f\n", map->points[i][j].x,
	// 				map->points[i][j].y, map->points[i][j].z);
	// 	}
	// }
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, render_map(map, mlx)->img,
			0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
