/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:28:15 by sgirard           #+#    #+#             */
/*   Updated: 2020/07/20 15:26:47 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_mots(const char *str, char c)
{
	int		mots;
	int		i;

	mots = 0;
	i = 0;
	if (str[0] != c)
		mots++;
	while (str[++i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			mots++;
	}
	return (mots);
}

int		ft_len_mots(char const *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

void	init(int *i, int *j)
{
	*i = -1;
	*j = 0;
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	int		nb;

	nb = ft_nbr_mots(s, c);
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	if (!s || !tab)
		return (NULL);
	init(&i, &j);
	while (++i < nb)
	{
		k = 0;
		tab[i] = ft_strnew(ft_len_mots(&s[j], c) + 1);
		if (!tab[i])
			tab[i] = NULL;
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
