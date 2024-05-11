/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:37:17 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/10 21:43:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_BONUS_H
# define DATA_TYPES_BONUS_H

# include "fdf_bonus.h"
# define FDF_HEIGHT 1080
# define FDF_WIDTH 1920
# define BASE1 "0123456789ABCDEF"
# define BASE2 "0123456789abcdef"


typedef struct s_dmdt
{
	float	mn_x;
	float	mx_x;
	float	mn_y;
	float	mx_y;
}	t_dmdt;

typedef struct s_dimensions
{
	int	cols;
	int	rows;
	float scale_f;
	t_dmdt	dt;
}	t_dimensions;

typedef struct s_point
{
	float		x0;
	float		y0;
	float		z0;
	float		x;
	float		y;
	float		z;
	float		u;
	float		v;
	uint32_t	color;
}	t_point;



typedef struct s_data
{
	mlx_t 			*win;
	mlx_image_t		*img;
	t_point 		**points;
	t_dimensions 	dm;
	t_dimensions 	rdm;
	bool			is_p;
}	t_data;

typedef struct s_color
{
	uint8_t		r1;
	uint8_t		r2;
	uint8_t		g1;
	uint8_t		g2;
	uint8_t		b1;
	uint8_t		b2;
	uint8_t		a;
	uint32_t	color;
}	t_color;

#endif