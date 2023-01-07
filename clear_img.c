/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:36:46 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/07 15:44:13 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->mlx->window_height)
	{
		j = 0;
		while (j < all->mlx->window_width)
		{
			my_mlx_pixel_put(all->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
