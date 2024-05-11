/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:04:25 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 21:06:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	fdf_clear(mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < FDF_HEIGHT)
	{
		j = 0;
		while (j < FDF_WIDTH)
		{
			fdf_put_pixel(j, i, 0x00000000, img);
			j++;
		}
		i++;
	}
}
