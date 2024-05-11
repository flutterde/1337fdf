/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:10:51 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 18:27:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_points(t_point **pnts, t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	while (pnts && pnts[i])
	{
		j = 0;
		while (j < dt->dm.cols)
		{
			fdf_put_pixel(pnts[i][j].u, pnts[i][j].v,
				pnts[i][j].color, dt->img);
			j++;
		}
		i++;
	}
}

static void	fdf_padding(t_point **pnts, t_dimensions dm, t_dimensions rdm)
{
	float	xpad;
	float	ypad;
	int		i;
	int		j;

	xpad = (FDF_WIDTH - rdm.cols) / 2;
	ypad = (FDF_HEIGHT - rdm.rows) / 2;
	i = 0;
	while (pnts && pnts[i])
	{
		j = 0;
		while (j < dm.cols)
		{
			pnts[i][j].u += xpad;
			pnts[i][j].v += ypad;
			j++;
		}
		i++;
	}
}

void	fdf_link_points(t_point **pnts, t_dimensions dm, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (pnts && pnts[i])
	{
		j = 0;
		while (j < dm.cols - 1)
		{
			fdf_dda(pnts[i][j], pnts[i][j + 1], img);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < dm.cols)
	{
		i = 0;
		while (pnts && pnts[i + 1])
		{
			fdf_dda(pnts[i][j], pnts[i + 1][j], img);
			i++;
		}
		j++;
	}
}

static void	__zoom(t_point **pnts, t_dimensions dm, t_dimensions rdm)
{
	int	i;
	int	j;

	(void) rdm;
	i = 0;
	while (pnts[i])
	{
		j = 0;
		while (j < dm.cols)
		{
			pnts[i][j].u = (pnts[i][j].u * rdm.scale_f)
				+ ((0 - rdm.dt.mn_x) * rdm.scale_f);
			pnts[i][j].v = (pnts[i][j].v * rdm.scale_f)
				+ ((0 - rdm.dt.mn_y) * rdm.scale_f);
			j++;
		}
		i++;
	}
	fdf_padding(pnts, dm, iso_dimensions(pnts, dm));
}

void	fdf_render(void *data)
{
	t_data	*dt;

	dt = data;
	__zoom(dt->points, dt->dm, dt->rdm);
	draw_points(dt->points, dt);
	fdf_link_points(dt->points, dt->dm, dt->img);
}
