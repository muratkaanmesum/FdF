#include "fdf.h"
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	does_include(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_map *map, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
	free(mlx);
}
