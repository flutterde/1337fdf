/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:09:37 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 21:29:09 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static void	set_vals_xyz(t_point *pnt, int ang, char c)
{
	pnt->x = pnt->x0;
	pnt->y = pnt->y0;
	pnt->z = pnt->z0;
	if (c == 'z')
		pnt->dz += ang;
	else if (c == 'x')
		pnt->dx += ang;
	else if (c == 'y')
		pnt->dy += ang;
	pnt->dz += ang;
	rotation_z(&pnt->x, &pnt->y, &pnt->z, pnt->dz);
	rotation_x(&pnt->x, &pnt->y, &pnt->z, pnt->dx);
	rotation_y(&pnt->x, &pnt->y, &pnt->z, pnt->dy);
	pnt->u = pnt->x;
	pnt->v = pnt->y;
}

static void	___rz(t_data data, char axis)
{
	int	i;
	int	j;

	i = 0;
	if (axis == 'I')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], 5, 'z');
			i++;
		}
	}
	else if (axis == 'U')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], -5, 'z');
			i++;
		}
	}
}

static void	___rx(t_data data, char axis)
{
	int	i;
	int	j;

	i = 0;
	if (axis == 'V')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], 5, 'x');
			i++;
		}
	}
	else if (axis == 'B')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], -5, 'x');
			i++;
		}
	}
}

static void	___ry(t_data data, char axis)
{
	int	i;
	int	j;

	i = 0;
	if (axis == 'N')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], 5, 'y');
			i++;
		}
	}
	else if (axis == 'M')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
				set_vals_xyz(&data.points[i][j++], -5, 'y');
			i++;
		}
	}
}

void	fdf_rotate(t_data data, char axis)
{
	if (axis == 'I' || axis == 'U')
	{
		___rz(data, axis);
	}
	else if (axis == 'V' || axis == 'B')
		___rx(data, axis);
	else if (axis == 'N' || axis == 'M')
		___ry(data, axis);
	data.rdm = iso_dimensions(data.points, data.dm);
	fdf_clear(data.img);
	fdf_render(&data);
}
