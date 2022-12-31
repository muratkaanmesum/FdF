#include "fdf.h"
int	get_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_point	*get_point(char *str, int x, int y)
{
	t_point	*points;
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(str, ' ');
	points = malloc(sizeof(t_point) * (get_map_length(strs) + 1));
	while (strs[i])
	{
		points[i].x = (double)i;
		points[i].y = (double)y;
		points[i].z = (double)ft_atoi(strs[i]);
		if (points[i].z > 0)
			points[i].color = 1829593;
		else
			points[i].color = 0x00FFFFFF;
		i++;
	}
	return (points);
}

t_point	**get_points(char **map)
{
	int		i;
	int		j;
	char	**str;
	t_point	**points;

	points = malloc(sizeof(t_point *) * (get_map_length(map) + 1));
	i = 0;
	while (map[i])
	{
		points[i] = get_point(map[i], i, get_map_length(map)
				- get_map_length(&map[i]));
		i++;
	}
	return (points);
}
