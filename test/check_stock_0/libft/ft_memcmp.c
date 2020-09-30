/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:01:23 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 16:54:44 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char		*buf_s1;
	const unsigned char		*buf_s2;

	if (s1 == s2 || len == 0)
		return (0);
	buf_s1 = (const unsigned char *)s1;
	buf_s2 = (const unsigned char *)s2;
	while (len--)
	{
		if (*buf_s1 != *buf_s2)
			return (*buf_s1 - *buf_s2);
		if (len)
		{
			buf_s1++;
			buf_s2++;
		}
	}
	return (0);
}
