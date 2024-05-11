/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:44:06 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/05 17:07:24 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

uint32_t	gradient_color(uint32_t col1, uint32_t col2, int step, int steps)
{
	t_color	color;

	if (col1 == col2)
		return (col1);
	if (!steps)
		return (col1);
	color.r1 = col1 >> 24;
	color.g1 = col1 >> 16;
	color.b1 = col1 >> 8;
	color.r2 = col2 >> 24;
	color.g2 = col2 >> 16;
	color.b2 = col2 >> 8;
	if (color.r1 < color.r2)
		color.r1 += step * (color.r2 - color.r1) / steps;
	else
		color.r1 -= step * (color.r1 - color.r2) / steps;
	if (color.g1 < color.g2)
		color.g1 += step * (color.g2 - color.g1) / steps;
	else
		color.g1 -= step * (color.g1 - color.g2) / steps;
	if (color.b1 < color.b2)
		color.b1 += step * (color.b2 - color.b1) / steps;
	else
		color.b1 -= step * (color.b1 - color.b2) / steps;
	return (color.r1 << 24 | color.g1 << 16 | color.b1 << 8 | 0xFF);
}
