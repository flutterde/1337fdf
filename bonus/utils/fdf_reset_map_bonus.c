/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 18:44:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static void	set_vals(t_point *pnt)
{
	pnt->x = pnt->x0;
	pnt->y = pnt->y0;
	pnt->z = pnt->z0;
	pnt->dx = 45;
	pnt->dy = 0;
	pnt->dz = 45;
	rotation_z(&pnt->x, &pnt->y, &pnt->z, 45);
	rotation_x(&pnt->x, &pnt->y, &pnt->z, 45);
	rotation_y(&pnt->x, &pnt->y, &pnt->z, 0);
	pnt->u = pnt->x;
	pnt->v = pnt->y;
	pnt->color = pnt->ccolor;
}

void	fdf_reset_map(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.points[i])
	{
		j = 0;
		while (j < data.dm.cols)
		{
			set_vals(&data.points[i][j]);
			j++;
		}
		i++;
	}
	fdf_clear(data.img);
	fdf_render(&data);
}
