/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_dimensions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:42:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/11 19:26:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static t_dmdt	calcul_dimensions(t_point **pnt, t_dimensions dm)
{
	t_dmdt	ndm;
	int		i;
	int		j;

	i = 0;
	ndm.mn_x = pnt[i][0].u;
	ndm.mn_y = pnt[i][0].v;
	while (pnt && pnt[i])
	{
		j = 0;
		while (j < dm.cols)
		{
			if (pnt[i][j].u < ndm.mn_x)
				ndm.mn_x = pnt[i][j].u;
			if (pnt[i][j].u > ndm.mx_x)
				ndm.mx_x = pnt[i][j].u;
			if (pnt[i][j].v < ndm.mn_y)
				ndm.mn_y = pnt[i][j].v;
			if (pnt[i][j].v > ndm.mx_y)
				ndm.mx_y = pnt[i][j].v;
			j++;
		}
		i++;
	}
	return (ndm);
}

static float	scale_f(t_dimensions data)
{
	float scale_f;
	
	scale_f = 0;
	if (data.cols == 0 || data.rows == 0)
		return (scale_f);
	if (1000 / data.cols < 1000 / data.rows)
		scale_f = 1000 / data.cols;
	else
		scale_f =  1000 / data.rows;
	return (scale_f);
}

t_dimensions	iso_dimensions(t_point **pnts, t_dimensions dm)
{
	t_dimensions	ndm;
	t_dmdt			dt;

	dt = calcul_dimensions(pnts, dm);
	ndm.cols = dt.mx_x - dt.mn_x;
	ndm.rows = dt.mx_y - dt.mn_y;
	ndm.dt = dt;

	printf("bounding hegiht -> %d\n", ndm.rows);
	printf("bounding width -> %d\n", ndm.cols);
	ndm.scale_f = scale_f(ndm);
	if (ndm.scale_f <= 0)
		ndm.scale_f = 1;
	printf("scale factor -> %f\n", ndm.scale_f);
	return (ndm);
}
