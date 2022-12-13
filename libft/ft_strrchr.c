/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:59 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/10 16:29:43 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	value;

	value = c;
	i = 0;
	while (*(str + i))
		i++;
	while (i > -1)
	{
		if (str[i] == value)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
