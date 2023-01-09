/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:04:31 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/09 13:04:51 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_decimal(const char *hex)
{
	int	decimal;
	int	i;
	int	len;
	int	val;

	decimal = 0;
	i = 0;
	len = ft_strlen(hex);
	while (i < len)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 'A' + 10;
		decimal = decimal * 16 + val;
		i++;
	}
	return (decimal);
}
