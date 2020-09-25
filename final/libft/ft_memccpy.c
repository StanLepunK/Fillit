/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:48:25 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/08 13:14:33 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s2[i] == (unsigned char)c)
			return ((void *)&s2[i + 1]);
		i++;
	}
	return (NULL);
}
