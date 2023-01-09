/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:32:49 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 12:36:30 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	draw_horizontal(t_point **projected_points, t_all *all)
{
	int				i;
	int				j;
	t_line_point	*point;

	i = 0;
	j = 0;
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
}

void	draw_lines(t_point **projected_points, t_all *all)
{
	t_line_point	*point;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (j < all->map->width)
	{
		i = 0;
		draw_horizontal(projected_points, all);
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
