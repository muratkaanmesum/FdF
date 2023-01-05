/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:36:46 by mmesum            #+#    #+#             */
/*   Updated: 2023/01/05 16:37:14 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->line_length)
	{
		j = 0;
		while (j < img->bpp)
		{
			my_mlx_pixel_put(img, i, j, 0);
			j++;
		}
		i++;
	}
}
