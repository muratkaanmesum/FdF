#include "fdf.h"
void	assign_hooks(t_all *all)
{
	mlx_key_hook(all->mlx->mlx_win, handle_keys, all);
	mlx_mouse_hook(all->mlx->mlx_win, handle_mouse_click, all);
	mlx_loop_hook(all->mlx->mlx, handle_loop, all);
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
	all = malloc(sizeof(t_all));
	all->settings = malloc(sizeof(t_settings));
	map = get_map(argv[1]);
	if (map == NULL)
		exit(0);
	mlx->window_height = 1080;
	mlx->window_width = 1368;
	mlx->mlx = mlx_init();
	all->map = map;
	all->mlx = mlx;
	set_settings(all);
	all->img = img;
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->window_width,
			mlx->window_height, "FdF");
	img = render_map(all);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	write_settings(all);
	assign_hooks(all);
	mlx_loop(mlx->mlx);
	return (0);
}
