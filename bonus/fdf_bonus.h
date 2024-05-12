/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:41:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/12 18:01:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "./../MLX42/include/MLX42/MLX42.h"
#include "data_types_bonus.h"

void			ft_free_map(t_point **map);
void			ft_exit();
char			**split_w(char const *s);
void			print_points(t_point **pnts, t_dimensions dm);
t_point			**load_map(char *map, t_dimensions dm);
t_dimensions	map_dimensions(char *map);
t_dimensions	iso_dimensions(t_point **pnts, t_dimensions dm);
void			fdf_key_hooks(t_data data);
t_data			set_data(mlx_t *win, mlx_image_t *img, t_point **points,
	t_dimensions dm, t_dimensions rdm);
void			fdf_render(void *data);
void			fdf_put_pixel(int x, int y, uint32_t color, mlx_image_t *img);
t_point 		set_point(int u, int v, uint32_t color);
void 			fdf_dda(t_point p1, t_point p2, mlx_image_t *img);
uint32_t		hexa2int(char *str);
uint32_t    	gradient_color(uint32_t col1, uint32_t col2, int step,
					int steps);
void 			rotation_x(float *x, float *y, float *z, int deg);
void 			rotation_z(float *x, float *y, float *z, int deg);
void			rotation_y(float *x, float *y, float *z, int deg);
void			fdf_clear(mlx_image_t *img);
void			fdf_sidebare(t_data data);
void			fdf_parallel(t_data data);
void			draw_points(t_point **pnts, t_data *dt);
void			fdf_link_points(t_point **pnts, t_dimensions dm, mlx_image_t *img);
void			fdf_padding(t_point **pnts, t_dimensions dm, t_dimensions rdm);
void			fdf_zoomfn(t_data data, bool in);
void			fdf_instructions(mlx_t *win);
void			fdf_translate(t_data data, char c);
void			random_color(t_data data);
void			fdf_go_crazy(t_data data);
void			fdf_rotate(t_data data, char axis);

#endif