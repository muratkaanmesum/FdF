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

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->map->height)
	{
		free(all->map->points[i]);
		i++;
	}
	free(all->map->points);
	free(all->map);
	free(all->mlx);
	free(all);
}

double	get_scale(t_all *all)
{
	int	scale;

	scale = all->mlx->window_width / all->map->width;
	return (scale);
}

void	free_points(t_point **points, t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}
