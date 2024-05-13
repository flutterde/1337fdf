/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:41:08 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 21:33:51 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static void	__key_helper(t_data *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fdf_translate(*data, 'R');
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'I');
	else if (keydata.key == MLX_KEY_U && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'U');
	else if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'V');
	else if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'B');
	else if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'N');
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		fdf_rotate(*data, 'M');
}

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	(void) keydata;
	if (mlx_is_key_down(data->win, MLX_KEY_ESCAPE))
		mlx_close_window(data->win);
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		fdf_parallel(*data);
	else if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		fdf_zoomfn(*data, true);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		fdf_reset_map(*data);
	else if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		fdf_zoomfn(*data, false);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fdf_translate(*data, 'U');
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fdf_translate(*data, 'D');
	else if (keydata.key == MLX_KEY_G && keydata.action == MLX_PRESS)
		fdf_go_crazy(*data);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fdf_translate(*data, 'L');
	else
		__key_helper(data, keydata);
}

t_data	set_data(t_data dta, t_point **points,
	t_dimensions dm, t_dimensions rdm)
{
	t_data	dt;

	dt.win = dta.win;
	dt.img = dta.img;
	dt.points = points;
	dt.dm = dm;
	dt.rdm = rdm;
	return (dt);
}

void	fdf_key_hooks(t_data data)
{
	mlx_key_hook(data.win, key_handler, &data);
}
