/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modified_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:47:02 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/07 15:36:04 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	matrix_application(t_point point, t_settings *settings)
{
	t_point	*projection_matrix;
	t_point	*rotation_matrix_x;
	t_point	*rotation_matrix_y;

	projection_matrix = get_projection_matrix(settings->scale,
												settings->scale);
	rotation_matrix_x = get_rotation_matrix_x(settings->angle_x);
	rotation_matrix_y = get_rotation_matrix_y(settings->angle_y);
	multply_rot(rotation_matrix_x, &point);
	multply_rot(rotation_matrix_y, &point);
	apply_2x2_matrix(projection_matrix, &point);
	free(projection_matrix);
	free(rotation_matrix_x);
	free(rotation_matrix_y);
	return (point);
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
			if (all->map->points[i][j].z != 0)
				points[i][j] = matrix_application(all->map->points[i][j],
													all->settings);
			else
				points[i][j] = matrix_application(all->map->points[i][j],
						all->settings);
			points[i][j].x = all->mlx->window_width / 2 + points[i][j].x;
			points[i][j].y = all->mlx->window_height / 2 + points[i][j].y;
			points[i][j].color = all->map->points[i][j].color;
			j++;
		}
		i++;
	}
	return (points);
}
