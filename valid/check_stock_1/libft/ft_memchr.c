/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:51:31 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/14 08:51:35 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *src, int c, size_t len)
{
	size_t			index;
	unsigned char	*buf_src;

	buf_src = (unsigned char*)src;
	index = 0;
	while (index < len)
	{
		if (buf_src[index] == (unsigned char)c)
			return ((void*)(src + index));
		index++;
	}
	return (NULL);
}
