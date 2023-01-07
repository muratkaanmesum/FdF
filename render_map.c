/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:08:01 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/07 22:29:02 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_line_point	*get_line_point(t_point start, t_point end)
{
	t_line_point	*point;

	point = malloc(sizeof(t_line_point));
	point->x_start = start.x;
	point->y_start = start.y;
	point->x_end = end.x;
	point->y_end = end.y;
	point->delta_x = abs(point->x_end - point->x_start);
	point->delta_y = abs(point->y_end - point->y_start);
	if (point->x_start < point->x_end)
		point->x_sign = 1;
	else
		point->x_sign = -1;
	if (point->y_start < point->y_end)
		point->y_sign = 1;
	else
		point->y_sign = -1;
	point->error = point->delta_x - point->delta_y;
	return (point);
}

void	draw_line(t_line_point *p, t_all *all, int color)
{
	int	x;
	int	y;

	x = p->x_start;
	y = p->y_start;
	while (x != p->x_end || y != p->y_end)
	{
		if (x >= 0 && x < all->mlx->window_width && y >= 0
			&& y < all->mlx->window_height)
			my_mlx_pixel_put(all->img, x, y, color);
		p->delta_error = 2 * p->error;
		if (p->delta_error > -p->delta_y)
		{
			p->error -= p->delta_y;
			x += p->x_sign;
		}
		if (p->delta_error < p->delta_x)
		{
			p->error += p->delta_x;
			y += p->y_sign;
		}
	}
	free(p);
}

void	draw_lines(t_point **projected_points, t_all *all)
{
	t_line_point	*point;
	int				i;
	int				j;

	i = 0;
	while (i < all->map->height)
	{
		j = 0;
		while (j < all->map->width - 1)
		{
			point = get_line_point(projected_points[i][j],
									projected_points[i][j + 1]);
			draw_line(point, all, projected_points[i][j].color);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < all->map->width)
	{
		i = 0;
		while (i < all->map->height - 1)
		{
			point = get_line_point(projected_points[i][j],
									projected_points[i + 1][j]);
			draw_line(point, all, projected_points[i][j].color);
			i++;
		}
		j++;
	}
}

void	free_points(t_point **points, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

double	get_scale(t_all *all)
{
	int	scale;

	scale = all->mlx->window_width / all->map->width;
	return (scale);
}

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
