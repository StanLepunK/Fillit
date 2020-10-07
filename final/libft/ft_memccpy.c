/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:38:46 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:00:07 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			index;
	unsigned char	*buf_src;
	unsigned char	*buf_dst;

	buf_dst = (unsigned char*)dst;
	buf_src = (unsigned char*)src;
	index = 0;
	while (index < len)
	{
		buf_dst[index] = buf_src[index];
		if (buf_dst[index] == (unsigned char)c)
			return ((void*)(dst + index + 1));
		index++;
	}
	return (NULL);
}
