/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sidebare_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:09:46 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 21:38:15 by ochouati         ###   ########.fr       */
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
			fdf_put_pixel((FDF_WIDTH * .015) + j, 59 + i,
				0x00FF00FF, data.img);
			j++;
		}
		i++;
	}
}

void	fdf_instructions(mlx_t *win)
{
	mlx_put_string(win, "Guides of use:", FDF_WIDTH * .02, 60);
	mlx_put_string(win, "P: Parallel projection", FDF_WIDTH * .02, 120);
	mlx_put_string(win, "Z: Zoom in", FDF_WIDTH * .02, 150);
	mlx_put_string(win, "X: Zoom out", FDF_WIDTH * .02, 180);
	mlx_put_string(win, "G: Go Crazy", FDF_WIDTH * .02, 210);
	mlx_put_string(win, "R: Reset", FDF_WIDTH * .02, 240);
	mlx_put_string(win, "Rotate: U|I..", FDF_WIDTH * .02, 270);
	mlx_put_string(win, "<: Move left", FDF_WIDTH * .02, 300);
	mlx_put_string(win, ">: Move right", FDF_WIDTH * .02, 330);
	mlx_put_string(win, "^: Move up", FDF_WIDTH * .02, 360);
	mlx_put_string(win, "v: Move down", FDF_WIDTH * .02, 390);
	mlx_put_string(win, "ochouati@1337", FDF_WIDTH * .02, 1040);
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
