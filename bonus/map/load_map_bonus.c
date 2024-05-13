/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:53 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/13 21:31:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static uint32_t	_get_color(char *str)
{
	char		**spl;
	uint32_t	color;
	char		*tmp;

	if (!str)
		return (0xFFFFFFFF);
	spl = ft_split(str, ',');
	if (!spl || ft_split_size(spl) != 2)
		return (ft_free_strs(spl), 0xFFFFFFFF);
	if (!ft_strncmp(spl[1], "0x", 2))
		tmp = &spl[1][2];
	else
		tmp = spl[1];
	color = hexa2int(tmp);
	return (ft_free_strs(spl), color);
}

static void	set_vals(t_point *pnt, char *str)
{
	pnt->x0 = pnt->x;
	pnt->y0 = pnt->y;
	pnt->z0 = ft_atoi(str);
	pnt->z = pnt->z0;
	pnt->dx = 45;
	pnt->dy = 0;
	pnt->dz = 45;
	rotation_z(&pnt->x, &pnt->y, &pnt->z, 45);
	rotation_x(&pnt->x, &pnt->y, &pnt->z, 45);
	rotation_y(&pnt->x, &pnt->y, &pnt->z, 0);
	pnt->u = pnt->x;
	pnt->v = pnt->y;
	pnt->color = _get_color(str);
	pnt->ccolor = pnt->color;
}

static t_point	*_get_points(char *line, int cols, int y)
{
	char	**spl;
	t_point	*pnt;
	int		x;

	x = 0;
	spl = split_w(line);
	if (!spl || ft_split_size(spl) < cols)
		return (ft_exit(), NULL);
	pnt = malloc(sizeof(t_point) * cols);
	if (!pnt)
		return (ft_exit(), NULL);
	while (spl && spl[x] && x < cols)
	{
		pnt[x].x = x;
		pnt[x].y = y;
		set_vals(&pnt[x], spl[x]);
		x++;
	}
	return (ft_free_strs(spl), pnt);
}

t_point	**load_map(char *map, t_dimensions dm)
{
	t_point	**pnts;
	char	*ln;
	int		i;
	int		fd;

	pnts = malloc(sizeof(t_point *) * dm.rows + 1);
	if (!pnts)
		return (ft_exit(), NULL);
	pnts[dm.rows] = NULL;
	i = 0;
	fd = open(map, O_RDONLY);
	ln = get_next_line(fd);
	while (ln && i < dm.rows)
	{
		pnts[i] = _get_points(ln, dm.cols, i);
		i++;
		free(ln);
		ln = get_next_line(fd);
		if (!ln && (i < dm.rows - 1))
			return (close(fd), free(ln), ft_exit(), NULL);
	}
	free(ln);
	return (close(fd), get_next_line(fd), pnts);
}
