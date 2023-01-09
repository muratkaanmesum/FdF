/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modified_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:47:02 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 14:01:26 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	matrix_application(t_point point, t_settings *settings)
{
	t_point	*projection_matrix;
	t_point	*rotation_matrix_x;
	t_point	*rotation_matrix_y;
	t_point	*parallel_matrix;

	parallel_matrix = get_parallel_projection_matrix(1);
	projection_matrix = get_projection_matrix(settings->scale,
			settings->scale
			/ settings->height);
	rotation_matrix_x = get_rotation_matrix_x(settings->angle_x);
	rotation_matrix_y = get_rotation_matrix_y(settings->angle_y);
	multply_rot(rotation_matrix_x, &point);
	multply_rot(rotation_matrix_y, &point);
	if (settings->parallel == 1)
		apply_2x2_matrix(parallel_matrix, &point);
	apply_2x2_matrix(projection_matrix, &point);
	free(projection_matrix);
	free(rotation_matrix_x);
	free(rotation_matrix_y);
	free(parallel_matrix);
	return (point);
}

void	add_data(t_point *point, t_all *all, int i, int j)
{
	point->x = (all->mlx->window_width / 2 + point->x)
		+ all->settings->x_offset;
	point->y = (all->mlx->window_height / 2 + point->y)
		+ all->settings->y_offset;
	if (all->settings->color_state == 0)
		point->color = all->map->points[i][j].color;
	else
		point->color = 0xFFFFFF;
}

t_point	**get_modified_points(t_all *all)
{
	int		i;
	int		j;
	t_point	**points;

	points = malloc(sizeof(t_point *) * all->map->height);
	i = 0;
	while (i < all->map->height)
	{
		points[i] = malloc(sizeof(t_point) * all->map->width);
		j = 0;
		while (j < all->map->width)
		{
			points[i][j] = matrix_application(all->map->points[i][j],
					all->settings);
			add_data(&points[i][j], all, i, j);
			j++;
		}
		i++;
	}
	return (points);
}
