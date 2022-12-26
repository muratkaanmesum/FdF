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

char	**get_map(char *file_name)
{
	int		fd;
	char	**map;
	char	*str;

	file_name = "test_maps/42.fdf";
	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("Error: file not found\n");
		return (NULL);
	}
	str = get_lines(fd);
	map = ft_split(str, '\n');
	return (map);
}
