/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:36:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/12 15:13:51 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	_leaks(void)
{
	system("leaks fdf");
}

static void	_destroy(void *mlx, void *img)
{
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

void	__loop(t_data *dt)
{
	ft_printf("the res is: %p.\n", dt->img);
}

static void	__draw(t_dimensions dm, t_dimensions md, t_point **pnts)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		data;

	mlx = mlx_init(FDF_WIDTH, FDF_HEIGHT, "FDF BONUS", false);
	if (!mlx)
		return ;
	img = mlx_new_image(mlx, FDF_WIDTH, FDF_HEIGHT);
	if (!img)
		return ;
	mlx_image_to_window(mlx, img, 0, 0);
	fdf_instructions(mlx);
	data = set_data(mlx, img, pnts, dm, md);
	fdf_key_hooks(data);
	fdf_render(&data);
	// mlx_loop_hook(mlx, &fdf_render, &data);
	// fdf_loop(__loop, &data);
	mlx_loop(mlx);
	_destroy(mlx, img);
}

void	__handler(char *map)
{
	t_dimensions	dm;
	t_point			**pnts;
	t_dimensions	md; // Map iso dimensions

	dm = map_dimensions(map);
	pnts = load_map(map, dm);
	md = iso_dimensions(pnts, dm);
	__draw(dm, md, pnts);
	ft_free_map(pnts);
}

int	main(int ac, char **av)
{
	atexit(_leaks);
	if (ac < 2 || ac > 2)
		return (ft_printf("Error\n"), 1);
	return (__handler(av[1]), 0);
}
