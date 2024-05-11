/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:00:38 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 20:57:10 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void rotation_x(float *x, float *y, float *z)
{
	(void)x;
	float tmp;
	float degree = atan(1 / sqrt(2));
	// float degree = 0;
	tmp = *y;
	*y =  (cos(degree) * (*y)) - (sin(degree) * (*z));
	*z = (sin(degree) * tmp) + (cos(degree) * (*z));
}

void rotation_z(float *x, float *y, float *z)
{
	float tmp;
	float degree = (45 * (M_PI / 180));
	// float degree = 0;
	(void)z;
	tmp = *x;
	*x = (cos(degree) * *x) - (sin(degree) * *y);
	*y =  sin(degree) * tmp + cos(degree) * *y;                                                                                                                                                                                                                                                        
	// *z = (sin(degree) * tmp) + (cos(degree) * *z);	
}

// void rotation_y(int *x, int *y, int *z)
// {
	
// }


//rotate_z(strcut);
//rotate_x(strcut);