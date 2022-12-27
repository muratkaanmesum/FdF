/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:25:05 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/18 15:23:30 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	findlen(const char *str)
{
	int	scount;

	scount = 0;
	while (*(str + scount))
		scount++;
	return (scount);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		scount;
	char	*str;
	int		i;
	int		index;

	scount = 0;
	i = 0;
	index = 0;
	scount = findlen(s1) + findlen(s2);
	str = malloc((scount) * sizeof(char));
	if (!str)
		return (0);
	while (s1[index] != '\0')
	{
		str[i] = s1[index++];
		i++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		str[i] = s2[index++];
		i++;
	}
	str[i] = '\0';
	return (str);
}
