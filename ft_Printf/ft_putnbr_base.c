/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:27:26 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/20 00:02:35 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *digitcount)
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
		ft_putnbr_base(nbr / count, base, digitcount);
		ft_putnbr_base(nbr % count, base, digitcount);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		*digitcount = *digitcount + 1;
	}
}
