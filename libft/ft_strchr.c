/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:41:29 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/10 16:28:19 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	value;
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	if (!str)
		return (0);
	value = c;
	i = 0;
	while (i <= len)
	{
		if (str[i] == value)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
