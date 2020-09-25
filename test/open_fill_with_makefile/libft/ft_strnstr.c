/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:26 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:17:04 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	len_find;
	size_t	index;
	char	*buf;

	buf = (char *)src;
	len_find = ft_strlen(find);
	if (len_find == 0)
		return ((char *)src);
	index = 0;
	while (*buf)
	{
		if (index + len_find > len)
			return ((char*)NULL);
		if (ft_strncmp(buf, find, len_find) == 0)
			return (char *)(buf);
		buf++;
		index++;
	}
	return ((char *)NULL);
}
