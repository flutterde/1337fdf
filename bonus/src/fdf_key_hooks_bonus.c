/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:41:08 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/11 12:56:58 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	(void) keydata;
	if (mlx_is_key_down(data->win, MLX_KEY_ESCAPE))
		mlx_close_window(data->win);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		fdf_parallel(*data);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
	{
		ft_printf("ZOOM IN\n");
		fdf_zoomfn(*data, true);
	}
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
	{
		ft_printf("ZOOM OUT\n");
		fdf_zoomfn(*data, false);
	}
		ft_printf("ZOOM OUT\n");
	if (keydata.key == MLX_KEY_G && keydata.action == MLX_PRESS)
		ft_printf("Go crazy\n");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_printf("LEFT\n");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_printf("RIGHT\n");
}

t_data	set_data(mlx_t *win, mlx_image_t *img, t_point **points,
	t_dimensions dm, t_dimensions rdm)
{
	t_data	dt;

	dt.win = win;
	dt.img = img;
	dt.points = points;
	dt.dm = dm;
	dt.rdm = rdm;
	dt.is_p = false;
	return (dt);
}

void	fdf_key_hooks(t_data data)
{
	mlx_key_hook(data.win, key_handler, &data);
}
