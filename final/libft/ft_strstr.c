/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:01:40 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/08 11:01:44 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *find)
{
	int index_src;
	int index_needle;
	int len;

	index_src = 0;
	index_needle = 0;
	len = 0;
	while (find[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)src);
	while (src[index_src])
	{
		while (find[index_needle] == src[index_src + index_needle])
		{
			if (index_needle == len - 1)
				return ((char *)src + index_src);
			index_needle++;
		}
		index_needle = 0;
		index_src++;
	}
	return (NULL);
}
