/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modified_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:47:02 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/03 17:02:17 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	matrix_application(t_point point, double angle_x, double angle_y,
		int scale)
{
	t_point	*projection_matrix;
	t_point	*rotation_matrix_x;
	t_point	*rotation_matrix_y;

	projection_matrix = get_projection_matrix(scale);
	rotation_matrix_x = get_rotation_matrix_x(angle_x);
	rotation_matrix_y = get_rotation_matrix_y(angle_y);
	multply_rot(rotation_matrix_x, &point);
	multply_rot(rotation_matrix_y, &point);
	apply_2x2_matrix(projection_matrix, &point);
	free(projection_matrix);
	free(rotation_matrix_x);
	free(rotation_matrix_y);
	return (point);
}
t_point	**get_modified_points(t_map *map, double angle_x, double angle_y,
		int scale, t_mlx *mlx)
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
			if (map->points[i][j].z != 0)
				points[i][j] = matrix_application(map->points[i][j], angle_x,
						angle_y, scale / 2);
			else
				points[i][j] = matrix_application(map->points[i][j], angle_x,
						angle_y, scale);
			points[i][j].x = (mlx->window_width / 2) + points[i][j].x;
			points[i][j].y = mlx->window_height / 2 - points[i][j].y;
			points[i][j].color = map->points[i][j].color;
			j++;
		}
		i++;
	}
	return (points);
}
