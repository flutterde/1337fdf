/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:53 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 17:58:03 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	while (spl[x] && x < cols)
	{
		pnt[x].x = x;
		pnt[x].y = y;
		pnt[x].z = ft_atoi(spl[x]);
		rotation_z(&pnt[x].x, &pnt[x].y, &pnt[x].z);
		rotation_x(&pnt[x].x, &pnt[x].y, &pnt[x].z);
		pnt[x].u = pnt[x].x;
		pnt[x].v = pnt[x].y;
		pnt[x].color = _get_color(spl[x]);
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
			return (ft_exit(), NULL);
	}
	free(ln);
	return (close(fd), get_next_line(fd), pnts);
}
