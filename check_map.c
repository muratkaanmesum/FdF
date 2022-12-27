#include "fdf.h"

void	error(void)
{
	ft_printf("ERROR !\n");
	exit(0);
}
int	check_num(char *str)
{
	int	i;
//test
	i = 0;
	while (str[i] != '\0' && str[i] != ',')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_all_nums(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
		check_num(map[i++]);
	return (1);
}
int	check_row_length(char **map)
{
	int		i;
	char	**tmp;
	int		count;
	int		count2;
	int		j;

	i = 0;
	count2 = -1;
	while (map[i] != NULL)
	{
		count = 0;
		j = 0;
		tmp = ft_split(map[i], ' ');
		while (tmp[j] != NULL)
		{
			free(tmp[count]);
			count++;
			j++;
		}
		free(tmp);
		if (count2 == -1)
			count2 = count;
		else if (count2 != count)
			return (0);
		i++;
	}
	return (1);
}
int	check_map(char **map)
{
	if (check_all_nums(map) == 0 || check_row_length(map) == 0)
		error();
	return (1);
}
