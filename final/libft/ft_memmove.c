/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:40:32 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/08 13:20:22 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (s1 < s2)
	{
		while (++i <= len)
			s2[len - i] = s1[len - i];
	}
	else
	{
		while (len-- > 0)
			*(s2++) = *(s1++);
	}
	return (dst);
}
