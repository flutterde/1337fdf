/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sidebare_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:09:46 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/11 13:22:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	fdf_bgs(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 25)
	{
		j = 0;
		while (j < 200)
		{
			fdf_put_pixel((FDF_WIDTH * .015) + j, 9 + i, 0x00FF00FF, data.img);
			j++;
		}
		i++;
	}
}

void	fdf_instructions(mlx_t *win)
{
	mlx_put_string(win, "Guides of use:", FDF_WIDTH * .02, 10);
	mlx_put_string(win, "P: Parallel projection", FDF_WIDTH * .02, 40);
	mlx_put_string(win, "Z: Zoom in", FDF_WIDTH * .02, 70);
	mlx_put_string(win, "X: Zoom out", FDF_WIDTH * .02, 100);
	mlx_put_string(win, "G: Go Crazy", FDF_WIDTH * .02, 130);
	mlx_put_string(win, "R: Reset", FDF_WIDTH * .02, 130);
	mlx_put_string(win, "LEFT: Move left", FDF_WIDTH * .02, 160);
	mlx_put_string(win, "RIGHT: Move right", FDF_WIDTH * .02, 190);
}

void	fdf_sidebare(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (i < FDF_HEIGHT)
	{
		j = 0;
		while (j < FDF_WIDTH * .17)
		{
			fdf_put_pixel(j, i, 0x000000FF, data.img);
			j++;
		}
		i++;
	}
	fdf_bgs(data);
}
