/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:09:37 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/12 20:21:53 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

	// rotation_z(&pnt->x, &pnt->y, &pnt->z, 45);
	// rotation_x(&pnt->x, &pnt->y, &pnt->z, 45);
	// rotation_y(&pnt->x, &pnt->y, &pnt->z, 0);
	// pnt->u = pnt->x;
	// pnt->v = pnt->y;
	
void	fdf_rotate(t_data data, char axis)
{
	int i = 0;
	int	j;
	// rotate the points around the axis
	(void)data;
	(void)axis;
	ft_printf("=======>> axis: %c\n", axis);
	if (axis == 'I')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
			{
				data.points[i][j].dz += 5;
				ft_printf("===========>dz + 5: %d\n", data.points[i][j].dz);
				rotation_z(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, data.points[i][j].dz);
				// rotation_x(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, 45);
				// rotation_y(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, 0);
				data.points[i][j].u = data.points[i][j].x;
				data.points[i][j].v = data.points[i][j].y;
				j++;
			}
			i++;
		}
	}
	else if (axis == 'U')
	{
		while (data.points[i])
		{
			j = 0;
			while (j < data.dm.cols)
			{
				data.points[i][j].dz -= 5;
				ft_printf("===========>dx-: %d\n", data.points[i][j].dz);
				rotation_z(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, data.points[i][j].dz);
				// rotation_x(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, 45);
				// rotation_y(&data.points[i][j].x, &data.points[i][j].y, &data.points[i][j].z, 0);
				data.points[i][j].u = data.points[i][j].x;
				data.points[i][j].v = data.points[i][j].y;
				j++;
			}
			i++;
		}
	}
	data.rdm = iso_dimensions(data.points, data.dm);
	fdf_clear(data.img);
	fdf_render(&data);
	// fdf_link_points(data.points, data.dm, data.img);
	// fdf_sidebare(data);
	ft_printf("======-> Out of the function\n");
}
