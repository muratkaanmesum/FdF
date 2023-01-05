#include "fdf.h"

char	*get_lines(int fd)
{
	char	*line;
	char	*str;
	int		i;

	line = NULL;
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
int	get_width(char **strs)
{
	int		i;
	char	**line;

	i = 0;
	line = ft_split(strs[0], ' ');
	while (line[i])
		i++;
	free_split(line);
	return (i);
}
t_map	*get_map(char *file_name)
{
	int		fd;
	char	**map_arr;
	char	*str;
	t_map	*map;

	map = malloc(sizeof(t_map));
	file_name = "test_maps/elem-fract.fdf";
	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_printf("Error: file not found\n");
		return (NULL);
	}
	str = get_lines(fd);
	map_arr = ft_split(str, '\n');
	check_map(map_arr);
	map->points = get_points(map_arr);
	map->width = get_width(map_arr);
	map->height = get_map_length(map_arr);
	free_split(map_arr);
	free(str);
	return (map);
}
