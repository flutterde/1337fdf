/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dda_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:25:00 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/10 19:24:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

t_point set_point(int u, int v, uint32_t color)
{
    t_point p;

    p.u = u;
    p.v = v;
    p.color = color;
    return (p);
}

void fdf_dda(t_point p1, t_point p2, mlx_image_t *img)
{
    float dx = p2.u - p1.u;
    float dy = p2.v - p1.v;
    int steps = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = p1.u;
    float y = p1.v;
    int i = 0;

    uint32_t color;
    while (i <= steps)
    {
        color = gradient_color(p1.color, p2.color, i, steps);
        fdf_put_pixel(x, y, color, img);
        x += x_inc;
        y += y_inc;
        i++;
    }
}
