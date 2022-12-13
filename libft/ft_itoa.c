/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:41:04 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/13 16:01:06 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void static	putnbr(int n, char *str, int *i)
{
	if (n > 9)
	{
		putnbr(n / 10, str, i);
		putnbr(n % 10, str, i);
	}
	if (n <= 9)
	{
		str[*i] = n + '0';
		*i = *i + 1;
	}
}

static int	checknegative(int *n)
{
	if (*n < 0)
	{
		*n = (*n) * -1;
		return (1);
	}
	return (0);
}

static int	getdigitcount(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*checkerror(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		while ("-2147483648"[i] != '\0')
		{
			str[i] = "-2147483648"[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		isnegative;
	int		i;
	char	*value;

	value = 0;
	i = 0;
	value = checkerror(n);
	if (value != NULL)
		return (value);
	isnegative = checknegative(&n);
	str = malloc((getdigitcount(n) + isnegative + 1) * sizeof(char));
	if (!str)
		return (0);
	if (isnegative == 1)
	{
		str[i] = '-';
		i++;
	}
	putnbr(n, str, &i);
	str[i] = '\0';
	return (str);
}
