/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:34:07 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:04:53 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	index;
	unsigned char	*buf_src;
	unsigned char	*buf_dst;

	if (!dst && !src && len > 0)
		return (NULL);
	buf_src = (unsigned char *)src;
	buf_dst = (unsigned char *)dst;
	index = 0;
	if (buf_src < buf_dst)
		while (len-- > 0)
			buf_dst[len] = buf_src[len];
	else
		while (index < len)
		{
			buf_dst[index] = buf_src[index];
			index++;
		}
	return ((buf_dst));
}
