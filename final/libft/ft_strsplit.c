/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:33:22 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/29 15:07:58 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		elem_count(char const *src, char c)
{
	int count;
	int index;
	int is;

	count = 0;
	index = 0;
	is = TRUE;
	while (src[index] != '\0')
	{
		if (!is && src[index] == c)
			is = TRUE;
		else if (src[index] != c)
		{
			if (is)
				count++;
			is = FALSE;
		}
		index++;
	}
	return (count);
}

static int		str_len(char const *src, unsigned int start, char c)
{
	int	count;

	if (src)
	{
		count = 0;
		while (src[start] != '\0' && src[start] != c)
		{
			start++;
			count++;
		}
		return (count);
	}
	else
		return (0);
}

static char		*str_from(char *elem, const char *src, int start, char c)
{
	int		index;

	if (src)
	{
		index = 0;
		while (src[start] != '\0' && src[start] != c)
		{
			elem[index] = src[start];
			start++;
			index++;
		}
		elem[index] = '\0';
		return (elem);
	}
	else
		return (NULL);
}

static void		free_tab(char **tabs, size_t index)
{
	while (index--)
		ft_strdel(&(tabs[index]));
	free(*tabs);
}

char			**ft_strsplit(char const *src, char c)
{
	char	**tab;
	int		ix;
	int		ix_tab;

	if (!src || !(tab = (char**)malloc(8 * (elem_count(src, c) + 1))))
		return (NULL);
	ix = 0;
	ix_tab = 0;
	while (src[ix] != '\0')
	{
		if (src[ix] != c)
		{
			if (!(tab[ix_tab] = (char*)malloc(8 * (str_len(src, ix, c) + 1))))
			{
				free_tab(tab, ix_tab);
				return (NULL);
			}
			ix += ft_strlen(str_from(tab[ix_tab++], (char*)src, ix, c));
		}
		else
			ix++;
	}
	tab[ix_tab] = NULL;
	return (tab);
}
