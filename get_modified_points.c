/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modified_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:47:02 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/02 15:52:31 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	matrix_application(t_point point, double angle_x, double angle_y)
{
	t_point	*projection_matrix;
	t_point	*rotation_matrix_x;
	t_point	*rotation_matrix_y;
	t_point	*_2d_rotation;

	projection_matrix = get_projection_matrix();
	_2d_rotation = get_2d_rotation_matrix(0.2);
	rotation_matrix_x = get_rotation_matrix_x(angle_x);
	rotation_matrix_y = get_rotation_matrix_y(angle_y);
	multply_rot(rotation_matrix_x, &point);
	multply_rot(rotation_matrix_y, &point);
	multply_rot(_2d_rotation, &point);
	apply_2x2_matrix(projection_matrix, &point);
	free(projection_matrix);
	free(rotation_matrix_x);
	free(rotation_matrix_y);
	free(_2d_rotation);
	//
	return (point);
}
t_point	**get_modified_points(t_map *map, double angle_x, double angle_y)
{
	int		i;
	int		j;
	t_point	**points;

	points = malloc(sizeof(t_point *) * map->height);
	i = 0;
	while (i < map->height)
	{
		points[i] = malloc(sizeof(t_point) * map->width);
		j = 0;
		while (j < map->width)
		{
			points[i][j] = matrix_application(map->points[i][j], angle_x,
					angle_y);
			points[i][j].x = WINDOW_WIDTH / 2 + points[i][j].x;
			points[i][j].y = WINDOW_HEIGHT / 2 + points[i][j].y;
			points[i][j].color = map->points[i][j].color;
			j++;
		}
		i++;
	}
	return (points);
}
