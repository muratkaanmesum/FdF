/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_matrices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:08:01 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 14:08:01 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_2x2_matrix(t_point *matrix1, t_point *matrix2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	matrix2->x = (matrix1[0].x * matrix2->x) + (matrix1[0].y * matrix2->y)
		+ (matrix1[0].z * matrix2->z);
	matrix2->y = (matrix1[1].x * matrix2->x) + (matrix1[1].y * matrix2->y)
		+ (matrix1[1].z * matrix2->z);
}

void	multply_rot(t_point *matrix1, t_point *matrix2)
{
	matrix2->x = (matrix1[0].x * matrix2->x) + (matrix1[0].y * matrix2->y)
		+ (matrix1[0].z * matrix2->z);
	matrix2->y = (matrix1[1].x * matrix2->x) + (matrix1[1].y * matrix2->y)
		+ (matrix1[1].z * matrix2->z);
	matrix2->z = (matrix1[2].x * matrix2->x) + (matrix1[2].y * matrix2->y)
		+ (matrix1[2].z * matrix2->z);
}
