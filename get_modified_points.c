#include "fdf.h"

t_point	*multiply_scale()
{
	t_point	*matrix;

	matrix = malloc(sizeof(t_point) * 2);
	matrix[0].x = 2;
	matrix[0].y = 0;
	matrix[0].z = 0;
	matrix[0].color = 0;
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[1].color = 0;
	return (matrix);
}
t_point	matrix_application(t_point point, double angle_x, double angle_y)
{
	t_point	*projection_matrix;
	t_point	*rotation_matrix_x;
	t_point	*result;
	t_point	*rotation_matrix_y;
	int		distance;
	int		z;

	projection_matrix = get_projection_matrix();
	rotation_matrix_x = get_rotation_matrix_x(angle_x);
	rotation_matrix_y = get_rotation_matrix_y(angle_y);
	result = malloc(sizeof(t_point));
	result = multply_rot(rotation_matrix_x, point);
	result = multply_rot(rotation_matrix_y, *result);
	result = multipy_matrix_proj(projection_matrix, *result);
	return (*result);
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
			points[i][j].x = WINDOW_WIDTH / 2 - points[i][j].x;
			points[i][j].y = WINDOW_HEIGHT / 2 - points[i][j].y;
			points[i][j].color = map->points[i][j].color;
			j++;
		}
		i++;
	}
	return (points);
}
