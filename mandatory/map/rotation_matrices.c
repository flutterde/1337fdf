/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:00:38 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 19:39:40 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotation_x(float *x, float *y, float *z)
{
	float	tmp;
	float	degree;

	(void)x;
	degree = atan(1 / sqrt(2));
	tmp = *y;
	*y = (cos(degree) * (*y)) - (sin(degree) * (*z));
	*z = (sin(degree) * tmp) + (cos(degree) * (*z));
}

void	rotation_z(float *x, float *y, float *z)
{
	float	tmp;
	float	degree;

	(void)z;
	degree = (45 * (M_PI / 180));
	tmp = *x;
	*x = (cos(degree) * (*x)) - (sin(degree) * (*y));
	*y = sin(degree) * tmp + cos(degree) * (*y);
}
