/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:09:05 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/13 16:03:14 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		value;
	const char	*s1;

	value = c;
	s1 = s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == value)
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
