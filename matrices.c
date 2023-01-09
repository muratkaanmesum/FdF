/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:10 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 14:08:44 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*get_projection_matrix(int scale_x, int scale_y)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = scale_x;
	matrix[0].y = 0;
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = scale_y;
	matrix[1].z = 0;
	matrix[1].color = 0;
	return (matrix);
}

t_point	*get_parallel_projection_matrix(double angle)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = 1;
	matrix[0].y = 0;
	matrix[0].z = cos(angle) * cos(angle) / sin(angle);
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = cos(angle) * sin(angle) / sin(angle);
	return (matrix);
}

t_point	*get_rotation_matrix_y(double angle)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 3);
	matrix[0].x = cos(angle);
	matrix[0].y = 0;
	matrix[0].z = sin(angle);
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[1].color = 0;
	matrix[2].x = -sin(angle);
	matrix[2].y = 0;
	matrix[2].z = cos(angle);
	return (matrix);
}

t_point	*get_rotation_matrix_x(double angle)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 3);
	matrix[0].x = 1;
	matrix[0].y = 0;
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = cos(angle);
	matrix[1].z = -sin(angle);
	matrix[1].color = 0;
	matrix[2].x = 0;
	matrix[2].y = sin(angle);
	matrix[2].z = cos(angle);
	return (matrix);
}
