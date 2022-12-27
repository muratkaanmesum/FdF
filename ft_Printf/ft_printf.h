/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:02:05 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/20 00:02:22 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		handle_numbers(int num, char value);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base(unsigned int nbr, char *base, int *digitcount);
void	handle_flags(const char *str);
void	handle_chars(char *arg, char value);
#endif
