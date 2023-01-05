#include "fdf.h"

int	close_window(int keycode, t_all *all)
{
	ft_printf("keycode: %d", keycode);
	if (keycode == 53)
	{
		//might need to delete this
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		free_all(all);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*img;
	t_all	*all;

	if (argc < 2)
	{
		ft_printf("Error: no file specified\n");
		exit(0);
	}
	mlx = malloc(sizeof(t_mlx));
	map = get_map(argv[1]);
	if (map == NULL)
		exit(0);
	mlx->window_height = 1080;
	mlx->window_width = 1920;
	mlx->mlx = mlx_init();
	img = render_map(map, mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->window_width,
			mlx->window_height, "FdF");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	all = malloc(sizeof(t_all));
	all->map = map;
	all->mlx = mlx;
	mlx_key_hook(mlx->mlx_win, close_window, all);
	mlx_loop(mlx->mlx);
	return (0);
}
