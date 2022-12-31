#include "fdf.h"
#include "math.h"

t_point	*get_projection_matrix()
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = -20;
	matrix[0].y = 0;
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = -20;
	matrix[1].z = 0;
	matrix[1].color = 0;
	return (matrix);
}
t_point	*multipy_matrix_proj(t_point *matrix1, t_point matrix2)
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
t_point	*get_2d_rotation_matrix(double angle)
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = cos(angle);
	matrix[0].y = sin(angle);
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = -sin(angle);
	matrix[1].y = cos(angle);
	matrix[1].z = 0;
	matrix[1].color = 0;
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

t_point	*multply_rot(t_point *matrix1, t_point matrix2)
{
	t_point	*result;

	result = malloc(sizeof(t_point));
	result->x = 0;
	result->y = 0;
	result->z = 0;
	result->color = 0;
	result->x = (matrix1[0].x * matrix2.x) + (matrix1[0].y * matrix2.y)
		+ (matrix1[0].z * matrix2.z);
	result->y = (matrix1[1].x * matrix2.x) + (matrix1[1].y * matrix2.y)
		+ (matrix1[1].z * matrix2.z);
	result->z = (matrix1[2].x * matrix2.x) + (matrix1[2].y * matrix2.y)
		+ (matrix1[2].z * matrix2.z);
	return (result);
}
