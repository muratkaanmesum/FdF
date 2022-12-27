/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:05:22 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/18 15:05:26 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	find_digit_count(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		return (1);
	}
	while (nbr > 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

int	handle_numbers(int num, char value)
{
	int	count;

	count = 0;
	if (value == 'd' || value == 'i')
	{
		ft_putnbr_fd(num, 1);
		if (num < 0)
		{
			num *= -1;
			count += 1;
		}
		if (num == -2147483648)
			count = 11;
		else
			count += find_digit_count(num);
	}
	else if (value == 'u')
	{
		ft_putnbr_base((unsigned int)num, "0123456789", &count);
	}
	else if (value == 'x')
		ft_putnbr_base((unsigned int)num, "0123456789abcdef", &count);
	else if (value == 'X')
		ft_putnbr_base((unsigned int)num, "0123456789ABCDEF", &count);
	return (count);
}
