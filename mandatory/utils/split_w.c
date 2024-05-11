/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:26:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/05/08 18:04:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	c_words(char *str)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
			cw++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (cw);
}

static int	w_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	return (i);
}

static char	*full_ptr(char	*str, char *ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**free_thestr(char **str, int index)
{
	int	i;

	i = 0;
	str[index] = NULL;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**split_w(char const *s)
{
	int		cw;
	int		i;
	int		j;
	char	**nstr;

	if (!s)
		return (NULL);
	cw = c_words((char *)s);
	nstr = malloc(sizeof(char *) * (cw + 1));
	if (!nstr)
		return (0);
	nstr[cw] = NULL;
	i = 0;
	j = -1;
	while (++j < cw)
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		nstr[j] = malloc(sizeof(char) * w_len((char *)&s[i]) + 1);
		if (!nstr[j])
			return (free_thestr(nstr, j));
		full_ptr((char *)&s[i], nstr[j], w_len((char *)&s[i]));
		i = i + w_len((char *)&s[i]);
	}
	return (nstr);
}
