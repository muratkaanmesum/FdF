#include "fdf.h"

void	set_settings(t_all *all)
{
	all->settings->angle_x = 0;
	all->settings->angle_y = 0;
	all->settings->scale = get_scale(all);
	all->settings->x_offset = 0;
	all->settings->y_offset = 0;
	all->settings->color_state = 0;
	all->settings->rotate_y_state = 0;
	all->settings->height = 1;
	all->settings->write_toggle = 1;
}
void	write_controls(t_all *all)
{
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 50, 0xFFFFFF,
			"Controls:");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 100, 0xFFFFFF,
			"W A S D ROTATE");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 120, 0xFFFFFF,
			"Arrow Keys TRANSLATE");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 140, 0xFFFFFF,
			"R TOGGLE AUTO ROTATE");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 160, 0xFFFFFF,
			"C TOGGLE COLOR");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 180, 0xFFFFFF,
			"Scrool Wheel ZOOM");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 200, 0xFFFFFF,
			"Press H to hide this menu");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 220, 0xFFFFFF,
			"Space to Reset");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 240, 0xFFFFFF,
			"Press P to parallel projection");
}
void	write_settings(t_all *all)
{
	char	*scale;
	char	*angle_x;
	char	*angle_y;

	scale = ft_itoa(all->settings->scale);
	angle_x = ft_itoa(all->settings->angle_x);
	angle_y = ft_itoa(all->settings->angle_y);
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 10, 0xFFFFFF,
			"Press ESC to exit");
	write_controls(all);
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 300, 0xFFFFFF,
			"Scale = ");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 60, 300, 0xFFFFFF, scale);
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 350, 0xFFFFFF,
			"Angle_X = ");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 70, 350, 0xFFFFFF,
			angle_x);
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 10, 400, 0xFFFFFF,
			"Angle_Y = ");
	mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, 70, 400, 0xFFFFFF,
			angle_y);
	free(scale);
	free(angle_x);
	free(angle_y);
}
