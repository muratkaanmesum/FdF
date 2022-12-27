#include "fdf.h"
#include "math.h"

t_point	*get_projection_matrix(void)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = 1;
	matrix[0].y = 0;
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[1].color = 0;
	return (matrix);
}

t_point	*multipy_matrix(t_point *matrix1, t_point matrix2)
{
	int		i;
	int		j;
	t_point	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(t_point));
	result->x = 0;
	result->y = 0;
	result->z = 0;
	result->color = 0;
	result->x = (matrix1[0].x * matrix2.x) + (matrix1[0].y * matrix2.y)
		+ (matrix1[0].z * matrix2.z);
	result->y = (matrix1[1].x * matrix2.x) + (matrix1[1].y * matrix2.y)
		+ (matrix1[1].z * matrix2.z);
	return (result);
}
t_point	*get_rotation_matrix_x(double angle)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = cos(angle);
	matrix[0].y = -sin(angle);
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = sin(angle);
	matrix[1].y = cos(angle);
	matrix[1].z = 0;
	matrix[1].color = 0;
	return (matrix);
}
t_point	*multiply_matrices(t_point *matrix1, int rows1, int columns1,
		t_point *matrix2, int rows2, int columns2)
{
	t_point	*result;
	t_point	sum;

	result = malloc(rows1 * columns2 * sizeof(t_point));
	sum.x = 0;
	sum.y = 0;
	sum.z = 0;
	sum.color = 0;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			for (int k = 0; k < columns1; k++)
			{
				sum.x += matrix1[i * columns1 + k].x * matrix2[k * columns2
					+ j].x;
				sum.y += matrix1[i * columns1 + k].y * matrix2[k * columns2
					+ j].y;
				sum.z += matrix1[i * columns1 + k].z * matrix2[k * columns2
					+ j].z;
			}
			result[i * columns2 + j] = sum;
		}
	}
	return (result);
}
