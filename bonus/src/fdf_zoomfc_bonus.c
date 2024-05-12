/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoomfc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:26:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/12 16:03:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	_zoom_in(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.points[i])
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u *= 1.2;
			data.points[i][j].v *= 1.2;
			j++;
		}
		i++;
	}	
}

void	_zoom_out(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.points[i])
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u *= .8;
			data.points[i][j].v *= .8;
			j++;
		}
		i++;
	}
	
}

void	fdf_zoomfn(t_data data, bool in)
{
	if (in)
		_zoom_in(data);
	else
		_zoom_out(data);
	
	data.rdm = iso_dimensions(data.points, data.dm);
	fdf_clear(data.img);
	fdf_link_points(data.points, data.dm, data.img);
	fdf_sidebare(data);
}
