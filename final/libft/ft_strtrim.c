/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:58:55 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/24 19:30:24 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s)
{
	int len;
	int i;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_space(s[i]) == 1)
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
	}
	len = ft_strlen((char*)s);
	if (s[len] == '\0')
		len = (len - 1);
	while (ft_space(s[len]) == 1)
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
