/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:43:36 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/07 15:44:36 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char*)src;
	tmp2 = (unsigned char*)dst;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		*tmp2++ = *tmp1++;
		n--;
	}
	return (dst);
}
