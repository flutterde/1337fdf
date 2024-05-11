/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:45:33 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 20:58:10 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	print_points(t_point **pnts, t_dimensions dm)
{
	int	i;
	int	j;

	i = 0;
	while (pnts && pnts[i])
	{
		j = 0;
		while (j < dm.cols)
		{
			ft_printf("the x is: %d.\n", pnts[i][j].x);
			ft_printf("the y is: %d.\n", pnts[i][j].y);
			ft_printf("the z is: %d.\n", pnts[i][j].z);
			ft_printf("the color is: %u.\n", pnts[i][j].color);
			printf("The U: %f      :: The V: %f     \n", pnts[i][j].u, pnts[i][j].v);
			j++;
		}
		i++;
	}
}
