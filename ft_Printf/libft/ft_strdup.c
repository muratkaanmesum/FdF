/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:45:43 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/13 15:50:08 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		a;
	int		i;
	char	*cpy;

	a = 0;
	i = 0;
	while (*(s1 + a))
		a++;
	cpy = malloc(a + 1 * sizeof(char));
	if (!cpy)
		return (0);
	while (i < a)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
