#include "fdf.h"

int	close_window(int keycode, t_all *all)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		//might need to delete this
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		free_all(all);
		exit(0);
	}
	//a = 0 d = 2 w = 13 s = 1
	if (keycode == 115)
	{
		all->settings->angle_x -= 0.1;
		draw_map(all);
	}
	else if (keycode == 119)
	{
		all->settings->angle_x += 0.1;
		draw_map(all);
	}
	else if (keycode == 97)
	{
		all->settings->angle_y -= 0.1;
		draw_map(all);
	}
	else if (keycode == 100)
	{
		all->settings->angle_y += 0.1;
		draw_map(all);
	}
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, all->img->img, 0,
			0);
	return (0);
}
int	zoom_window(int keycode, int x, int y, t_all *all)
{
	if (keycode == 4)
	{
		all->settings->scale += 0.5;
		draw_map(all);
	}
	//zoom out
	if (keycode == 5)
	{
		all->settings->scale -= 0.5;
		draw_map(all);
	}
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, all->img->img, 0,
			0);
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
	all->settings->scale = get_scale(all);
	all->settings->angle_x = 0;
	all->settings->angle_y = 0;
	img = render_map(all);
	all->img = img;
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->window_width,
			mlx->window_height, "FdF");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	mlx_key_hook(mlx->mlx_win, close_window, all);
	mlx_mouse_hook(mlx->mlx_win, zoom_window, all);
	mlx_loop(mlx->mlx);
	return (0);
}
