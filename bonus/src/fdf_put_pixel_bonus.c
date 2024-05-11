/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:46:43 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 20:57:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	fdf_put_pixel(int x, int y, uint32_t color, mlx_image_t *img)
{
	if ((x >= 0 && y >= 0) && (x < FDF_WIDTH && y < FDF_HEIGHT))
		mlx_put_pixel(img, x, y, color);
}
