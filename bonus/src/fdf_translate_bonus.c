/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:26:29 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/12 16:04:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static void	__letf(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.dm.rows)
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u -= 30;
			j++;
		}
		i++;
	}
}

static void	__right(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.dm.rows)
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].u += 30;
			j++;
		}
		i++;
	}
}

static void	__up(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.dm.rows)
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].v -= 30;
			j++;
		}
		i++;
	}
}

static void	__down(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.dm.rows)
	{
		j = 0;
		while (j < data.dm.cols)
		{
			data.points[i][j].v += 30;
			j++;
		}
		i++;
	}
}

void	fdf_translate(t_data data, char c)
{
	if (c == 'L')
		__letf(data);
	else if (c == 'R')
		__right(data);
	else if (c == 'U')
		__up(data);
	else if (c == 'D')
		__down(data);
	data.rdm = iso_dimensions(data.points, data.dm);
	fdf_clear(data.img);
	fdf_link_points(data.points, data.dm, data.img);
	fdf_sidebare(data);
}
