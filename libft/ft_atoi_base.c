/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:38:23 by ochouati          #+#    #+#             */
/*   Updated: 2024/04/26 15:22:26 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_is_inbase(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

static int	_is_sign(char *str)
{
	while (str && *str)
	{
		if (*str == '+' || *str == '-' || *str == ' ')
			return (0);
		str++;
	}
	return (1);
}

static int	_validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || (ft_strlen(base) <= 1) || !_is_sign(base))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned int	ft_atoi_base(char *base, char *str)
{
	int				i;
	int				l;
	unsigned int	res;

	if (!base || !str || !_validate_base(base))
		return (0);
	i = 0;
	res = 0;
	l = ft_strlen(base);
	while (str[i] && _is_inbase(str[i], base))
	{
		res = (res * l) + (_is_inbase(str[i++], base) - 1);
	}
	return (res);
}
