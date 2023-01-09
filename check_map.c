/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:35 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 13:08:10 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(void)
{
	ft_printf("ERROR !\n");
	exit(0);
}

int	check_num(char *str)
{
	int	i;

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
	int		i;
	char	**all_nums;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		all_nums = ft_split(map[i], ' ');
		while (all_nums[j] != NULL)
		{
			if (check_num(all_nums[j]) == 0)
				return (0);
			j++;
		}
		free_split(all_nums);
		i++;
	}
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
		while (tmp[j++] != NULL)
			count++;
		free_split(tmp);
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
