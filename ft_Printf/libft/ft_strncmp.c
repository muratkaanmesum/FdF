/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:12:38 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/13 14:33:00 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	s1v;
	unsigned char	s2v;

	i = 0;
	while (i < n && ((s1[i] != '\0' || s2[i] != '\0')))
	{
		s1v = (unsigned char)s1[i];
		s2v = (unsigned char)s2[i];
		if (s1v != s2v)
			return (s1v - s2v);
		i++;
	}
	return (0);
}
