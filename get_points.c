#include "fdf.h"
int	get_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_point	*get_point(char *str, int y, int map_height)
{
	t_point	*points;
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(str, ' ');
	points = malloc(sizeof(t_point) * (get_map_length(strs) + 1));
	while (strs[i])
	{
		points[i].x = (double)(i - get_map_length(strs) / 2);
		points[i].y = (double)(y - map_height / 2);
		points[i].z = (double)ft_atoi(strs[i]);
		if (ft_strchr(strs[i], ','))
			points[i].color = hex_to_decimal(ft_strchr(strs[i], ',') + 1);
		else if (points[i].z != 0)
			points[i].color = 1829593;
		else
			points[i].color = 0x00FFFFFF;
		i++;
	}
	free_split(strs);
	return (points);
}

t_point	**get_points(char **map)
{
	int		i;
	t_point	**points;

	points = malloc(sizeof(t_point *) * (get_map_length(map) + 1));
	i = 0;
	while (map[i])
	{
		points[i] = get_point(map[i], get_map_length(map)
				- get_map_length(&map[i]), get_map_length(map));
		i++;
	}
	return (points);
}
