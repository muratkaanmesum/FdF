/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:40:11 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/20 10:59:37 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static void	handle_p(unsigned long nbr, char *base, int *digitcount)
{
	unsigned int	count;
	int				a;

	count = ft_strlen(base);
	a = nbr;
	if (count <= 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
		*digitcount = *digitcount + 1;
	}
	if (nbr >= count)
	{
		handle_p(nbr / count, base, digitcount);
		handle_p(nbr % count, base, digitcount);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		*digitcount = *digitcount + 1;
	}
}

static int	handle_s(char *varstr)
{
	int	count;

	count = 0;
	if (!varstr)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		ft_putstr_fd(varstr, 1);
		count += ft_strlen((const char *)varstr);
	}
	return (count);
}

static int	handle_all(char value, va_list args)
{
	int	count;

	count = 0;
	if (value == 'd' || value == 'i' || value == 'x' || value == 'X'
		|| value == 'u')
		count += handle_numbers(va_arg(args, int), value);
	else if (value == '%')
	{
		ft_putchar_fd('%', 1);
		count += 1;
	}
	else if (value == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count += 1;
	}
	else if (value == 's')
		count += handle_s(va_arg(args, char *));
	else if (value == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		handle_p(va_arg(args, unsigned long), "0123456789abcdef", &count);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += handle_all(str[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
