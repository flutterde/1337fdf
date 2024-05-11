/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parallel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:23 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/09 15:09:19 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

/* PREPER POINTS */
void	_reset_points(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.points[i])
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u = data.points[i][j].x0;
			data.points[i][j].v = data.points[i][j].y0;
			j++;
		}
		i++;
	}
	data.rdm = iso_dimensions(data.points, data.dm);
}

/* SCALE THE MAP */
static void	scale_parallel(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.points[i])
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u *= data.rdm.scale_f;
			data.points[i][j].v *= data.rdm.scale_f;			
			j++;
		}
		i++;
	}
}

void	fdf_parallel(t_data data)
{
	fdf_clear(data.img);
	_reset_points(data);
	scale_parallel(data);
	fdf_padding(data.points, data.dm, data.rdm);
	draw_points(data.points, &data);
	fdf_link_points(data.points, data.dm, data.img);
	fdf_sidebare(data);
}
