/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa2int_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:51:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 20:58:06 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

static int	_inbase(char c)
{
	int	i;

	i = 0;
	while (BASE1[i] && BASE2[i])
	{
		if (c == BASE1[i] || c == BASE2[i])
			return (i + 1);
		i++;
	}
	return (0);
}

uint32_t	hexa2int(char *str)
{
	uint32_t	res;
	int			i;

	i = 0;
	if (!str)
		return (i);
	res = 0;
	while (str[i] && _inbase(str[i]))
	{
		res = (res * 16) + _inbase(str[i]) - 1;
		i++;
	}
	if (ft_strlen(str) == 8)
		return (res);
	return ((res << 8) | 0x000000FF);
}
