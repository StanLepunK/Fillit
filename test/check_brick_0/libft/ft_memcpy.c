/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:09:37 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/29 08:28:30 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*buf_src;
	unsigned char	*buf_dst;

	if (!dst && !src && len > 0)
		return (NULL);
	if (len < 0)
		return ((void*)src);
	buf_src = (unsigned char *)src;
	buf_dst = (unsigned char *)dst;
	index = len;
	while (index > 0)
	{
		*buf_dst++ = *buf_src++;
		index--;
	}
	return (dst);
}
