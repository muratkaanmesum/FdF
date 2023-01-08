/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:08:01 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/08 16:50:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_map(t_all *all)
{
	t_point	**projected_matrix;
	int		scale;

	clear_img(all);
	projected_matrix = get_modified_points(all);
	draw_lines(projected_matrix, all);
	free_points(projected_matrix, all->map);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, all->img->img, 0,
			0);
	if (all->settings->write_toggle == 1)
		write_settings(all);
}

t_img	*render_map(t_all *all)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(all->mlx->mlx, all->mlx->window_width,
			all->mlx->window_height);
	img->address = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	all->img = img;
	draw_map(all);
	return (img);
}
