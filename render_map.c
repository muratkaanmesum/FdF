/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:08:01 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/26 22:16:15 by kaan             ###   ########.fr       */
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
t_point	*get_point(int start_x, int start_y, int end_x, int end_y)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->x_start = start_x;
	p->y_start = start_y;
	p->x_end = end_x;
	p->y_end = end_y;
	p->delta_x = abs(p->x_end - p->x_start);
	p->delta_y = abs(p->y_end - p->y_start);
	p->error = p->delta_x - p->delta_y;
	if (p->x_start < p->x_end)
		p->x_sign = 1;
	else
		p->x_sign = -1;
	if (p->y_start < p->y_end)
		p->y_sign = 1;
	else
		p->y_sign = -1;
	return (p);
}

void	draw_line(t_point *p, t_img *img, int color)
{
	int	x;
	int	y;

	x = p->x_start;
	y = p->y_start;
	while (x != p->x_end || y != p->y_end)
	{
		my_mlx_pixel_put(img, x, y, color);
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
void	draw_map(char **map, t_img *img)
{
	int		i;
	int		x;
	int		y;
	char	**str;
	char	*color;
	int		j;

	i = 0;
	x = 0;
	y = 20;
	j = 0;
	while (map[i])
	{
		str = ft_split(map[i], ' ');
		j = 0;
		x = 0;
		while (str[j])
		{
			//color = ft_substr(str[j], ft_strchr(str[j], ',') - str[i] + 1, 6);
			if (does_include(str[j], ','))
				draw_line(get_point(x, y, x + 20, y), img, ft_atoi(color));
			else
				draw_line(get_point(x, y, x + 20, y), img, 0xFFFFFF);
			j++;
			x += 20;
		}
		free_split(str);
		y += 20;
		i++;
	}
}

t_img	*render_map(char **map, t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx->mlx, 1920, 1080);
	img->address = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	draw_map(map, img);
	return (img);
}
