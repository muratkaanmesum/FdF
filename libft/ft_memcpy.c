/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:11:18 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/13 16:08:14 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	size_t		i;
	const char	*srcstr;

	if ((!dst && !src))
		return (0);
	srcstr = src;
	i = 0;
	str = dst;
	while (i < n)
	{
		str[i] = srcstr[i];
		i++;
	}
	return (str);
}
