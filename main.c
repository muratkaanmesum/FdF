/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:21:13 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 14:21:47 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_hooks(t_all *all)
{
	mlx_key_hook(all->mlx->mlx_win, handle_keys, all);
	mlx_mouse_hook(all->mlx->mlx_win, handle_mouse_click, all);
	mlx_loop_hook(all->mlx->mlx, handle_loop, all);
}

t_all	*init_structs(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->settings = malloc(sizeof(t_settings));
	all->mlx = malloc(sizeof(t_mlx));
	all->mlx->window_height = 1080;
	all->mlx->window_width = 1920;
	return (all);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_all	*all;

	if (argc < 2)
	{
		ft_printf("Error: no file specified\n");
		exit(0);
	}
	all = init_structs();
	map = get_map(argv[1]);
	if (map == NULL)
		exit(0);
	all->mlx->mlx = mlx_init();
	all->map = map;
	set_settings(all);
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->mlx->window_width,
			all->mlx->window_height, "FdF");
	all->img = render_map(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, all->img->img, 0,
		0);
	write_settings(all);
	assign_hooks(all);
	mlx_loop(all->mlx->mlx);
	return (0);
}
