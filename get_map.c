#include "fdf.h"

char	*get_lines(int fd)
{
	char	*line;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (line != NULL || i == 0)
	{
		line = get_next_line(fd);
		if (line != NULL)
			str = ft_gnl_strjoin(str, line);
		free(line);
		i++;
	}
	return (str);
}

t_map	*get_map(char *file_name)
{
	int		fd;
	char	**map_arr;
	char	*str;
	t_map	*map;

	map = malloc(sizeof(t_map));
	file_name = "test_maps/42.fdf";
	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("Error: file not found\n");
		return (NULL);
	}
	str = get_lines(fd);
	map_arr = ft_split(str, '\n');
	check_map(map_arr);
	map->points = get_points(map_arr);
	map->width = get_map_length(&map_arr[0]);
	map->height = get_map_length(map_arr);
	return (map);
}
