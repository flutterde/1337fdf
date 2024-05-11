/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:42:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 20:57:05 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static bool	validate_extension(char *map)
{
	char	*tmp;

	if (!map)
		return (ft_exit(), false);
	tmp = ft_strrchr(map, '.');
	if (ft_strlen(tmp) != 4 || ft_strncmp(".fdf", tmp, 4))
		return (ft_exit(), false);
	return (true);
}

static t_dimensions	_map_dimensions(char *map)
{
	char			*ln;
	char			**tmp;
	int				fd;
	t_dimensions	dm;

	ft_bzero(&dm, sizeof(t_dimensions));
	fd = open(map, O_RDONLY);
	ln = get_next_line(fd);
	if (!ln)
		return (close(fd), ft_exit(), dm);
	tmp = split_w(ln);
	dm.cols = ft_split_size(tmp);
	if (!dm.cols)
		return (dm);
	while (ln)
	{
		dm.rows++;
		free(ln);
		ln = get_next_line(fd);
	}
	ft_free_strs(tmp);
	return (free(ln), close(fd), get_next_line(fd), dm);
}

t_dimensions	map_dimensions(char *map)
{
	return (validate_extension(map), _map_dimensions(map));
}
