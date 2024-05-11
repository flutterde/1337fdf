/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:25:00 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 18:24:34 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	set_point(int u, int v, uint32_t color)
{
	t_point	p;

	p.u = u;
	p.v = v;
	p.color = color;
	return (p);
}

void	fdf_dda(t_point p1, t_point p2, mlx_image_t *img)
{
	t_ddavars	vars;
	uint32_t	color;

	vars.dx = p2.u - p1.u;
	vars.dy = p2.v - p1.v;
	if (fabsf(vars.dx) > fabsf(vars.dy))
		vars.steps = fabsf(vars.dx);
	else
		vars.steps = fabsf(vars.dy);
	vars.x_inc = vars.dx / (float)vars.steps;
	vars.y_inc = vars.dy / (float)vars.steps;
	vars.x = p1.u;
	vars.y = p1.v;
	vars.i = 0;
	while (vars.i <= vars.steps)
	{
		color = gradient_color(p1.color, p2.color, vars.i, vars.steps);
		fdf_put_pixel(vars.x, vars.y, color, img);
		vars.x += vars.x_inc;
		vars.y += vars.y_inc;
		vars.i++;
	}
}
