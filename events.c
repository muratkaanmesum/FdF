#include "fdf.h"
int	handle_loop(t_all *all)
{
	if (all->settings->rotate_y_state == 1)
		all->settings->angle_y += 0.001;
	draw_map(all);
	return (0);
}
int	handle_keys(int keycode, t_all *all)
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
	//rotate
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
	//translate
	else if (keycode == 65361)
	{
		all->settings->x_offset -= 10;
		draw_map(all);
	}
	else if (keycode == 65363)
	{
		all->settings->x_offset += 10;
		draw_map(all);
	}
	else if (keycode == 65362)
	{
		all->settings->y_offset -= 10;
		draw_map(all);
	}
	else if (keycode == 65364)
	{
		all->settings->y_offset += 10;
		draw_map(all);
	}
	else if (keycode == 114)
	{
		all->settings->rotate_y_state = all->settings->rotate_y_state != 1;
		;
	}
	return (0);
}
int	handle_mouse_move(int x, int y, t_all *all)
{
	(void)all;
	return (0);
}

int	handle_mouse_click(int keycode, int x, int y, t_all *all)
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
	return (0);
}
