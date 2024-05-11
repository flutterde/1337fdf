/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:04:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/03 18:08:22 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_map(t_point **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i++]);
	}
	free(map);
}