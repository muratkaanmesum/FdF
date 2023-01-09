/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:31 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 13:45:34 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_loop(t_all *all)
{
	if (all->settings->rotate_y_state == 1)
	{
		all->settings->angle_y += 0.001;
		draw_map(all);
	}
	return (0);
}

void	rotate(int keycode, t_all *all)
{
	if (keycode == 1)
		all->settings->angle_x -= 0.1;
	else if (keycode == 13)
		all->settings->angle_x += 0.1;
	else if (keycode == 0)
		all->settings->angle_y -= 0.1;
	else if (keycode == 2)
		all->settings->angle_y += 0.1;
}

void	translate(int keycode, t_all *all)
{
	if (keycode == 126)
		all->settings->y_offset -= 10;
	else if (keycode == 125)
		all->settings->y_offset += 10;
	else if (keycode == 123)
		all->settings->x_offset -= 10;
	else if (keycode == 124)
		all->settings->x_offset += 10;
}

int	handle_keys(int keycode, t_all *all)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		free_all(all);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		rotate(keycode, all);
	else if (keycode == 126 || keycode == 125 || keycode == 123
		|| keycode == 124)
		translate(keycode, all);
	else if (keycode == 15)
		all->settings->rotate_y_state = all->settings->rotate_y_state != 1;
	else if (keycode == 8)
		all->settings->color_state = all->settings->color_state != 1;
	else if (keycode == 49)
		set_settings(all);
	else if (keycode == 4)
		all->settings->write_toggle = all->settings->write_toggle != 1;
	else if (keycode == 35)
		all->settings->parallel = all->settings->parallel != 1;
	draw_map(all);
	return (0);
}

int	handle_mouse_click(int keycode, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		all->settings->scale += 0.5;
	else if (keycode == 5)
	{
		if (all->settings->scale > 0.5)
		{
			all->settings->scale -= 0.5;
		}
	}
	else if (keycode == 1)
		all->settings->height += 0.1;
	else if (keycode == 3)
		all->settings->height -= 0.1;
	draw_map(all);
	return (0);
}
