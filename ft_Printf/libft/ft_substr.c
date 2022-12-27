/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:20:55 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/11 12:06:40 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	count;
	size_t	startindex;

	count = 0;
	startindex = start;
	while (s[startindex] != '\0' && count < len && ft_strlen(s) > startindex)
	{
		count++;
		startindex++;
	}
	substr = malloc((count + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0' && ft_strlen(s) > start)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
