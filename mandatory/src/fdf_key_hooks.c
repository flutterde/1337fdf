/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:41:08 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 18:25:00 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	(void) keydata;
	if (mlx_is_key_down(data->win, MLX_KEY_ESCAPE))
		mlx_close_window(data->win);
}

t_data	set_data(t_data dat, t_point **points,
	t_dimensions dm, t_dimensions rdm)
{
	t_data	dt;

	dt.win = dat.win;
	dt.img = dat.img;
	dt.points = points;
	dt.dm = dm;
	dt.rdm = rdm;
	return (dt);
}

void	fdf_key_hooks(t_data data)
{
	mlx_key_hook(data.win, key_handler, &data);
}
