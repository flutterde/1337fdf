/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:41:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 14:42:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./../MLX42/include/MLX42/MLX42.h"
# include "data_types.h"

void			ft_free_map(t_point **map);
void			ft_exit(void);
char			**split_w(char const *s);
t_point			**load_map(char *map, t_dimensions dm);
t_dimensions	map_dimensions(char *map);
t_dimensions	iso_dimensions(t_point **pnts, t_dimensions dm);
t_data			set_data(t_data dt, t_point **points, t_dimensions dm,
					t_dimensions rdm);
void			fdf_render(void *data);
void			fdf_key_hooks(t_data data);
void			fdf_put_pixel(int x, int y, uint32_t color, mlx_image_t *img);
t_point			set_point(int u, int v, uint32_t color);
void			fdf_dda(t_point p1, t_point p2, mlx_image_t *img);
uint32_t		hexa2int(char *str);
uint32_t		gradient_color(uint32_t col1, uint32_t col2, int step,
					int steps);
void			rotation_x(float *x, float *y, float *z);
void			rotation_z(float *x, float *y, float *z);

#endif