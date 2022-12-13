/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:50:26 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/19 18:50:37 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	findstart(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	doesinclude;

	i = 0;
	j = 0;
	doesinclude = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				doesinclude = 1;
			j++;
		}
		if (doesinclude == 0)
			break ;
		j = 0;
		i++;
		doesinclude = 0;
	}
	return (i);
}

static int	findend(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	doesinclude;

	i = ft_strlen(s1) - 1;
	j = 0;
	doesinclude = 0;
	while (i >= 0)
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				doesinclude = 1;
			j++;
		}
		if (doesinclude == 0)
			break ;
		j = 0;
		i--;
		doesinclude = 0;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		index;
	char	*str;

	start = findstart(s1, set);
	end = findend(s1, set);
	i = 0;
	index = 0;
	while (start + i <= end)
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (index < i)
	{
		str[index] = s1[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}
